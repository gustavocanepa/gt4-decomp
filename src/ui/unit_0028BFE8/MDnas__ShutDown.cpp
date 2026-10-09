typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_0028BDA8(struct Buf00109C40 *arg0);
extern "C" void func_0028D0B0(s32 arg0);
extern "C" void func_0028BD50(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void MDnas__ShutDown(void) {
    struct Buf00109C40 buf;

    func_0028BDA8(&buf);
    func_0028D0B0(buf.unk0);
    func_0028BD50(&buf, 2);
}
