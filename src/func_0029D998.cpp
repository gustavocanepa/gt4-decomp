typedef int s32;

struct Buf0029D998 {
    void *unk0;
    char pad[0xC];
};

extern "C" void func_0029D4F0(struct Buf0029D998 *arg0);
extern "C" void func_0029DEF8(s32 arg0);
extern "C" void func_0029D498(struct Buf0029D998 *arg0, int arg1);

extern "C" void func_0029D998(s32 arg0, s32 arg1, s32 arg2) {
    struct Buf0029D998 buf;

    if (arg2 > 0) {
        func_0029D4F0(&buf);
        func_0029DEF8((s32)buf.unk0);
        func_0029D498(&buf, 2);
    }
}
