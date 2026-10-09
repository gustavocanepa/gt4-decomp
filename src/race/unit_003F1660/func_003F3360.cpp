typedef signed char s8;

struct Obj { char pad[0x6C4]; s8 unk6C4; };

extern "C" void func_003F3360(Obj *arg0) {
    arg0->unk6C4 = 0;
}
