/* mButton virtual 77: if the script handler at this+0xB0 is set, builds a 2-element argument list (arg1 via func_00309348, arg2 via func_002BF4B8), invokes the handler (vtable slot 0xA8) into a result value, destroys the arguments and the result; returns 1 */
typedef int s32;

struct VObj { char pad0[4]; char *vtbl; };
struct VEntryCall { short delta; short index; void (*fn)(void *, s32 *, s32, void *); };
struct Obj { char pad0[0xB0]; VObj *handler; };

extern "C" void func_0030BB18(void *h);
extern "C" void func_00309348(void *h, s32 *val);
extern "C" void func_00309378(void *h, int flags);
extern "C" void func_002BF4B8(void *h, s32 *val);
extern "C" void func_002BF4E8(void *h, int flags);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

struct Value {
    s32 p;
    Value() { func_0030BB18(this); }
};

static inline void vcall20(VObj *o, s32 *ret, s32 n, void *args) {
    VEntryCall *e = (VEntryCall *)(o->vtbl + 0xA8);
    e->fn((char *)o + e->delta, ret, n, args);
}

extern "C" s32 mButton__virtual_77(Obj *self, s32 arg1, s32 arg2) {
    s32 newVal;
    s32 oldVal;
    VObj **ph = &self->handler;
    if (*ph != 0) {
        s32 ret[4];

        func_0030BB18(ret);
        {
            Value args[2];
            s32 tmp[4];
            s32 v1;
            s32 v2;
            s32 *p0;
            Value *dst;

            p0 = tmp;
            dst = args;
            v1 = arg1;
            func_00309348(p0, &v1);
            if (dst != (Value *)p0) {
                newVal = *p0;
                if (newVal != 0) {
                    func_003285A8(newVal);
                }
                oldVal = dst->p;
                if (oldVal != 0) {
                    func_003285F8(oldVal);
                }
                dst->p = newVal;
            }
            func_00309378(p0, 2);

            dst = &args[1];
            v2 = arg2;
            func_002BF4B8(p0, &v2);
            if (dst != (Value *)p0) {
                newVal = *p0;
                if (newVal != 0) {
                    func_003285A8(newVal);
                }
                oldVal = dst->p;
                if (oldVal != 0) {
                    func_003285F8(oldVal);
                }
                dst->p = newVal;
            }
            func_002BF4E8(p0, 2);

            vcall20(*ph, ret, 2, args);
            {
                Value *q = args + 2;
                while (args != q) {
                    --q;
                    func_00309378(q, 2);
                }
            }
            func_00309378(ret, 2);
        }
    }
    return 1;
}
