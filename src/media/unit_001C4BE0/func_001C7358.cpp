typedef int s32;

struct Obj {
    char pad[0xA8];
    s32 unkA8;
    s32 unkAC;
};

extern "C" void func_001C5E88(void *arg0);
extern "C" void func_001C60B0(void *arg0);

extern "C" void func_001C7358(Obj *arg0) {
    s32 v0 = arg0->unkAC;
    s32 v1 = arg0->unkA8;
    arg0->unkA8 = v0;
    arg0->unkAC = v1;
    func_001C5E88((char *)arg0 + v0 * 0x54);

    s32 v0b = arg0->unkAC;
    func_001C60B0((char *)arg0 + v0b * 0x54);
}
