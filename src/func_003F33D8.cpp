typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

struct Obj {
    char pad[0x466];
    s8 unk466;
    u8 unk467;
};

extern "C" s32 func_003F33D8(char *arg0base) {
    struct Obj *arg0 = (struct Obj *)(arg0base + 0x104);

    if (arg0->unk466 != 1) {
        return 0;
    }
    return arg0->unk467 == 0;
}
