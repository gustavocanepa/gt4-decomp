typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_002CC920(struct Buf00109C40 *arg0);
extern "C" void func_002CDAA0(s32 arg0);
extern "C" void func_002CC8C8(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_002CD2C0(void) {
    struct Buf00109C40 buf;

    func_002CC920(&buf);
    func_002CDAA0(buf.unk0);
    func_002CC8C8(&buf, 2);
}
