#include "types.h"

/*
 * func_001F38B0 (inferred): returns the current network game's info as a script value array.
 * The network manager (D_00645570) keeps two game records: the online one at +0x88C (used when
 * +0x3F24 is set) and the LAN one at +0x70C (used when the session at +0x5E4 is open). The record
 * must belong to the current game id (+0xA3C); its five ints, two names and four more ints are
 * appended to a new array, which is returned. Without a valid record the result is the value 0.
 *
 * The result is returned by value through the hidden pointer (g++'s named return value): each
 * branch ends with its own copy into the result, destruction of the array and return, and the
 * address register is set once at the return label. That is what lets jump2 cross-jump the
 * online branch into the LAN branch's tail as retail does.
 */

struct Handle {
    void *p;
    char pad[0xC];
};

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; char pad[0xC]; };
struct S00659988 { const char *name; };

extern StringRep D_00659FA8;
extern char D_00645570[];

extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_002ED590(Handle *, int *);
extern "C" Handle *func_002EFBF0(Handle *);
extern "C" void func_002EEEB0(Handle *, void *, Handle *);
extern "C" void func_00309378(Handle *, int);
extern "C" void func_002ED5C0(Handle *, int);
extern "C" void func_002ED5A8(Handle *, Handle *);
extern "C" void func_002FE278(Handle *, int);
extern "C" void func_002FC870(Handle *, int);
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

#define FIELD(base, off) (*(s32 *)((char *)(base) + (off)))

extern "C" Handle func_001F38B0(void *ctx) return result {
    Handle list;
    Handle tmp;
    Handle v;
    char *net = D_00645570;
    char *lanSession = net + 0x5E4;
    if (FIELD(net, 0x3F24)) {
        char *game = net + 0x88C;
        if (FIELD(game, 0x1A0) != FIELD(net, 0xA3C))
            goto invalid;
        Handle v2;
        Handle v3;
        Handle v4;
        Handle v5;
        Handle v6;
        String name1;
        String name2;
        func_002EFBF0(&list);
        Handle *ptmp = &tmp;
        { void *p = get(&list); func_002FE278(&v, FIELD(game, 0x180)); add_int(p, &v, ptmp); }
        { void *p = get(&list); func_002FE278(&v2, FIELD(game, 0x17C)); add_int(p, &v2, ptmp); }
        { void *p = get(&list); func_002FE278(&v3, FIELD(game, 0x188)); add_int(p, &v3, ptmp); }
        { void *p = get(&list); func_002FE278(&v4, FIELD(game, 0x18C)); add_int(p, &v4, ptmp); }
        { void *p = get(&list); func_002FE278(&v5, FIELD(game, 0x184)); add_int(p, &v5, ptmp); }
        { void *p = get(&list); construct(&name1, game + 0x55); add_str(p, &name1, &v6, ptmp); }
        { void *p = get(&list); construct(&name2, game + 0x15); add_str(p, &name2, &v, ptmp); }
        { void *p = get(&list); func_002FE278(&v, FIELD(game, 0x190)); add_int(p, &v, ptmp); }
        { void *p = get(&list); func_002FE278(&v, FIELD(game, 0x194)); add_int(p, &v, ptmp); }
        { void *p = get(&list); func_002FE278(&v, FIELD(game, 0x198)); add_int(p, &v, ptmp); }
        { void *p = get(&list); func_002FE278(&v, FIELD(game, 0x19C)); add_int(p, &v, ptmp); }
        func_002ED5A8(&result, &list);
        func_002ED5C0(&list, 2);
        return;
    } else {
        if (!FIELD(lanSession, 8))
            goto invalid;
        char *game = net + 0x70C;
        if (FIELD(game, 0x14) != FIELD(net, 0xA3C))
            goto invalid;
        Handle v2;
        Handle v3;
        String name1;
        String name2;
        func_002EFBF0(&list);
        Handle *ptmp = &tmp;
        { void *p = get(&list); func_002FE278(&v2, FIELD(game, 0x15C)); add_int(p, &v2, ptmp); }
        { void *p = get(&list); func_002FE278(&v3, FIELD(game, 0x160)); add_int(p, &v3, ptmp); }
        { void *p = get(&list); func_002FE278(&v, FIELD(game, 0x164)); add_int(p, &v, ptmp); }
        { void *p = get(&list); func_002FE278(&v, FIELD(game, 0x168)); add_int(p, &v, ptmp); }
        { void *p = get(&list); func_002FE278(&v, FIELD(game, 0x18)); add_int(p, &v, ptmp); }
        { void *p = get(&list); construct(&name1, game + 0x5C); add_str(p, &name1, &v, ptmp); }
        { void *p = get(&list); construct(&name2, game + 0x1C); add_str(p, &name2, &v, ptmp); }
        { void *p = get(&list); func_002FE278(&v, FIELD(game, 0x16C)); add_int(p, &v, ptmp); }
        { void *p = get(&list); func_002FE278(&v, FIELD(game, 0x170)); add_int(p, &v, ptmp); }
        { void *p = get(&list); func_002FE278(&v, FIELD(game, 0x174)); add_int(p, &v, ptmp); }
        { void *p = get(&list); func_002FE278(&v, FIELD(game, 0x178)); add_int(p, &v, ptmp); }
        func_002ED5A8(&result, &list);
        func_002ED5C0(&list, 2);
        return;
    }
invalid:
    {
        int zero = 0;
        func_002ED590(&result, &zero);
    }
}
