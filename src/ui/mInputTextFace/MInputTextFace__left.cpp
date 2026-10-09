typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_002A5E18(struct Buf00109C40 *arg0);
extern "C" void func_002A7B10(s32 arg0);
extern "C" void func_002A5DC0(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void MInputTextFace__left(void) {
    struct Buf00109C40 buf;

    func_002A5E18(&buf);
    func_002A7B10(buf.unk0);
    func_002A5DC0(&buf, 2);
}
