typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x488];
    f32 unk488;
    char pad2[0x494 - 0x488 - 4];
    f32 unk494;
};

extern "C" f32 func_003F9030(char *arg0, s32 arg1, f32 *arg2) {
    Obj *temp_a0;

    temp_a0 = (Obj *)(arg0 + 0x104);
    *arg2 = temp_a0->unk494;
    return temp_a0->unk488;
}
