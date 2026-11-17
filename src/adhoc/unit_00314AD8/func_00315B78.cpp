/*
 * Formats a "{n}" template (inferred: the names are guesses). The template is split at "{" with
 * func_00314B88; the first piece starts the result, and each later piece is split at "}": the text
 * before it is read as an argument index (virtual slot 11 of the value), and when the index is
 * below the size of `args` that argument's string (slot 13 of the list, slot 3 of the value) is
 * appended, then the text after the "}" if there is any. The result is returned as a value built
 * from the string (func_00314B20). hArray__size is a list's size.
 *
 * The strings are placement-new'd into reused buffers, as in func_00314B88: retail keeps one
 * stack slot for the "{" separator and the result, and one for the "}" separator and each
 * appended piece. The per-piece list is placement-new'd too, which takes its address before the
 * "}" separator is built.
 */
#include "types.h"

typedef unsigned int size_t;
inline void *operator new(size_t, void *where) { return where; }

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct HeapName { const char *name; };
struct Str { char *p; char pad[0xC]; };
struct VEntry { s16 delta; s16 index; void *fn; };
struct VObj { char pad0[4]; VEntry *vtbl; };
struct Handle { VObj *p; char pad[0xC]; };
struct Item { VObj *p; char pad[0xC]; };

extern Rep D_00659FA8;              /* basic_string<char>::nilRep */
extern "C" char D_0069E1C8[];       /* "{" */
extern "C" char D_0069E1D0[];       /* "}" */

extern "C" u32 hArray__size(VObj *list);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n1, const char *src, s32 n2);
extern "C" void *func_005CE388(Str *s, s32 pos, s32 n1, const Str *str, s32 pos2, s32 n2);
extern "C" s32 func_0057F260(const char *s);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" HeapName *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void func_00314B20(Item *item, const Str *s);
extern "C" void func_00312318(void *value, s32 flags);
extern "C" void func_002ED5C0(void *list, s32 flags);

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }

static inline char *grab(Rep *r) {
    if (r->sel)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

struct String : Str {
    String(const char *text) {
        p = grab(&D_00659FA8);
        func_005C2630(this, 0, -1, text, func_0057F260(text));
    }
    ~String() { release(this); }
};

struct List {
    VObj *p;
    char pad[0xC];
    VObj *get() const { return p; }
    ~List() { func_002ED5C0(this, 2); }
};

struct Value {
    VObj *p;
    char pad[0xC];
    Value(Handle *h) __asm__("func_00312370");
    ~Value() { func_00312318(this, 2); }
    VObj *get() const { return p; }
};

extern "C" void func_00314B88(List *result, VObj *src, const String *sep);
extern "C" List split(VObj *src, const String *sep) __asm__("func_00314B88");

static inline Handle *at(VObj *list, s32 i) {
    VEntry *e = &list->vtbl[14];
    return ((Handle *(*)(void *, s32))e->fn)((char *)list + e->delta, i);
}

static inline Handle *argument(VObj *list, s32 i) {
    VEntry *e = &list->vtbl[13];
    return ((Handle *(*)(void *, s32))e->fn)((char *)list + e->delta, i);
}

static inline String to_string(VObj *value) {
    VEntry *e = &value->vtbl[3];
    return ((String (*)(void *))e->fn)((char *)value + e->delta);
}

static inline s32 to_int(VObj *value) {
    VEntry *e = &value->vtbl[11];
    return ((s32 (*)(void *))e->fn)((char *)value + e->delta);
}

static inline void append(String *dst, const String *src) {
    func_005CE388(dst, str_length(dst), 0, src, 0, -1);
}

extern "C" Item *func_00315B78(Item *ret, VObj *format, Handle *args) {
    List pieces;
    Str text;
    func_00314B88(&pieces, format, new (&text) String(D_0069E1C8));
    ((String *)&text)->~String();
    new (&text) String(to_string(at(pieces.p, 0)->p));
    for (s32 i = 1; i < (s32)hArray__size(pieces.p); i++) {
        Value piece(at(pieces.p, i));
        Str partsBuffer;
        Str scratch;
        List *parts = new (&partsBuffer) List(split(piece.get(), new (&scratch) String(D_0069E1D0)));
        ((String *)&scratch)->~String();
        s32 index = to_int(at(parts->get(), 0)->p);
        if (index < (s32)hArray__size(args->p)) {
            String *s = new (&scratch) String(to_string(argument(args->p, index)->p));
            append((String *)&text, s);
            s->~String();
        }
        if (hArray__size(parts->get()) >= 2) {
            String *s = new (&scratch) String(to_string(at(parts->get(), 1)->p));
            append((String *)&text, s);
            s->~String();
        }
        parts->~List();
    }
    func_00314B20(ret, (String *)&text);
    ((String *)&text)->~String();
    return ret;
}
