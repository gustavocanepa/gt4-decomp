typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" void func_00558FB0(s32 arg0, struct Obj *arg1);

extern "C" void func_005596D8(struct Obj *arg0) {
    func_00558FB0(arg0->unk10, arg0);
}
