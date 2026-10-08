typedef int s32;

struct Arg1 {
    char pad[0x8];
    s32 *unk8;
};

extern "C" s32 *func_0030F670(s32 *arg0, Arg1 *arg1) {
    s32 *p = arg1->unk8;
    *arg0 = p[-1];
    return arg0;
}
