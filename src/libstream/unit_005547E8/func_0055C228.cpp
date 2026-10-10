typedef int s32;

extern "C" void func_006117B8(void *, void *, s32);
extern "C" void func_00611828(void *, void *, s32);

extern "C" void func_0055C228(char *self) {
    func_006117B8(self, self, 12);
    func_00611828(self, self + 0x540, 2);
}
