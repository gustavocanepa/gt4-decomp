typedef int s32;

struct Buf {
    void *ptr;
    char pad[0xC];
};

extern "C" void func_0028BDA8(struct Buf *arg0);
extern "C" void func_0032EE88(void *arg0);
extern "C" void func_0028BD50(struct Buf *arg0, s32 arg1);

extern "C" void func_0028C658(void) {
    struct Buf buf;

    func_0028BDA8(&buf);
    func_0032EE88((char *)buf.ptr + 0x10);
    func_0028BD50(&buf, 2);
}
