typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00232C78(struct Buf00109C40 *arg0);
extern "C" void func_002355E0(s32 arg0);
extern "C" void func_00232C20(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00233380(void) {
    struct Buf00109C40 buf;

    func_00232C78(&buf);
    func_002355E0(buf.unk0);
    func_00232C20(&buf, 2);
}
