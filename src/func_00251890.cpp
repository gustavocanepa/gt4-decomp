typedef int s32;
typedef short s16;

struct B {
    char pad[0x94];
    s16 field94[1];
    s32 field98[1];
};

extern "C" void func_00251890(struct B *arg0, s32 arg1, s32 arg2) {
    arg0->field98[arg1] = arg2;
    if (arg2 != 0) {
        arg0->field94[arg1] = 1;
    }
}
