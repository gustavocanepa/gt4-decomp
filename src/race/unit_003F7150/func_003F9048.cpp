typedef int s32;
typedef float f32;

struct Elem003F9048 {
    char pad0[0x1C8];
    f32 unk1C8;
};

struct Obj003F9048 {
    char pad0[0x590];
    f32 unk590;
};

extern "C" f32 func_003F9048(char *arg0, s32 arg1, f32 *arg2) {
    char *base = arg0;
    base = base + arg1 * 0xEC;
    *arg2 = ((struct Elem003F9048 *)base)->unk1C8;
    return ((struct Obj003F9048 *)arg0)->unk590;
}
