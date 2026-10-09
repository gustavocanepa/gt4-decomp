/* basic_string<char>::Rep::clone() (gcc 2.96 libstdc++ v2, std/bastring.h, with the engine's
 * tagged allocator): a 16-byte header (length, capacity, reference count, spare) followed by the
 * text. Rep::create() rounds the capacity with frob_size() (16, doubled until the text and its
 * terminator fit) and starts the copy with one reference. Returns the text of the copy. */
typedef unsigned int u32;

struct Heap { const char *name; };
struct StringRep { u32 len; u32 cap; u32 refs; u32 spare; };

extern struct Heap *func_005C11A8(void);
extern void *func_00326750(int size, int align, const char *name);
extern void *func_005A4724(void *dst, const void *src, u32 n);

static inline u32 frob_size(u32 s) {
    u32 i = 16;
    while (i < s)
        i *= 2;
    return i;
}

/* Rep::operator new: the size is a parameter, evaluated before the current heap is looked up */
static inline void *rep_new(u32 n) {
    return func_00326750(n, 4, func_005C11A8()->name);
}

static inline struct StringRep *create(u32 extra) {
    struct StringRep *p;
    extra = frob_size(extra + 1);
    p = rep_new(sizeof(struct StringRep) + extra);
    p->cap = extra;
    p->refs = 1;
    p->spare = 0;
    return p;
}

static inline char *data(struct StringRep *r) { return (char *)(r + 1); }
static inline void copy(struct StringRep *r, u32 pos, const char *s, u32 n) {
    if (n)
        func_005A4724(data(r) + pos, s, n);
}
char *func_005C2560(struct StringRep *src) {
    struct StringRep *p = create(src->len);
    copy(p, 0, data(src), src->len);
    p->len = src->len;
    return data(p);
}
