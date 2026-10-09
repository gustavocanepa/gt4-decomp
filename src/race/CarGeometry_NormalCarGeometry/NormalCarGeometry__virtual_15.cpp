typedef int s32;
typedef float f32;

struct Obj;

extern "C" s32 func_0038D0C0(Obj *arg0);

struct Ret {
    char pad[0x14];
    f32 unk14;
};

extern "C" f32 NormalCarGeometry__virtual_15(Obj *arg0) {
    return ((Ret *)func_0038D0C0(arg0))->unk14;
}
