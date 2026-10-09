typedef int s32;
typedef float f32;

struct Obj2 {
    char pad[0x78];
    s32 unk78;
};

struct Obj {
    char pad[0x10];
    struct Obj2 *unk10;
};

extern "C" void func_005CC0C8(struct Obj *arg0, f32 arg1) {
    arg0->unk10->unk78 = (s32)(arg1 * 128.0f);
}
