typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_002D2598(struct Buf00109C40 *arg0);
extern "C" void func_002D2BF8(s32 arg0);
extern "C" void func_002D2540(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_002D28E8(void) {
    struct Buf00109C40 buf;

    func_002D2598(&buf);
    func_002D2BF8(buf.unk0);
    func_002D2540(&buf, 2);
}
