typedef int s32;
typedef short s16;

struct Obj {
    char pad[0x60E];
    s16 unk60E;
};

extern "C" void func_0035FC48(Obj *arg0, s32 arg1) {
    arg0->unk60E = (s16)(arg1 * 0x3C);
}
