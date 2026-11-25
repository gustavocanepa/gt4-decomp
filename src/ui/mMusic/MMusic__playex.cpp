/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; s32 pad[3]; };
struct Handle { s32 id; s32 pad[3]; };
struct TypeInfo { const char *name; };
struct Obj { char pad0[4]; char *vtbl; };
struct VEntry { s16 delta; s16 index; void (*fn)(); };

extern char D_0069C550[];

extern "C" TypeInfo *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_002C2878(void *arg0, int arg1);
extern "C" void func_002C28D0(void *arg0, void *arg1);
extern "C" void func_002C3CF8(s32 handle, const char *name, s32 number, s32 loop, f32 volume);

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_0069C550;
    str_terminate(s);
    return rep_data(str_rep(s));
}
static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline f32 getFloat(Obj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x60);
    return ((f32 (*)(void *))e->fn)((char *)o + e->delta);
}
static inline s32 getInt(Obj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x58);
    return ((s32 (*)(void *))e->fn)((char *)o + e->delta);
}
static inline void getString(Str *out, Obj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x18);
    ((void (*)(Str *, void *))e->fn)(out, (char *)o + e->delta);
}

extern "C" void MMusic__playex(void *self, void *owner, s32 n, Obj **args) {
    union { Str s; Handle h; } u;
    s32 number = -1;
    s32 loop = 0;
    f32 volume = 1.0f;
    const char *name;
    const char *title = 0;

    switch (n) {
    case 4:
        volume = getFloat(args[3]);
    case 3:
        loop = getInt(args[2]) != 0;
    case 2:
        number = getInt(args[1]);
    case 1:
        break;
    default:
        return;
    }
    getString(&u.s, args[0]);
    name = c_str(&u.s);
    release(&u.s);
    /* The name goes through a second variable copied before the handle is
       built: the copy cannot be combined across that call, sched1 sinks it
       below the call, and the a2 copy becomes the first insn the call
       releases (retail: a2, a0, a1, a3). */
    title = name;
    func_002C28D0(&u.h, owner);
    func_002C3CF8(u.h.id, title, number, loop, volume);
    func_002C2878(&u.h, 2);
}
