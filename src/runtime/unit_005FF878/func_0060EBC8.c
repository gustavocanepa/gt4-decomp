typedef int s32;
typedef unsigned int u32;

struct Ring0060EBC8 {
    u32 wr;
    u32 rd;
    s32 count;
};

void func_0060EBC8(struct Ring0060EBC8 *r, s32 n) {
    u32 p = r->wr + n;
    s32 c = r->count;
    if (p >= 0x100) {
        p -= 0x100;
    }
    r->count = c + n;
    r->wr = p;
}
