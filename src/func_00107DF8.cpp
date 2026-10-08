typedef int s32;

struct Obj {
    char pad[0x8];
    s32 unk8;
    s32 unkC;
};

extern "C" void func_00107DF8(char *arg0) {
    ((Obj *)arg0)->unkC = 1;
    ((Obj *)arg0)->unk8 = (s32)(arg0 + 0x18);
}
