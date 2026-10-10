typedef int s32;

struct Obj {
    char pad[0xCD8];
    s32 unkCD8;
};

extern "C" void RaceBase__setPause(Obj *arg0, s32 arg1) {
    arg0->unkCD8 = arg1;
}
