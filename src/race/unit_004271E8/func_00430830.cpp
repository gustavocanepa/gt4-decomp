typedef int s32;

struct S00430830 {
    char pad[0x54];
    s32 unk54;
    s32 unk58;
};

extern "C" s32 func_00436930(s32 arg0, s32 arg1);

extern "C" s32 func_00430830(S00430830 *arg0) {
    return func_00436930(arg0->unk58, arg0->unk54);
}
