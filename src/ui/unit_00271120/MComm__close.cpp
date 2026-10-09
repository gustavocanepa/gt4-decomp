typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00270F20(struct Buf00109C40 *arg0);
extern "C" void func_00271E40(s32 arg0);
extern "C" void func_00270EC8(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void MComm__close(void) {
    struct Buf00109C40 buf;

    func_00270F20(&buf);
    func_00271E40(buf.unk0);
    func_00270EC8(&buf, 2);
}
