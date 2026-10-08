typedef int s32;

extern "C" s32 *D_006187A8;

struct Obj00127E10 {
    char pad[0x454];
    s32 unk454;
};

extern "C" void func_00127E10(void *arg0, s32 arg1, s32 arg2) {
    s32 *temp_v1 = D_006187A8;

    if (temp_v1 != 0) {
        ((struct Obj00127E10 *)(temp_v1 + arg1))->unk454 = arg2;
    }
}
