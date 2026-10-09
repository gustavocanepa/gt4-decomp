typedef int s32;

struct Obj {
    char pad[0x200];
    s32 unk200;
    s32 unk204;
};

extern "C" void func_004F8938(Obj *arg0) {
    arg0->unk200 = 0;
    arg0->unk204 = -1;
}
