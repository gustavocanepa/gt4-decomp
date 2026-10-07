typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00137DB8(struct Buf00109C40 *arg0);
extern "C" void func_0013A470(s32 arg0);
extern "C" void func_00137D60(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00138F50(void) {
    struct Buf00109C40 buf;

    func_00137DB8(&buf);
    func_0013A470(buf.unk0);
    func_00137D60(&buf, 2);
}
