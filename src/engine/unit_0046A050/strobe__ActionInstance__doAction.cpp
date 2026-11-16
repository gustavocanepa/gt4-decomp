/* compiler: ee-gcc2.96-no-strict-aliasing */
/*
 * strobe::ActionInstance::doAction (GT HD name; behaviour inferred): the bytecode interpreter of
 * the game's Flash-style UI player. It runs `len` bytes of SWF actions from `pc` on the value stack
 * of the animation instance (+0x164) and returns the value of a Return action (0x3E), or
 * undefined at an End action (0x00) or the end of the code. Locals: the four action registers and
 * a stack of up to eight With blocks (object plus end address).
 *
 * Actions below 0x80 have no payload (play/stop/frame control, arithmetic and comparisons, string
 * and type conversion, variables, members, function and method calls, object creation); from 0x80
 * on a 16-bit length follows (GotoFrame, ConstantPool, Push, StoreRegister, DefineFunction, If,
 * Jump, With). Unknown actions are only reported through the debug printf.
 *
 * Source forms that decide the code (see knowledge/attempts.jsonl, 00481880):
 * - String has the library's copy constructor: it makes the class BLKmode, so its temporaries get
 *   16-byte stack slots like retail's; its constructor nests Rep::grab / assign / replace as
 *   bastring.h does.
 * - Any's copy constructor and operator= are out-of-line members (func_00476768, func_00476790):
 *   their arguments are then evaluated last-first, as in retail.
 * - Calls whose result is only pushed or passed on are written as one expression with
 *   temporaries bound to reference parameters (result slot first, then the argument slots).
 * - Type tests are inline bool predicates (xori compares); the With lookup of CallFunction is an
 *   inline function returning Any (copy into the caller's variable).
 * - Trace (0x26) is a case of its own (trace, pop): falling through into Pop changes the order of
 *   its printf arguments.
 */
#include "types.h"

/* ---- the script value (strobe::Any) ---- */
struct Any;
extern "C" void func_00476768(Any *self, const Any *src);
extern "C" Any *func_00476790(Any *self, const Any *src);
extern "C" void func_004768C0(Any *self);
extern "C" void func_004769E0(Any *self);
extern "C" void func_00476A08(Any *self);
extern "C" void func_00476A38(Any *self);
extern "C" void func_00476AE8(Any *self, const char *s);
extern "C" void func_00476B30(Any *self, s32 b);
extern "C" void func_00476B78(Any *self, f32 n);
extern "C" void func_00476BC0(Any *self, s32 i);
extern "C" void func_00476BE8(Any *self, const u8 *body, s32 size, s32 nargs, const u8 *args, void *frame, void *pool);
extern "C" const char *strobe__Any__toString(Any *self); /* toString */
extern "C" f32 func_00477460(Any *self); /* toNumber */
extern "C" s32 func_004774A8(Any *self); /* toBoolean */
extern "C" const char *strobe__Any__typeOf(Any *self);
extern "C" void func_004787B8(Any *self, s32 radix);

struct Any {
    s32 type;
    union {
        s32 i;
        f32 n;
        void *p;
    } u;
    Any() : type(1) {}
    Any(f32 n) : type(6) { u.n = n; }
    Any(const Any &o) __asm__("func_00476768");
    ~Any() { func_004768C0(this); }
    Any &operator=(const Any &o) __asm__("func_00476790");
    bool isUndefined() const { return type == 1; }
    bool isNotFound() const { return type == 2; }
    bool isObject() const { return type == 7; }
    bool isFunction() const { return type == 13; }
    bool isPrimitive() const { return (u32)(type - 3) < 2; }
};

/* ---- the string (libstdc++ v2 basic_string, second instantiation) ---- */
struct Rep;
extern "C" char *strobe__toUpper(Rep *rep);
struct Rep {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    char *clone() { return strobe__toUpper(this); }
    char *grab() {
        if (selfish)
            return clone();
        ++ref;
        return data();
    }
};
extern Rep D_00659E20;
extern char D_006ADF70[];
struct String;
extern "C" String *strobe__Any__setMember(String *s, u32 pos, u32 n1, const char *src, u32 n2);
extern "C" u32 func_0057F260(const char *s);
extern "C" void func_00575DA0(Rep *rep);
extern "C" void func_00480FE8(String *s); /* upper-cases the name */

