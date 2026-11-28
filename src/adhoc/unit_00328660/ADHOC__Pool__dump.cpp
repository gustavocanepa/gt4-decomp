/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

/* Pool allocator report: one block per chunk, then the totals, the peak use
 * as a percentage and, when the pool ran full, a banner with the pool size to
 * paste into the size table. */

struct Out {
    void printf(const char *fmt, ...) __asm__("func_0030C378");
    void indent() __asm__("func_0030C430");
    void unindent() __asm__("func_0030C448");
};

struct Chunk {
    char pad0[8];
    Chunk *next;
    s32 used;
    char pad10[4];
    void *start;
    void *end;
};

struct Pool {
    char pad0[0x30];
    Chunk *chunks;
    char pad34[8];
    s32 freeCount;
    u32 elementSize;
    u32 chunkElements;
    char pad48[4];
    u32 maxUse;
};

/* Defined earlier in this unit, so the original call could not throw (delay-slot liveness
   scans go past it). */
extern "C" s32 func_00328A38(Pool *self) throw();
extern "C" double fptodp(float);

extern char D_0069ECD8[], D_0069ECF0[], D_0069ED00[], D_0069ED28[], D_0069ED40[], D_0069ED58[];
extern char D_0069ED60[], D_0069ED78[], D_0069ED98[], D_0069EDE0[], D_0069EE28[], D_0069EE38[];

extern "C" void ADHOC__Pool__dump(Pool *self, Out *out) {
    s32 n = 0;
    u32 size; /* one scratch for the chunk size and the total below, as the original's
                 registers show (the raw-size copy is only kept because size is used again) */
    out->printf(D_0069ECD8, self->elementSize, self->chunkElements);
    for (Chunk *c = self->chunks; c != 0; c = c->next) {
        out->printf(D_0069ECF0, n);
        out->indent();
        n++;
        u32 count = self->chunkElements;
        size = (self->elementSize + 4) * count + 0x1C;
        u32 raw = size;
        if (size & 0xF) size = (size & ~0xF) + 0x10;
        out->printf(D_0069ED00, c, (char *)c - 0x10, raw, size + 0x10);
        out->printf(D_0069ED28, c->start, c->end);
        out->printf(D_0069ED40, c->used, count);
        out->unindent();
        out->printf(D_0069ED58);
    }
    size = n * self->chunkElements;
    out->printf(D_0069ED60, self->freeCount, size);
    {
        const char *fmt = D_0069ED78;
        u32 total = self->chunkElements;
        u32 use = self->maxUse;
        double percent = 0;
        if (total != 0) percent = (float)use / (float)total * 100.0f;
        out->printf(fmt, use, total, percent);
    }
    if (self->chunkElements != 0 && self->maxUse >= self->chunkElements) {
        const char *bar = D_0069ED98;
        out->printf(bar);
        out->printf(D_0069EDE0);
        out->printf(bar);
        out->printf(D_0069EE28);
    }
    out->printf(D_0069EE38, self->elementSize, func_00328A38(self));
}
