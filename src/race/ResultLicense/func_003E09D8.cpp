typedef int s32;

struct Obj {
    char pad[0x564];
    s32 unk564;
};

extern "C" void ResultLicense__disableEffect(struct Obj *arg0);

extern "C" void func_003E09D8(struct Obj *arg0, s32 arg1) {
    arg0->unk564 = arg1;
    ResultLicense__disableEffect(arg0);
}
