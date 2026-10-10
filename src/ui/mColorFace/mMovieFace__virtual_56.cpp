typedef int s32;
typedef float f32;

struct Elem00288E98 {
    char pad0[0xC];
    f32 unkC;
};

struct Base00288E98 {
    char pad0[4];
    s32 unk4;
    s32 unk8;
};

extern "C" f32 mMovieFace__virtual_56(char *arg0, s32 arg1) {
    struct Base00288E98 *base = (struct Base00288E98 *)(arg0 + 0xA0);
    s32 count;
    s32 idx;

    if (arg1 < 0) {
        arg1 = 0;
    }
    count = (base->unk8 - base->unk4) >> 4;
    idx = (arg1 < count) ? arg1 : count - 1;
    return ((struct Elem00288E98 *)(base->unk4 + (idx << 4)))->unkC;
}
