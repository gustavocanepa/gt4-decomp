typedef int s32;

struct Obj005FBAF8 {
    char pad[0x80];
    s32 unk80;
};

extern "C" void func_00394E70(s32 arg0);

extern "C" void func_005FBAF8(struct Obj005FBAF8 *arg0) {
    func_00394E70(arg0->unk80);
}
