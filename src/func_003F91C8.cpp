typedef int s32;
typedef unsigned char u8;

struct Elem003F91C8 {
    char pad0[0x1EC];
    u8 unk1EC;
};

extern "C" s32 func_003F91C8(char *arg0, s32 arg1) {
    arg0 = arg0 + arg1 * 0xEC;
    return ((struct Elem003F91C8 *)arg0)->unk1EC != 0;
}
