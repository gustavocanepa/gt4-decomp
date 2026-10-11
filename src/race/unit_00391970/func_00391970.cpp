typedef int s32;

struct Arg1 {
    char pad0[4];
    s32 unk4;
    s32 unk8;
};

extern "C" void memcpy(void *arg0, s32 arg1, s32 arg2);

extern "C" void *func_00391970(void *arg0, Arg1 *arg1) {
    memcpy((char *)arg0 + 0x24, arg1->unk4, arg1->unk8);
    return arg0;
}
