typedef int s32;
typedef unsigned char u8;

struct Elem {
    char pad[0x1ED];
    u8 code;
};

extern u8 D_00620288[];

extern "C" s32 func_003F9158(char *arg0, s32 arg1) {
    struct Elem *e = (struct Elem *)(arg0 + arg1 * 0xEC);
    return D_00620288[e->code] != 0;
}
