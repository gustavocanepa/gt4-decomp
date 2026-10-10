typedef int s32;

struct Buf { char b[0x1E0]; };
extern "C" void func_00449440(void *, s32, Buf *);
extern "C" void func_00449600(void *, Buf *, s32);

extern "C" void func_004493F8(void *self, s32 a, s32 b) {
    Buf buf;
    func_00449440(self, a, &buf);
    func_00449600(self, &buf, b);
}
