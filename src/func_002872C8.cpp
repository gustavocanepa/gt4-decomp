typedef int s32;

struct Obj002872C8 {
    char pad[0x20];
    s32 unk20;
};

extern "C" void func_0024D1B8(Obj002872C8 *arg0);

extern "C" void func_002872C8(Obj002872C8 *arg0) {
    func_0024D1B8(arg0);
    arg0->unk20 = 0;
}
