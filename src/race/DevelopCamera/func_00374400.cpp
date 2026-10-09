typedef int s32;

struct Elem {
    char pad[0x148];
    s32 unk148;
};

extern "C" s32 func_00374400(char *arg0, s32 arg1) {
    return ((Elem *)(arg0 + arg1 * 0x19C))->unk148;
}
