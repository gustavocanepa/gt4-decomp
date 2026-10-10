typedef int s32;
typedef short s16;

struct Obj {
    char pad[0x1003C];
    s16 unk1003C;
};

extern "C" s32 SetupHumanInterfaceParameters(Obj *arg0) {
    arg0->unk1003C = 0;
    return 0;
}
