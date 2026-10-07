typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001D6ED8(struct Buf00109C40 *arg0);
extern "C" void func_001D9C58(s32 arg0);
extern "C" void func_001D6E80(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001D7F50(void) {
    struct Buf00109C40 buf;

    func_001D6ED8(&buf);
    func_001D9C58(buf.unk0);
    func_001D6E80(&buf, 2);
}
