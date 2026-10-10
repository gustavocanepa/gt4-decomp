typedef int s32;

struct Obj {
    char pad0[0xF864];
    char unkF864;
};

extern "C" s32 DynamicsConductor__SetupGlobalStatusPre(Obj *arg0);

extern "C" s32 DynamicsConductorTraining__SetupGlobalStatusPre(Obj *arg0) {
    arg0->unkF864 = 0;
    return DynamicsConductor__SetupGlobalStatusPre(arg0);
}
