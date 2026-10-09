typedef int s32;

struct Obj0030F628 {
    char pad0[4];
    s32 *unk4;
};

extern "C" s32 *func_0030F628(s32 *arg0, struct Obj0030F628 *arg1, s32 arg2) {
    s32 *p = arg1->unk4;
    s32 *addr = p + arg2;
    s32 *ret = arg0;
    *arg0 = *addr;
    return ret;
}
