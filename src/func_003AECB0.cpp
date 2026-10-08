typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" s32 func_003A1E10(s32 arg0);

extern "C" void func_003AECB0(Obj *arg0, s32 arg1) {
    s32 result = func_003A1E10(arg1);
    arg0->unk10 = result;
}
