typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x5C4];
    f32 unk5C4;
};

extern char PDISTD__UNIT_MANAGER;

extern "C" s32 func_00472A78(void *arg0, f32 arg1);

extern "C" s32 Automobile_GetGasConsumption(Obj *arg0) {
    return func_00472A78(&PDISTD__UNIT_MANAGER, arg0->unk5C4);
}
