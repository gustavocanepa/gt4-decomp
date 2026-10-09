typedef int s32;
typedef float f32;

struct Obj;

extern "C" s32 func_0038D0C0(Obj *arg0);

struct Ret {
    char pad[0x10];
    f32 unk10;
};

extern "C" f32 NormalCarGeometry__virtual_14(Obj *arg0) {
    return ((Ret *)func_0038D0C0(arg0))->unk10;
}
