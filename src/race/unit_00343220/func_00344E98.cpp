typedef int s32;
typedef signed char s8;

struct Arg0 {
    char pad[0x10];
    void *unk10;
};

extern "C" void *func_00359510(void *arg0);

extern "C" s8 func_00344E98(Arg0 *arg0, char *arg1) {
    char *s0 = arg1 + (s32)func_00359510(arg0->unk10);
    return *(s8 *)(s0 + 0x4C);
}
