typedef int s32;

struct Obj {
    char pad[0xCD0];
    s32 unkCD0;
    char pad2[0xE414 - 0xCD0 - 4];
    s32 unkE414;
};

extern "C" void func_0038BA90(Obj *arg0, s32 arg1) {
    if (arg0->unkCD0 == 0) {
        arg0->unkE414 = arg1;
    }
}
