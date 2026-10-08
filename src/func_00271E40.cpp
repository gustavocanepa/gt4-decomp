typedef int s32;

struct Obj_00271E40 {
    char pad[0x10];
    s32 unk10;
};

extern "C" void func_00520E60(s32 arg0);

extern "C" void func_00271E40(struct Obj_00271E40 *arg0) {
    func_00520E60(arg0->unk10);
    arg0->unk10 = 0;
}
