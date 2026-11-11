/* compiler: ee-gcc2.96-stl */
/* Inferred from its callers (MOption__clearButtonFunction and the other button/analog config
 * methods): resolves the config list a script call names. The first argument is an index, the
 * second a name; the name's C string is taken (and the temporary string released), the option
 * object is reached through the handle func_0017FB28 builds, and its table at +0x11D0 yields the
 * group for the index (virtual slot 0x40), which yields the list for the name (slot 0x20). */
typedef int s32;
typedef short s16;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; char pad[0xC]; };
struct VEntry { s16 delta; s16 index; void *fn; };
struct VObj { char pad[4]; char *vtbl; };
struct Arg { VObj *v[3]; };
struct List { char pad[0xC]; char *vtbl; };
struct Table { char *vtbl; };  /* vptr at offset 0 */
struct Owner { char pad[0x11D0]; Table table; };
struct Inner { char pad[0x10]; Owner *owner; };
struct Handle { Inner *p; s32 pad[3]; };

extern char D_00692090[];
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_0017FB28(Handle *, s32);
extern "C" void func_0017FAD0(Handle *, s32) throw();

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *str_c_str(Str *s) {
    if (str_length(s) == 0) return D_00692090;
    str_terminate(s);
    return rep_data(str_rep(s));
}
static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}
static inline s32 to_int(VObj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x58);
    return ((s32 (*)(void *))e->fn)((char *)o + e->delta);
}
static inline void to_string(Str *ret, VObj *o) {
    VEntry *e = (VEntry *)(o->vtbl + 0x18);
    ((void (*)(Str *, void *))e->fn)(ret, (char *)o + e->delta);
}

extern "C" List *func_001908C0(s32 self, Arg *args) {
    s32 index = to_int(args->v[0]);
    const char *c;
    {
        Str name;
        to_string(&name, args->v[1]);
        c = str_c_str(&name);
        str_release(&name);
    }
    Handle h;
    func_0017FB28(&h, self);
    Table *table = &h.p->owner->table;
    func_0017FAD0(&h, 2);
    VEntry *e = (VEntry *)(table->vtbl + 0x40);
    Table *group = ((Table *(*)(void *, s32))e->fn)((char *)table + e->delta, index);
    VEntry *f = (VEntry *)(group->vtbl + 0x20);
    return ((List *(*)(void *, const char *))f->fn)((char *)group + f->delta, c);
}
