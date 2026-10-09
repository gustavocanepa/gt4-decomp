typedef int s32;

struct Obj {
    s32 unk0;
    char pad4[4];
    s32 unk8;
};

extern "C" void func_004F8E20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" void func_004F9078(s32 arg0, Obj *arg1) {
    func_004F8E20(arg0, arg1->unk0, arg1->unk8, 0, 0);
}
