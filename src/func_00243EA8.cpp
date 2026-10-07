typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_002434C8(struct Buf00109C40 *arg0);
extern "C" void func_00245658(s32 arg0);
extern "C" void func_00243470(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00243EA8(void) {
    struct Buf00109C40 buf;

    func_002434C8(&buf);
    func_00245658(buf.unk0);
    func_00243470(&buf, 2);
}
