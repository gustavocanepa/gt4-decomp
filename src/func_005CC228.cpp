typedef int s32;
typedef float f32;

struct Obj2 {
    char pad[0x8C];
    s32 unk8C;
};

struct Obj {
    char pad[0x10];
    struct Obj2 *unk10;
};

extern "C" void func_005CC228(struct Obj *arg0, f32 arg1) {
    arg0->unk10->unk8C = (s32)(arg1 * 128.0f);
}
