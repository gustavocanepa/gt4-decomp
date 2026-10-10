typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_0022AD20(struct Buf00109C40 *arg0);
extern "C" void mRenderContext__closeOSKeyboard(s32 arg0);
extern "C" void func_0022ACC8(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void MRenderContext__closeOSKeyboard(void) {
    struct Buf00109C40 buf;

    func_0022AD20(&buf);
    mRenderContext__closeOSKeyboard(buf.unk0);
    func_0022ACC8(&buf, 2);
}