struct String {
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    String(const String &o) : dat(o.rep()->grab()) {}
    String(const char *s) : dat(D_00659E20.grab()) { assign(s); }
    ~String() {
        Rep *r = rep();
        if (--r->ref == 0)
            func_00575DA0(r);
    }
    String &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *strobe__Any__setMember(this, pos, n1, s, n2); }
    String &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String &assign(const char *s) { return assign(s, func_0057F260(s)); }
    u32 length() const { return rep()->len; }
    const char *c_str() {
        if (length() == 0)
            return D_006ADF70;
        dat[length()] = 0;
        return dat;
    }
};

/* ---- interpreter state ---- */
struct ValStack {
    Any *start;
    Any *pad;
    Any *finish;
    Any *top() { return finish - 1; }
};
extern "C" void func_00480F20(ValStack *stack, const Any &v); /* push */
extern "C" void func_00480F78(ValStack *stack); /* pop */
extern "C" void func_00480FA0(ValStack *stack, s32 n); /* pop n */

struct String;
extern "C" s32 func_00477738(Any *obj, String *name, Any *value, s32 create); /* obj.name = value */
struct WithEntry {
    Any obj;
    const u8 *end;
};
struct WithStack;
extern "C" s32 func_00609DF8(WithStack *ws, const u8 *pc);
struct WithStack {
    WithEntry e[8];
    s32 depth;
    WithStack() : depth(-1) {}
    WithStack *active() { return depth < 0 ? 0 : this; }
    s32 setVariable(String &name, Any &v) {
        for (s32 i = depth; i >= 0; i--)
            if (func_00477738(&e[i].obj, &name, &v, 0))
                return 1;
        return 0;
    }
    s32 check(const u8 *pc) {
        s32 i = depth;
        if (i < 0)
            return 0;
        if (!(pc < e[i].end)) {
            depth = i - 1;
            return func_00609DF8(this, pc);
        }
        return 1;
    }
};

extern "C" s32 func_00481698(const u8 **p) throw(); /* reads a 16-bit value and advances */
extern "C" s32 func_004816C0(const u8 **p); /* reads a 32-bit value and advances */
extern "C" void func_0057D9C0(const char *fmt, ...); /* debug printf */
extern "C" f32 func_00475DA8(char *anim);
extern "C" void *func_00475D98(char *anim);
extern "C" Any func_00484308(void *self); /* the instance's target movie clip */
extern "C" Any func_00477C40(const Any &obj, const String &name, void *self, s32 nargs, void *pool, char *anim); /* calls obj.name(nargs arguments from the stack) */
extern "C" Any func_00477890(Any *fn, void *self, s32 nargs, void *pool, char *anim);
extern "C" Any func_00476698(String *name, char *anim);
extern "C" Any func_00481190(void *cb, String *name, s32 nargs, ValStack *stack);
extern "C" Any func_004774F8(const Any &obj, const String &name); /* obj.name */
extern "C" Any func_00484530(void *self, String *name, void *frame, WithStack *ws, char *anim);
extern "C" void func_00476D40(Any *result, Any *source, void *self, s32 nargs, void *pool, char *anim);
extern "C" s32 func_00477738(Any *obj, String *name, Any *value, s32 create);
extern "C" Any *func_00481230(void *frame, String *name); /* variable slot or 0 */
extern "C" s32 func_00481280(void *frame, String *name);
extern "C" Any *func_00481410(void *frame, String *name); /* variable slot, created when missing */
extern "C" s32 func_004809D8(void *vars, String *name, Any *value);
extern "C" void func_00484748(void *self, const char *path, void *frame, WithStack *ws, char *anim, const char **var, Any *target);
extern "C" void func_00485368(void *pool, const u8 *data);
extern "C" const char *func_00485498(void *pool, s32 index);
extern "C" void *func_00477298(s32 v);
extern "C" void func_00477D98(Any *v, ValStack *stack);
extern "C" void func_00477DE0(Any *a, Any *b);
extern "C" s32 func_00477F28(Any *a, Any *b);
extern "C" s32 func_00478000(Any *a, Any *b);
extern "C" s32 func_004780F8(Any *a, Any *b);
extern "C" s32 func_00478178(Any *a, Any *b);
extern "C" s32 func_00478250(Any *a, Any *b);
extern "C" void func_00478280(Any *a, Any *b);
extern "C" void func_004782D0(Any *a, Any *b);
extern "C" void func_00478320(Any *a, Any *b);
extern "C" void func_00478378(Any *a, Any *b);
extern "C" void func_00478400(Any *a);
extern "C" void func_00478480(Any *a, Any *b);
extern "C" void func_004784E0(Any *a, Any *b);
extern "C" void func_00478540(Any *a, Any *b);
extern "C" void func_004785A0(Any *a, Any *b);
extern "C" void func_00478600(Any *a, Any *b);
extern "C" void func_00478660(Any *a, Any *b);
extern "C" void func_004786C0(Any *a, Any *b);
extern "C" void func_00478748(Any *a);
extern "C" void func_00478780(Any *a);

