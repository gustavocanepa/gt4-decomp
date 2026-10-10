typedef int s32;

struct Sub {
    char pad0[4];
    s32 lo;
    s32 hi;
};

struct Obj {
    char pad0[0xB0];
    struct Sub sub;
};

extern "C" s32 func_00288DB0(struct Obj *arg0, s32 arg1) {
    struct Sub *sub = &arg0->sub;
    s32 lo = sub->lo;
    s32 hi = sub->hi;
    s32 idx = (arg1 < 0) ? 0 : arg1;
    s32 count = (hi - lo) >> 4;
    s32 cond = (idx < count);
    s32 maxIdx = count - 1;
    idx = cond ? idx : maxIdx;
    return lo + idx * 0x10;
}
