typedef int s32;
typedef unsigned int u32;

struct Ring0060EC10 {
    u32 wr;
    u32 rd;
    s32 count;
};

void func_0060EC10(struct Ring0060EC10 *r, s32 n) {
    u32 p = r->rd + n;
    s32 c = r->count;
    if (p >= 0x1000) {
        p -= 0x1000;
    }
    r->count = c - n;
    r->rd = p;
}
