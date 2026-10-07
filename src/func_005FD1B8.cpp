typedef int s32;

struct Obj {
    char pad[0x3000];
    s32 unk3000;
};

extern "C" void func_005FD1B8(Obj *arg0) {
    arg0->unk3000 = arg0->unk3000 - 1;
}
