typedef int s32;
typedef float f32;

struct Elem {
    char pad[0x130];
    f32 arr[1];
};

struct Obj {
    char pad[0x2DC];
    s32 unk2DC;
};

extern "C" f32 func_0045ADD0(Obj *arg0, s32 arg1) {
    return ((Elem *)((char *)arg0 + arg0->unk2DC * 0x16C))->arr[arg1];
}
