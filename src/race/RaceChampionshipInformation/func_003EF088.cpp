typedef int s32;

struct Obj {
    char pad[0x170];
    s32 unk170;
};

extern "C" void func_003EF388(Obj *arg0);

extern "C" void func_003EF088(Obj *arg0) {
    arg0->unk170 = arg0->unk170 + 1;
    func_003EF388(arg0);
}
