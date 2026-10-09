typedef int s32;

extern "C" s32 *D_006187A8;

struct Obj00127BF0 {
    char pad[0x37C];
    s32 unk37C;
};

extern "C" void func_00127BF0(void *arg0, s32 arg1, s32 arg2) {
    s32 *temp_v1 = D_006187A8;

    if (temp_v1 != 0) {
        ((struct Obj00127BF0 *)(temp_v1 + arg1))->unk37C = arg2;
    }
}
