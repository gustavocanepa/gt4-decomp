typedef int s32;

struct Obj {
    char pad[0x10];
    void *unk10;
};

extern "C" int func_00436FC0(void *a0, void *a1);

extern "C" void func_005CC740(struct Obj *arg0) {
    func_00436FC0(arg0->unk10, 0);
}
