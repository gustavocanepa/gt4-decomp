typedef int s32;
typedef float f32;

struct SubStruct_104 {
    char pad0[0x4C4];
    f32 unk4C4;
    f32 unk4C8;
};

struct Obj {
    char pad0[0x104];
    SubStruct_104 sub104;
};

extern "C" char PDISTD__UNIT_MANAGER[];
extern "C" s32 func_00472AE0(char *arg0, f32 arg1, f32 arg2);

extern "C" s32 Automobile_GetAverageGasMileage10(Obj *arg0) {
    SubStruct_104 *v0 = &arg0->sub104;
    return func_00472AE0(PDISTD__UNIT_MANAGER, v0->unk4C8, v0->unk4C4);
}
