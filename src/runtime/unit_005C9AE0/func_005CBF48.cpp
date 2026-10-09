typedef int s32;
typedef float f32;

struct Obj2 {
    char pad[0x60];
    s32 unk60;
};

struct Obj {
    char pad[0x10];
    struct Obj2 *unk10;
};

extern "C" void func_005CBF48(struct Obj *arg0, f32 arg1) {
    arg0->unk10->unk60 = (s32)(arg1 * 128.0f);
}
