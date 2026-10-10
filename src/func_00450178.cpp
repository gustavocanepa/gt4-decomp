typedef int s32;
typedef unsigned short u16;
typedef unsigned long long u64;

struct Table_00450178 {
    char pad0[8];
    u16 count;
    u16 stride;
    char padC[4];
    char data[1];
};

extern "C" s32 func_00450178(Table_00450178 *t, u64 key) {
    s32 lo = -1;
    s32 hi = t->count;
    char *base = t->data;
    s32 stride = t->stride;
    do {
        s32 mid = (lo + hi) >> 1;
        u64 k = *(u64 *)(base + stride * mid);
        if (k == key) {
            return mid;
        }
        if (k < key) {
            lo = mid;
        } else {
            hi = mid;
        }
    } while (lo + 1 != hi);
    return -1;
}