extern char D_006ADF38[], D_006ADF40[], D_006ADF48[], D_006ADF58[], D_006ADF68[];
extern char D_006ADF78[], D_006ADF88[], D_006ADFB8[], D_006ADFC8[], D_006AE000[];
extern char D_006AE038[], D_006AE040[], D_006AE050[], D_006AE070[], D_006AE080[];
extern const char *D_00624838[];


static inline Any findInWith(WithStack &ws, const String &name, void *self, u32 nargs, void *pool, char *anim) {
    Any fn;
    for (s32 i = ws.depth; i >= 0; i--) {
        fn = func_00477C40(ws.e[i].obj, name, self, nargs, pool, anim);
        if (!fn.isNotFound())
            return fn;
    }
    func_00476A08(&fn);
    return fn;
}

struct Action {
    char pad[0x14];
    void *vars;
};

extern "C" Any strobe__ActionInstance__doAction(Action *self, const u8 *pc, s32 len, void *pool, void *frame, char *anim) {
    Any regs[4];
    WithStack withs;
    ValStack *stack = *(ValStack **)(anim + 0x164);
    const u8 *end = pc + len;

    while (pc < end) {
        u8 op = *pc++;
        if (op == 0)
            return Any();
        if ((s8)op >= 0) {
            switch (op) {
            case 0x06: {
                func_00477C40(func_00484308(self), String(D_006ADF38), self, 0, pool, anim);
                break;
            }
            case 0x07: {
                func_00477C40(func_00484308(self), String(D_006ADF40), self, 0, pool, anim);
                break;
            }
            case 0x04: {
                func_00477C40(func_00484308(self), String(D_006ADF48), self, 0, pool, anim);
                break;
            }
            case 0x05: {
                func_00477C40(func_00484308(self), String(D_006ADF58), self, 0, pool, anim);
                break;
            }
            case 0x34:
                func_00480F20(stack, Any((f32)(s32)(func_00475DA8(anim) * 1000.0f)));
                break;
            case 0x26:
                func_0057D9C0(D_006ADF68, strobe__Any__toString(stack->top()));
                func_00480F78(stack);
                break;
            case 0x17:
                func_00480F78(stack);
                break;
            case 0x0A:
            case 0x47: {
                Any b(*stack->top());
                func_00480F78(stack);
                func_00477DE0(stack->top(), &b);
                break;
            }
            case 0x0B: {
                Any b(*stack->top());
                func_00480F78(stack);
                func_00478280(stack->top(), &b);
                break;
            }
            case 0x0C: {
                Any b(*stack->top());
                func_00480F78(stack);
                func_004782D0(stack->top(), &b);
                break;
            }
            case 0x0D: {
                Any b(*stack->top());
                func_00480F78(stack);
                func_00478320(stack->top(), &b);
                break;
            }
            case 0x48: {
                Any b(*stack->top());
                func_00480F78(stack);
                Any *a = stack->top();
                func_00476B30(a, func_00477F28(a, &b));
                break;
            }
            case 0x0E:
            case 0x49: {
                Any b(*stack->top());
                func_00480F78(stack);
                Any *a = stack->top();
                func_00476B30(a, func_00478178(a, &b));
                break;
            }
            case 0x13: {
                Any b(*stack->top());
                strobe__Any__toString(&b);
                func_00480F78(stack);
                strobe__Any__toString(stack->top());
                Any *a = stack->top();
                func_00476B30(a, func_00478178(a, &b));
                break;
            }
            case 0x66: {
                Any b(*stack->top());
                func_00480F78(stack);
                Any *a = stack->top();
                func_00476B30(a, func_00478250(a, &b));
                break;
            }
            case 0x67: {
                Any b(*stack->top());
                func_00480F78(stack);
                Any *a = stack->top();
                func_00476B30(a, func_00478000(a, &b));
                break;
            }
            case 0x68: {
                Any b(*stack->top());
                func_00480F78(stack);
                Any *a = stack->top();
                func_00476B30(a, func_004780F8(a, &b));
                break;
            }
            case 0x3F: {
                Any b(*stack->top());
                func_00480F78(stack);
                func_00478378(stack->top(), &b);
                break;
            }
            case 0x60: {
                Any b(*stack->top());
                func_00480F78(stack);
                func_00478480(stack->top(), &b);
                break;
            }
            case 0x10: {
                Any b(*stack->top());
                func_00480F78(stack);
                func_004784E0(stack->top(), &b);
                break;
            }
            case 0x61: {
                Any b(*stack->top());
                func_00480F78(stack);
                func_00478540(stack->top(), &b);
                break;
            }
            case 0x12:
                func_00478400(stack->top());
                break;
            case 0x63: {
                Any b(*stack->top());
                func_00480F78(stack);
                func_00478600(stack->top(), &b);
                break;
            }
            case 0x64: {
                Any b(*stack->top());
                func_00480F78(stack);
                func_00478660(stack->top(), &b);
                break;
            }
            case 0x65: {
                Any b(*stack->top());
                func_00480F78(stack);
                func_004786C0(stack->top(), &b);
                break;
            }
            case 0x62: {
                Any b(*stack->top());
                func_00480F78(stack);
                func_004785A0(stack->top(), &b);
                break;
            }
            case 0x51:
                func_00478780(stack->top());
                break;
            case 0x50:
                func_00478748(stack->top());
                break;
            case 0x4C:
                func_00480F20(stack, *stack->top());
                break;
            case 0x4D: {
                Any a(*stack->top());
                func_00480F78(stack);
                Any b(*stack->top());
                func_00480F78(stack);
                func_00480F20(stack, a);
                func_00480F20(stack, b);
                break;
            }
            case 0x3D: {
                String name(strobe__Any__toString(stack->top()));
                func_00480FE8(&name);
                func_00480F78(stack);
                u32 nargs = (u32)func_00477460(stack->top());
                func_00480F78(stack);
                if (withs.check(pc - 1)) {
                    Any r = findInWith(withs, name, self, nargs, pool, anim);
                    if (!r.isNotFound()) {
                        func_00480F20(stack, r);
                        break;
                    }
                }
                {
                    Any *f = func_00481230(frame, &name);
                    if (f != 0 && f->isFunction()) {
                        Any r = func_00477890(f, self, nargs, pool, anim);
                        func_00480F20(stack, r);
                        break;
                    }
                }
                {
                    Any fn;
                    fn = func_00477C40(func_00484308(self), name, self, nargs, pool, anim);
                    if (!fn.isNotFound()) {
                        func_00480F20(stack, fn);
                        break;
                    }
                    fn = func_00476698(&name, anim);
                    if (fn.isUndefined()) {
                        Any r = func_00481190(func_00475D98(anim), &name, nargs, stack);
                        func_00480F20(stack, r);
                    } else {
                        Any r = func_00477890(&fn, self, nargs, pool, anim);
                        func_00480F20(stack, r);
                    }
                }
                break;
            }
            case 0x3E: {
                Any v(*stack->top());
                func_00480F78(stack);
                return v;
            }
            case 0x52: {
                String name(strobe__Any__toString(stack->top()));
                func_00480FE8(&name);
                func_00480F78(stack);
                Any obj(*stack->top());
                func_00480F78(stack);
                u32 nargs = (u32)func_00477460(stack->top());
                func_00480F78(stack);
                Any r = func_00477C40(obj, name, self, nargs, pool, anim);
                func_00480F20(stack, r);
                break;
            }
            case 0x40: {
                String name(strobe__Any__toString(stack->top()));
                func_0057D9C0(D_006ADF78, name.c_str());
                func_00480FE8(&name);
                func_00480F78(stack);
                u32 nargs = (u32)func_00477460(stack->top());
                func_00480F78(stack);
                Any ctor = func_00484530(self, &name, frame, &withs, anim);
                if (!ctor.isUndefined()) {
                    Any r;
                    func_00476D40(&r, &ctor, self, nargs, pool, anim);
                    func_00480F20(stack, r);
                } else {
                    func_0057D9C0(D_006ADF88, name.c_str());
                    func_00480FA0(stack, nargs);
                    Any r;
                    func_00480F20(stack, r);
                }
                break;
            }
            case 0x53: {
                String name(strobe__Any__toString(stack->top()));
                func_0057D9C0(D_006ADFB8, name.c_str());
                func_00480FE8(&name);
                func_00480F78(stack);
                Any obj(*stack->top());
                func_00480F78(stack);
                u32 nargs = (u32)func_00477460(stack->top());
                func_00480F78(stack);
                Any ctor = func_004774F8(obj, name);
                if (!ctor.isUndefined()) {
                    Any r;
                    func_00476D40(&r, &ctor, self, nargs, pool, anim);
                    func_00480F20(stack, r);
                } else {
                    func_0057D9C0(D_006ADF88, name.c_str());
                    func_00480FA0(stack, nargs);
                    Any r;
                    func_00480F20(stack, r);
                }
                break;
            }
            case 0x42: {
                s32 n = (s32)func_00477460(stack->top());
                func_00480F78(stack);
                Any array;
                func_00476A38(&array);
                Any r;
                func_00476D40(&r, &array, self, n, pool, anim);
                func_00480F20(stack, r);
                break;
            }
            case 0x43: {
                s32 n = (s32)func_00477460(stack->top());
                func_00480F78(stack);
                Any proto;
                Any obj;
                func_00476D40(&obj, &proto, self, 0, pool, anim);
                for (s32 i = 0; i < n; i++) {
                    Any v(*stack->top());
                    func_00480F78(stack);
                    String name(strobe__Any__toString(stack->top()));
                    func_00480FE8(&name);
                    func_00480F78(stack);
                    func_00477738(&obj, &name, &v, 1);
                }
                func_00480F20(stack, obj);
                break;
            }
            case 0x3C: {
                Any v(*stack->top());
                func_00480F78(stack);
                String name(strobe__Any__toString(stack->top()));
                func_00480FE8(&name);
                func_00480F78(stack);
                *func_00481410(frame, &name) = v;
                break;
            }
            case 0x41: {
                String name(strobe__Any__toString(stack->top()));
                func_00480FE8(&name);
                func_00481410(frame, &name);
                func_00480F78(stack);
                break;
            }
            case 0x1C: {
                withs.check(pc - 1);
                const char *var;
                Any target;
                func_00484748(self, strobe__Any__toString(stack->top()), frame, &withs, anim, &var, &target);
                func_00480F78(stack);
                String name(var);
                func_00480FE8(&name);
                if (target.isUndefined()) {
                    Any r = func_00484530(self, &name, frame, &withs, anim);
                    func_00480F20(stack, r);
                } else {
                    Any r = func_004774F8(target, name);
                    func_00480F20(stack, r);
                }
                break;
            }
            case 0x1D: {
                Any v(*stack->top());
                func_00480F78(stack);
                withs.check(pc - 1);
                const char *var;
                Any target;
                func_00484748(self, strobe__Any__toString(stack->top()), frame, &withs, anim, &var, &target);
                func_00480F78(stack);
                String name(var);
                func_00480FE8(&name);
                if (target.isUndefined()) {
                    if (withs.active() && withs.setVariable(name, v))
                        break;
                    Any *slot = func_00481230(frame, &name);
                    if (slot != 0)
                        *slot = v;
                    else if (func_004809D8(self->vars, &name, &v) == 0)
                        *func_00481410(self, &name) = v;
                } else {
                    func_00477738(&target, &name, &v, 1);
                }
                break;
            }
            case 0x4E: {
                String name(strobe__Any__toString(stack->top()));
                func_00480FE8(&name);
                func_00480F78(stack);
                Any obj(*stack->top());
                func_00480F78(stack);
                Any r = func_004774F8(obj, name);
                func_00480F20(stack, r);
                break;
            }
            case 0x4F: {
                Any v(*stack->top());
                func_00480F78(stack);
                String name(strobe__Any__toString(stack->top()));
                func_00480FE8(&name);
                func_00480F78(stack);
                Any obj(*stack->top());
                func_00480F78(stack);
                func_00477738(&obj, &name, &v, 1);
                break;
            }
            case 0x22: {
                s32 index = (s32)func_00477460(stack->top());
                func_00480F78(stack);
                Any path(*stack->top());
                func_00480F78(stack);
                Any target;
                const char *s = strobe__Any__toString(&path);
                if (*s == 0)
                    target = func_00484308(self);
                else
                    func_0057D9C0(D_006ADFC8, s);
                if ((u32)index < 22)
                    func_00480F20(stack, func_004774F8(target, String(D_00624838[index])));
                else
                    func_00480F20(stack, Any());
                break;
            }
            case 0x23: {
                Any v(*stack->top());
                func_00480F78(stack);
                s32 index = (s32)func_00477460(stack->top());
                func_00480F78(stack);
                Any path(*stack->top());
                func_00480F78(stack);
                Any target;
                const char *s = strobe__Any__toString(&path);
                if (*s == 0)
                    target = func_00484308(self);
                else
                    func_0057D9C0(D_006AE000, s);
                if ((u32)index < 22) {
                    String name(D_00624838[index]);
                    func_00477738(&target, &name, &v, 0);
                }
                break;
            }
            case 0x4A: {
                Any v(*stack->top());
                func_00480F78(stack);
                if (v.isObject()) {
                    Any r = func_00477C40(v, String(D_006AE038), self, 0, pool, anim);
                    Any n(func_00477460(&r));
                    func_00480F20(stack, n);
                } else {
                    func_004787B8(&v, 10);
                    func_00480F20(stack, v);
                }
                break;
            }
            case 0x4B: {
                Any v(*stack->top());
                func_00480F78(stack);
                if (v.isObject()) {
                    Any r = func_00477C40(v, String(D_006AE040), self, 0, pool, anim);
                    if (r.isPrimitive()) {
                        func_00480F20(stack, r);
                        break;
                    }
                }
                strobe__Any__toString(&v);
                func_00480F20(stack, v);
                break;
            }
            case 0x18: {
                Any v(*stack->top());
                func_00480F78(stack);
                func_004787B8(&v, 10);
                func_00476B78(&v, (f32)(s32)func_00477460(&v));
                func_00480F20(stack, v);
                break;
            }
            case 0x44: {
                Any *v = stack->top();
                func_00476AE8(v, strobe__Any__typeOf(v));
                break;
            }
            case 0x55: {
                Any obj(*stack->top());
                func_00480F78(stack);
                Any null;
                func_004769E0(&null);
                func_00480F20(stack, null);
                func_00477D98(&obj, stack);
                break;
            }
            default:
                func_0057D9C0(D_006AE050, op);
                break;
            }
        } else {
            s32 size = func_00481698(&pc);
            const u8 *p = pc;
            pc += size;
            switch (op) {
            case 0x81: {
                Any frameNo((f32)(func_00481698(&p) + 1));
                func_00480F20(stack, frameNo);
                func_00477C40(func_00484308(self), String(D_006AE070), self, 1, pool, anim);
                break;
            }
            case 0x88:
                func_00485368(pool, p);
                break;
            case 0x96:
                while (p < pc) {
                    u8 type = *p++;
                    Any v;
                    switch (type) {
                    case 0:
                        func_00476AE8(&v, (const char *)p);
                        while (*p++ != 0)
                            ;
                        break;
                    case 1: {
                        s32 bits = func_004816C0(&p);
                        func_00476B78(&v, *(f32 *)&bits);
                        break;
                    }
                    case 2:
                        func_004769E0(&v);
                        break;
                    case 3:
                        func_004768C0(&v);
                        break;
                    case 4:
                        v = regs[*p++];
                        break;
                    case 5:
                        func_00476B30(&v, *p++ != 0);
                        break;
                    case 6: {
                        u8 b[4];
                        s32 c;
                        c = *p++;
                        b[0] = c << 3;
                        b[1] = c >> 5;
                        c = *p++;
                        b[1] |= c << 3;
                        b[2] = c >> 5;
                        c = *p++;
                        b[2] |= (c & 0x1F) << 3;
                        b[3] = c >> 5;
                        c = *p++;
                        b[3] |= (c & 0xC0) | ((c & 7) << 3);
                        p += 3;
                        c = *p++;
                        b[0] |= c >> 5;
                        func_00476B78(&v, *(f32 *)b);
                        break;
                    }
                    case 7:
                        func_00476BC0(&v, func_004816C0(&p));
                        break;
                    case 8:
                        func_00476AE8(&v, func_00485498(pool, *p++));
                        break;
                    case 9:
                        func_00476AE8(&v, func_00485498(pool, func_00481698(&p)));
                        break;
                    }
                    func_00480F20(stack, v);
                }
                break;
            case 0x87: {
                Any &reg = regs[*p++];
                reg = *stack->top();
                break;
            }
            case 0x9B: {
                s32 anonymous = *p == 0;
                String name((const char *)p);
                func_00480FE8(&name);
                s32 existing = 0;
                if (!anonymous)
                    existing = func_00481280(frame, &name);
                if (existing == 0) {
                    while (*p++ != 0)
                        ;
                    Any fn;
                    u32 nargs = func_00481698(&p);
                    const u8 *args = p;
                    u32 i;
                    for (i = 0; i < nargs; i++)
                        while (*p++ != 0)
                            ;
                    s32 bodySize = func_00481698(&p);
                    func_00476BE8(&fn, pc, bodySize, nargs, args, frame, pool);
                    if (anonymous)
                        func_00480F20(stack, fn);
                    else
                        *func_00481410(frame, &name) = fn;
                    pc += bodySize;
                } else {
                    pc += *(u16 *)((char *)func_00477298(existing) + 8);
                }
                break;
            }
            case 0x9D: {
                s32 cond = func_004774A8(stack->top());
                func_00480F78(stack);
                if (!cond)
                    break;
            }
            case 0x99:
                pc += (s16)func_00481698(&p);
                break;
            case 0x94: {
                withs.check(pc);
                Any *obj = stack->top();
                const u8 *blockEnd = pc + func_00481698(&p);
                if (withs.depth < 7) {
                    withs.depth++;
                    withs.e[withs.depth].obj = *obj;
                    withs.e[withs.depth].end = blockEnd;
                }
                func_00480F78(stack);
                break;
            }
            default:
                func_0057D9C0(D_006AE080, op, size);
                break;
            }
        }
    }
    return Any();
}
