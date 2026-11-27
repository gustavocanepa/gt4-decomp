/* Default project compiler (ee-gcc 2.96 -O2 -G0 -fno-exceptions): no compiler marker. */
#include "types.h"

struct Handle {
    void *p;
    char pad[0xC];
};

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; char pad[0xC]; };
struct S00659988 { const char *name; };

struct Item {
    char pad0[0x1C];
    s32 i1C;
    char name[0x20];
    s32 i40;
};
struct Table { char pad[0x5B30]; s32 count; };
struct Manager { char pad[0x5A8]; Table *table; };

extern StringRep D_00659FA8;
extern Manager D_00645570;

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_004F4C70(Manager *);
extern "C" Item *func_004F4EB8(Manager *, s32);
extern "C" s32 func_001F1368(void *);
extern void mUpdateContext__Sync(int);
extern "C" void func_002ED590(Handle *, int *);
extern "C" Handle *func_002EFBF0(Handle *);
extern "C" void func_002EEEB0(Handle *, void *, Handle *);
extern "C" void func_00309378(Handle *, int);
extern "C" void func_002ED5C0(Handle *, int);
extern "C" void func_002ED5A8(Handle *, Handle *);
extern "C" void func_002FE278(Handle *, int);
extern "C" void func_002FC870(Handle *, int);
/* Declared as returning its first argument (other sources of this unit declare it void): the call
 * is then a SET of $v0, so the next `$v0 = &value` reload depends on the call instead of on this
 * call's own `$v0 = &value` reload; that one keeps 2 dependents against 3 for the `$v1 = &text`
 * reload, and sched2 issues the $v1 one first, as the original does. */
extern "C" Handle *func_00314B20(Handle *, String *);
extern "C" void func_00312318(Handle *, int);

static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

static inline String &assign(String *str, const char *s, u32 n) {
    return *func_005C2630(str, 0, (u32)-1, s, n);
}

static inline void construct(String *str, const char *s) {
    str->dat = grab(&D_00659FA8);
    assign(str, s, func_0057F260(s));
}


static inline void release(String *s) {
    StringRep *q = (StringRep *)(s->dat - 0x10);
    if (--q->ref == 0) {
        s32 size = q->res + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}




static inline void *get(Handle *h) { return h->p; }
static inline void add_str(void *a, String *s, Handle *v, Handle *tmp) {
    func_00314B20(v, s);
    func_002EEEB0(tmp, a, v);
    func_00309378(tmp, 2);
    func_00312318(v, 2);
    release(s);
}
static inline void add_int(void *a, Handle *v, Handle *tmp) {
    func_002EEEB0(tmp, a, v);
    func_00309378(tmp, 2);
    func_002FC870(v, 2);
}

/* Builds the list of table rows as script values: waits until the manager is ready, returns the
 * integer 0 when the context check fails, otherwise one row [int +0x1C, string +0x20, int +0x40]
 * per entry of the manager's table.
 * Shape notes: one return (ret then has 4 references and is the pseudo left on the stack);
 * &row is written directly at every use (a pointer variable set inside the loop is split by gcse
 * into the variable and PRE's reaching register; set before the loop it lands above the loop
 * guard); the first add passes &tmp directly, the others through ptmp. */
extern "C" Handle *func_001F5850(Handle *ret, void *ctx) {
    Handle list;
    Handle row;
    Handle tmp;
    Handle v;
    Handle v2;
    String s;
    Handle v3;
    int zero;
    s32 i;
    s32 n;

    while (!func_004F4C70(&D_00645570))
        mUpdateContext__Sync(1);
    if (!func_001F1368(ctx)) {
        zero = 0;
        func_002ED590(ret, &zero);
    } else {
    func_002EFBF0(&list);
    n = D_00645570.table->count;
    for (i = 0; i < n; i++) {
        Item *it = func_004F4EB8(&D_00645570, i);
        func_002EFBF0(&row);
        Handle *ptmp = &tmp;
        { void *a = get(&row); func_002FE278(&v, it->i1C); add_int(a, &v, &tmp); }
        { void *a = get(&row); construct(&s, it->name); add_str(a, &s, &v2, ptmp); }
        { void *a = get(&row); func_002FE278(&v3, it->i40); add_int(a, &v3, ptmp); }
        func_002EEEB0(ptmp, get(&list), &row);
        func_00309378(ptmp, 2);
        func_002ED5C0(&row, 2);
    }
    func_002ED5A8(ret, &list);
    func_002ED5C0(&list, 2);
    }
    return ret;
}
