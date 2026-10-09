typedef int s32;

struct Obj {
    char pad[0x58];
    s32 unk58;
};

extern "C" void func_005A3AB8(s32 arg0);

extern "C" void stdiobuf__virtual_14(struct Obj *arg0) {
    func_005A3AB8(arg0->unk58);
}
