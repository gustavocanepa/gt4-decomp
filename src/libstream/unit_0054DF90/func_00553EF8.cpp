typedef int s32;

extern "C" void func_00553FC8(char *, s32, s32, s32, s32, s32, char *);
extern "C" char *func_00554070(char *);
extern "C" void func_00576788(s32);
extern "C" void func_005767C0(s32);

extern "C" void func_00553EF8(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 lock;
    char *buf;

    lock = (s32)(arg0 + 0x2200);
    func_00576788(lock);
    if (arg6 == 0 && *(s32 *)(arg0 + 0x21C8) == 0) {
        buf = arg0 + 0x2100;
        *(s32 *)(arg0 + 0x21C8) = 1;
    } else {
        buf = func_00554070(arg0);
    }
    if (buf != 0) {
        func_00553FC8(arg0, arg1, arg2, arg3, arg4, arg5, buf);
    }
    func_005767C0(lock);
}
