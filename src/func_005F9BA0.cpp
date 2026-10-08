typedef float f32;
typedef short s16;

struct Obj {
    char pad[0xA];
    s16 unkA;
    char pad2[0x1C - 0xA - 2];
    f32 unk1C;
};

extern "C" f32 func_005F9BA0(Obj *arg0) {
    return arg0->unk1C * (f32)arg0->unkA;
}
