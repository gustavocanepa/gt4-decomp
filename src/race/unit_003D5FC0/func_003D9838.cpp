typedef int s32;

extern "C" s32 func_003D8C18(void *) throw();
extern "C" s32 func_003D9D88(void *);
extern "C" s32 func_003D9DB0(void *);
extern "C" s32 func_003D9DD8(void *);
extern "C" s32 func_003D9E30(void *);
extern "C" s32 func_00426AF8(s32);

extern "C" void func_003D9838(char *self, s32 id) {
    s32 flags;
    s32 state;

    flags = func_00426AF8(id);
    if (flags & 0x3000C) {
        state = 3;
        if (func_003D8C18(self) != 0) {
            if (flags & 4) {
                state = (func_003D9DB0(self) != 0) ? 2 : 3;
            }
            if (flags & 8) {
                state = (func_003D9D88(self) != 0) ? 2 : state;
            }
            if (flags & 0x10000) {
                state = (func_003D9DD8(self) != 0) ? 6 : state;
            }
            if (flags & 0x20000) {
                state = (func_003D9E30(self) != 0) ? 6 : state;
            }
        }
        *(s32 *)(self + 0x9C) = state;
    }
}
