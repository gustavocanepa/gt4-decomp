/*
 * HSystemModule::Get (GT HD name): builds the script engine's System module and returns a handle
 * to it (inferred from the calls; names are guesses). It stores two lists in the module's statics
 * (D_00840AD0, from the program arguments; D_00840AD8 holding "."), the constants PLATFORM
 * ("playstation") and HOME (func_00316E18's path), and the functions exit, SetDebugLevel and
 * MemoryBlockDump, then applies func_00306638 with a func_00317C80 value.
 *
 * Every stack buffer is reused by hand for several objects (the module handle at 0x10, the list
 * at 0x20, the iterator and later PLATFORM's value at 0x30, ...), as retail's frame shows; the
 * handle reads go through get() before the arguments that follow are built.
 */
#include "types.h"

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct HeapName { const char *name; };
struct Str { char *p; char pad[0xC]; };
struct Slot { void *p; char pad[0xC]; };

extern Rep D_00659FA8;
extern char D_00840AE8[];
extern char D_0069E1E8[];   /* "." */
extern char D_0069E1F0[];   /* "playstation" */
extern char D_0069E200[];   /* "PLATFORM" */
extern char D_0069E210[];   /* "HOME" */
extern char D_0069E218[];   /* "exit" */
extern char D_0069E220[];   /* "SetDebugLevel" */
extern char D_0069E230[];   /* "MemoryBlockDump" */
extern char D_00840AD0[];
extern char D_00840AD8[];

extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n1, const char *src, s32 n2);
extern "C" HeapName *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

extern "C" void func_002ECDE0(Slot *args);
extern "C" void HModule__dynamicAssign(Slot *module, void *id);
extern "C" void func_002ECE20(Slot *list, void *args);
extern "C" void func_00306800(void *module, void *id, Slot *value);
extern "C" void func_002ED5C0(Slot *list, s32 flags);
extern "C" void func_002EFBF0(Slot *list);
extern "C" void func_00314B20(Slot *item, Str *s);
extern "C" void func_002EEEB0(Slot *it, void *list, Slot *item);
extern "C" void func_00309378(Slot *it, s32 flags);
extern "C" void func_00312318(Slot *item, s32 flags);
extern "C" void func_00316E18(Str *path);
extern "C" void func_00306938(void *module, Str *name, Slot *value);
extern "C" void func_003068A8(void *module, Str *name, void (*fn)(void));
extern "C" void func_00317C80(Slot *x);
extern "C" void func_00306638(Slot *ret, void *module, Slot *x);
extern "C" void func_00323B60(Slot *s, s32 flags);
extern "C" void func_003041B8(Slot *h, s32 flags);
extern "C" void func_003041A0(Slot *ret, Slot *src);
extern "C" void func_002EA590(Slot *args, s32 flags);
extern "C" void adhoc__exit(void);
extern "C" void func_00316E08(void);
extern "C" void adhoc__MemoryBlockDump(void);

static inline void *get(Slot *h) { return h->p; }

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }

static inline char *grab(Rep *r) {
    if (r->sel)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

static inline void construct(Str *s, const char *text) {
    s->p = grab(&D_00659FA8);
    func_005C2630(s, 0, -1, text, func_0057F260(text));
}

static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" Slot *HSystemModule__Get(Slot *ret) {
    Slot args;
    Slot module;
    Slot list;
    Slot platform;  /* insert result, then PLATFORM's value */
    Slot item;
    Str text;
    Slot home;      /* "playstation" string, then HOME's value */
    Str name;       /* member names; HOME's path; func_00306638's result */
    Slot x;

    func_002ECDE0(&args);
    HModule__dynamicAssign(&module, D_00840AE8);
    {
        void *m = get(&module);
        func_002ECE20(&list, args.p);
        func_00306800(m, D_00840AD0, &list);
    }
    func_002ED5C0(&list, 2);

    func_002EFBF0(&list);
    {
        Slot *it = &platform;
        void *l = get(&list);
        construct(&text, D_0069E1E8);
        func_00314B20(&item, &text);
        func_002EEEB0(it, l, &item);
        func_00309378(it, 2);
        func_00312318(&item, 2);
        release(&text);
    }
    func_00306800(get(&module), D_00840AD8, &list);

    construct((Str *)&home, D_0069E1F0);
    func_00314B20(&platform, (Str *)&home);
    release((Str *)&home);
    func_00316E18(&name);
    func_00314B20(&home, &name);
    release(&name);

    { void *m = get(&module); construct(&name, D_0069E200); func_00306938(m, &name, &platform); release(&name); }
    { void *m = get(&module); construct(&name, D_0069E210); func_00306938(m, &name, &home); release(&name); }
    { void *m = get(&module); construct(&name, D_0069E218); func_003068A8(m, &name, adhoc__exit); release(&name); }
    { void *m = get(&module); construct(&name, D_0069E220); func_003068A8(m, &name, func_00316E08); release(&name); }
    { void *m = get(&module); construct(&name, D_0069E230); func_003068A8(m, &name, adhoc__MemoryBlockDump); release(&name); }

    {
        void *m = get(&module);
        func_00317C80(&x);
        func_00306638((Slot *)&name, m, &x);
        func_00323B60((Slot *)&name, 2);
        func_003041B8(&x, 2);
    }

    func_003041A0(ret, &module);
    func_00312318(&home, 2);
    func_00312318(&platform, 2);
    func_002ED5C0(&list, 2);
    func_003041B8(&module, 2);
    func_002EA590(&args, 2);
    return ret;
}
