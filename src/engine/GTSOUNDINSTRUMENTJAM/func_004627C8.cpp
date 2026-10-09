typedef int s32;

struct Obj {
    char pad[0x94];
    s32 unk94;
};

extern "C" void func_00462670(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_004627C8(s32 arg0, Obj *arg1) {
    func_00462670(arg0, arg1->unk94, 0);
}
