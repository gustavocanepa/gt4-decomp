typedef int s32;

struct Obj {
    char pad[0x80];
    s32 unk80;
};

extern "C" void func_00394B80(void);
extern "C" void func_00394E70(s32 arg0);

extern "C" void func_003C0008(struct Obj *arg0) {
    s32 temp_v0 = arg0->unk80;

    if (temp_v0 != 0) {
        func_00394E70(temp_v0);
    }
    func_00394B80();
}
