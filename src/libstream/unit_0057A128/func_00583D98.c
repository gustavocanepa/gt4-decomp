/* compiler: ee-gcc2.9-991111 */
/* Sets up the block pool descriptor over [base, base + size) and builds its first table. */
typedef struct Pool {
    void *base;            /* raw buffer as given by the caller */
    unsigned size;         /* raw size as given by the caller */
    unsigned end;          /* end of the buffer, rounded down to 256 bytes */
    unsigned start;        /* start of the buffer, rounded up to 256 bytes */
    volatile int used;     /* the two counters are volatile: their stores keep source order */
    volatile int count;
} Pool;
extern Pool D_00875878;
extern int func_00583DF8(void);

int func_00583D98(void *base, int size)
{
    Pool *pool = &D_00875878;

    pool->used = 0;
    pool->base = base;
    pool->size = size;
    if ((unsigned)size > 0xFFFFFF00) {
        size = -0x100;
    }
    pool->start = ((unsigned)base + 0xFF) & 0xFFFFFF00;
    pool->end = ((unsigned)base + size) & 0xFFFFFF00;
    pool->count = 0;
    return func_00583DF8();
}
