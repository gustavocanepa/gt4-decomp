/*
 * Splits the string held by `src` (read through func_00314AD8) at every occurrence of `sep`
 * and returns the pieces as a list, by value in `result` (inferred: the names are guesses).
 * func_005A6DC8 is strstr; each piece is a basic_string<char> built in place from [p, q)
 * (bastring.h's nilRep.grab() then the iterator replace, func_005C5028), wrapped as a list
 * item (func_00314B20) and inserted at the list's end (func_002EEEB0); the text after the last
 * separator becomes the final piece (replace(0, npos, p, strlen(p)), func_005C2630).
 *
 * Every piece is placement-new'd into one buffer: retail keeps one stack slot for all of them,
 * with the buffer address and the returned pointer in two registers. The new rep pointer is
 * stored as an s32 so that its store and the length load that follows share an alias set.
 */
#include "types.h"

typedef unsigned int size_t;
inline void *operator new(size_t, void *where) { return where; }

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct HeapName { const char *name; };
struct Str { char *p; char pad[0xC]; };
struct Source;
struct List;
struct Item;
struct Iterator;
struct ListValue { void *p; char pad[0xC]; };

extern Rep D_00659FA8;              /* basic_string<char>::nilRep */
extern "C" char D_0069E1B0[];       /* "" */

extern "C" void func_002EFBF0(List *list);
extern "C" void func_002ED5A8(ListValue *result, List *list);
extern "C" void func_002ED5C0(List *list, s32 flags);
extern "C" void func_00309378(Iterator *it, s32 flags);
extern "C" void func_00312318(Item *item, s32 flags);
extern "C" void func_00314B20(Item *item, Str *s);
extern "C" const char *func_00314AD8(Source *src);
extern "C" const char *func_005A6DC8(const char *s, const char *find);
extern "C" void func_005C5028(Str *s, char *i1, char *i2, const char *j1, const char *j2);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n1, const char *src, s32 n2);
extern "C" s32 func_0057F260(const char *s);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" HeapName *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }

static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) {
        return D_0069E1B0;
    }
    str_terminate(s);
    return rep_data(str_rep(s));
}

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
    String(const char *first, const char *last) {
        *(s32 *)&p = (s32)grab(&D_00659FA8);
        func_005C5028(this, p, p + str_length(this), first, last);
    }
    String(const char *s) {
        p = grab(&D_00659FA8);
        func_005C2630(this, 0, -1, s, func_0057F260(s));
    }
    ~String() { release(this); }
};

struct Item {
    void *p;
    char pad[0xC];
    Item(const String &s) { func_00314B20(this, (Str *)&s); }
    ~Item() { func_00312318(this, 2); }
};

struct Iterator {
    void *p;
    char pad[0xC];
    ~Iterator() { func_00309378(this, 2); }
};

struct ListObject {
    Iterator insert(const Item &item) __asm__("func_002EEEB0");
};

struct List {
    ListObject *p;
    char pad[0xC];
    ListObject *operator->() const { return p; }
};

extern "C" ListValue *func_00314B88(ListValue *result, Source *src, Str *sep) {
    List list;
    Str buffer;
    func_002EFBF0(&list);
    const char *separator = c_str(sep);
    s32 separatorLength = str_length(sep);
    const char *p = func_00314AD8(src);
    const char *found = func_005A6DC8(p, separator);
    while (found != 0) {
        String *piece = new (&buffer) String(p, found);
        p = found + separatorLength;
        list->insert(Item(*piece));
        found = func_005A6DC8(p, separator);
        piece->~String();
    }
    String *rest = new (&buffer) String(p);
    list->insert(Item(*rest));
    func_002ED5A8(result, &list);
    rest->~String();
    func_002ED5C0(&list, 2);
    return result;
}
