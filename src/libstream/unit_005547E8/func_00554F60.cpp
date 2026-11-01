/* compiler: ee-gcc2.96-nogcse-as2004 */
/* Writes size bytes into a stream as a chain of chunks: allocates the chain (flushing chunks
   until one is free), fills each chunk up to its capacity, then queues the chain. The copied
   length goes through size before advancing src, which keeps retail's register roles. */
typedef unsigned int u32;
struct Chunk { int x0; u32 len; Chunk *next; u32 used; char data[1]; } __attribute__((packed));
extern "C" Chunk *func_00554A58(void *, u32, int);
extern "C" Chunk *func_00554CA0(void *);
extern "C" void func_00554D60(void *, Chunk *);
extern "C" void func_00554C10(void *, Chunk *);
extern "C" void *func_005A4724(void *, const void *, u32);
extern "C" void func_00554F60(void *s, const char *src, u32 size) {
    u32 rem = size;
    Chunk *head, *c;
    while ((head = func_00554A58(s, size, 1)) == 0) {
        c = func_00554CA0(s);
        if (c) func_00554D60(s, c);
    }
    c = head;
    do {
        u32 len = c->len;
        if (len >= rem) len = rem < len ? rem : len;
        rem -= len;
        func_005A4724(c->data, src, len);
        c->used = len;
        c = c->next;
        size = len;
        src += size;
    } while (c);
    func_00554C10(s, head);
}
