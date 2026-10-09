typedef int s32;

struct Obj { char pad[0x104]; s32 unk104; };

extern "C" s32 func_002B7110(s32 arg0);

extern "C" s32 func_002450D0(Obj *arg0) {
    return func_002B7110(arg0->unk104);
}
