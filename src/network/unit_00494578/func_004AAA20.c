typedef signed char s8;
struct Entry { int *tag; int pad[4]; };
struct Pool { char pad0[0xC30]; struct Entry entries[1]; };
struct Cache { char pad0[0x14]; struct Pool pool; };
int func_004AA858(struct Cache *self, int blocks);
void func_004AAAF0(struct Cache *self);
void func_004A1FA8(struct Cache *self, int flags);

/* Statement macro of the packet code: its block keeps the store ahead of the call setup. */
#define WRITE_TAG(p, v) do { *(p) = (v); } while (0)

/* Allocate `size` bytes (in 2048-byte blocks), evicting the oldest entries until it fits. */
int func_004AAA20(struct Cache *self, int size) {
    int blocks = (size + 0x7FF) / 0x800;
    int r = func_004AA858(self, blocks);
    if (r < 0) {
        int *tag = 0;
        struct Pool *pool = &self->pool;
        for (;;) {
            r = *((s8 *)self + 0xEBC);          /* oldest entry, -1 when none is left */
            if (r < 0) break;
            tag = pool->entries[r].tag;
            func_004AAAF0(self);
            r = func_004AA858(self, blocks);
            if (r >= 0) break;
        }
        if (tag) {
            WRITE_TAG(tag, 0x91020000);
            func_004A1FA8(self, 0x10000);
        }
    }
    return r;
}
