typedef signed char s8;

struct Obj {
    char pad[0x40];
    s8 unk40;
    s8 unk41;
};

extern "C" void func_00469E48(Obj *arg0) {
    arg0->unk41 = 0;
    arg0->unk40 = -1;
}
