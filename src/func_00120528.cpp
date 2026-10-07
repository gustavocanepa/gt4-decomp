typedef float f32;

struct Obj {
    char pad[0x2DC];
    f32 unk2DC;
    char pad2[0x2F8 - 0x2DC - 4];
    f32 unk2F8;
    f32 unk2FC;
};

extern "C" f32 func_00120528(Obj *arg0) {
    f32 a = arg0->unk2F8;
    f32 diff = arg0->unk2FC - a;
    f32 other = arg0->unk2DC;
    f32 result;
    __asm__("min.s %0, %1, %2" : "=f"(result) : "f"(other), "f"(diff));
    return result;
}
