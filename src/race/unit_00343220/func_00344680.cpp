typedef unsigned char u8;
typedef float f32;

struct Obj {
    char pad[0x560];
    f32 unk560;
    char pad2[0x569 - 0x560 - 4];
    u8 unk569;
};

extern "C" f32 func_00344680(Obj *arg0, u8 *arg1) {
    if (arg1 != 0) {
        *arg1 = arg0->unk569;
    }
    return arg0->unk560;
}
