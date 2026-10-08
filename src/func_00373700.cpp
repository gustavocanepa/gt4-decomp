typedef int s32;

struct Elem {
    char pad[0x13C];
    s32 unk13C;
};

extern "C" s32 func_00373700(char *arg0, s32 arg1) {
    return ((Elem *)(arg0 + arg1 * 0x19C))->unk13C;
}
