typedef int s32;

extern "C" s32 func_0043C170(s32 arg0);
extern "C" s32 func_0043C608(s32 arg0, s32 arg1);
extern "C" s32 func_0043C8F0(s32 arg0, s32 arg1);
extern "C" s32 func_0043CC10(s32 arg0, s32 arg1);

extern "C" s32 func_0043D8A8(s32 arg0) {
    s32 s0 = arg0;
    s32 v0;

    v0 = func_0043C170(s0 + 0x18);
    v0 = func_0043C608(s0 + 0x48, v0);
    v0 = func_0043C8F0(s0 + 0x64, v0);
    return func_0043CC10(s0 + 0x8C, v0);
}
