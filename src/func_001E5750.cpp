typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001DC650(struct Buf00109C40 *arg0);
extern "C" void func_001F6A78(s32 arg0);
extern "C" void func_001DC5F8(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001E5750(void) {
    struct Buf00109C40 buf;

    func_001DC650(&buf);
    func_001F6A78(buf.unk0);
    func_001DC5F8(&buf, 2);
}
