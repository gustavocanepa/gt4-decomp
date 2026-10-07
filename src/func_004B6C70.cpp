typedef int s32;

struct Obj4B6C70 {
    char pad[0x1C];
    s32 unk1C;
};

extern "C" s32 func_004B6C70(Obj4B6C70 *arg0, s32 arg1) {
    arg0->unk1C = (s32)(arg1 == 0);
    return 1;
}
