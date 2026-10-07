typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad[0x23];
    u8 unk23;
};

extern "C" s32 func_00359EF8(u8 arg0);

extern "C" s32 func_00359F20(Obj *arg0) {
    return func_00359EF8(arg0->unk23);
}
