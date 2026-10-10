typedef int s32;

struct DoubleBuf {
    s32 buf[2];
    s32 arg;
    s32 cur;
};

extern DoubleBuf D_006184C0;
extern "C" void func_004A1A00(s32, s32);
extern "C" void func_004A1BB0(void);

extern "C" void func_001077F8(void) {
    D_006184C0.cur = 1 - D_006184C0.cur;
    func_004A1A00(D_006184C0.buf[D_006184C0.cur], D_006184C0.arg);
    func_004A1BB0();
}
