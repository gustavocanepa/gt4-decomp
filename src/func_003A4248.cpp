typedef int s32;

struct Obj {
    char pad0[0x1C];
    s32 unk1C;
};

extern "C" void func_0057DA20(char *arg0, const char *arg1, ...);

extern "C" void func_003A4248(Obj *arg0, s32 arg1) {
    func_0057DA20((char *)arg0 + 0x20, "%%0%dd", arg1);
    arg0->unk1C = 0;
}
