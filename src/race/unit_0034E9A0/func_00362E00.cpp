typedef signed char s8;

struct Obj {
    char pad[0x466];
    s8 unk466;
    s8 unk467;
};

extern "C" void func_00362E00(Obj *arg0, s8 arg1) {
    arg0->unk466 = arg1;
    arg0->unk467 = 0;
}
