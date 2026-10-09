typedef int s32;

struct Obj {
    char pad[0x42C];
    s32 unk42C;
};

extern "C" s32 func_004CF580(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" s32 func_0026D320(Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_004CF580(arg0->unk42C, arg1, arg2, arg3 != 0) != 0;
}
