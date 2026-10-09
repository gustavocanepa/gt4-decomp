typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_002AE9C0(struct Buf00109C40 *arg0);
extern "C" void func_002B5668(s32 arg0);
extern "C" void func_002AE968(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void MListBox__postRedraw(void) {
    struct Buf00109C40 buf;

    func_002AE9C0(&buf);
    func_002B5668(buf.unk0);
    func_002AE968(&buf, 2);
}
