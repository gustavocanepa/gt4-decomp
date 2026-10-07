typedef signed char s8;

struct Obj { char pad[0x547]; s8 unk547; };

extern "C" void func_003487F0(Obj *arg0, s8 arg1) {
    arg0->unk547 = arg1;
}
