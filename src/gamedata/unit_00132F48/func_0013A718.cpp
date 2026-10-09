typedef int s32;

struct Obj {
    char pad[0x2A8];
    s32 unk2A8;
};

extern "C" s32 func_00145AB8(s32 arg0);

extern "C" s32 func_0013A718(Obj *arg0) {
    return func_00145AB8(arg0->unk2A8);
}
