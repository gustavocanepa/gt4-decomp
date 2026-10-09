typedef int s32;
typedef float f32;

struct Obj003F90C8 {
    char pad[0x20C];
    f32 unk20C;
};

extern "C" f32 func_003F90C8(char *arg0, s32 arg1) {
    arg0 = arg0 + arg1 * 0xEC;
    return ((struct Obj003F90C8 *)arg0)->unk20C;
}
