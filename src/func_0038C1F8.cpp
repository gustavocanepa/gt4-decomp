typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad[0x4];
    u32 unk4;
};

extern "C" s32 func_0038C128(Obj *arg0, s32 arg1);

extern "C" s32 func_0038C1F8(Obj *arg0) {
    return func_0038C128(arg0, arg0->unk4 != 0);
}
