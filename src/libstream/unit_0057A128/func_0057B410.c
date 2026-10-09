typedef int s32;
typedef unsigned int u32;

struct Ring0057B410 {
    u32 wr;
    u32 rd;
    s32 count;
    s32 unkC;
    s32 unk10;
    u32 size;
};

void func_0057B410(struct Ring0057B410 *r, s32 n) {
    u32 p = r->wr + n;
    u32 s = r->size;
    s32 c = r->count;
    if (p >= s) {
        p -= s;
    }
    r->count = c + n;
    r->wr = p;
}
