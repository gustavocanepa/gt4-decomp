typedef int s32;
typedef unsigned int u32;

struct Ring006009F0 {
    u32 wr;
    u32 rd;
    s32 count;
};

void func_006009F0(struct Ring006009F0 *r, s32 n) {
    u32 p = r->rd + n;
    s32 c = r->count;
    if (p >= 0xB6A) {
        p -= 0xB6A;
    }
    r->count = c - n;
    r->rd = p;
}
