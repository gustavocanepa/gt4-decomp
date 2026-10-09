typedef int s32;

struct Obj {
    char pad0[0xA8];
    s32 unkA8;
    s32 unkAC;
};

extern "C" void func_001C5E48(void *arg0);

extern "C" void func_001C7260(Obj *arg0) {
    arg0->unkAC = 1;
    arg0->unkA8 = 0;
    func_001C5E48(arg0);
    func_001C5E48((char *)arg0 + 0x54);
}
