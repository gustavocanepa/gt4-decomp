typedef int s32;

struct Inner003465E0 {
    char pad[4];
    s32 unk4;
};

struct Obj003465E0 {
    char pad[0x48];
    struct Inner003465E0 *unk48;
};

extern "C" s32 func_003465E0(struct Obj003465E0 *arg0) {
    struct Inner003465E0 *temp_a0;

    if (arg0 == 0 || (temp_a0 = arg0->unk48) == 0) {
        return 0;
    }
    return (temp_a0->unk4 + 3) & ~3;
}
