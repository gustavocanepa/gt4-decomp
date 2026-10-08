typedef int s32;

struct Obj {
    char pad[0xE4];
    s32 unkE4;
    s32 unkE8;
    s32 unkEC;
};

extern "C" void func_00463930(Obj *arg0, s32 arg1, s32 arg2) {
    arg0->unkE4 = arg1;
    arg0->unkE8 = arg2;
    arg0->unkEC = arg1 + 0xDA50;
}
