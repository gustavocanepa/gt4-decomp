typedef int s32;
typedef short s16;
typedef float f32;

struct Obj {
    char pad0[0x4FA];
    s16 unk4FA;
    char pad4FC[0x634 - 0x4FA - 2];
    f32 unk634;
    s32 unk638;
};

extern "C" void func_00350EB0(char *arg0) {
    struct Obj *obj = (struct Obj *)(arg0 + 0x104);
    s32 temp_v0 = obj->unk4FA;
    obj->unk638 = 0;
    obj->unk634 = (f32)temp_v0;
}
