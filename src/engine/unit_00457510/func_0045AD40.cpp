typedef int s32;
typedef float f32;

struct Elem {
    char pad[0x128];
    f32 unk128;
};

struct Obj {
    char pad[0x2DC];
    s32 unk2DC;
};

extern "C" f32 func_0045AD40(Obj *arg0) {
    return ((Elem *)((char *)arg0 + arg0->unk2DC * 0x16C))->unk128;
}
