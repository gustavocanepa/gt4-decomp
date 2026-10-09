typedef int s32;

struct Obj {
    char pad[0x1158];
    s32 unk1158;
};

extern "C" s32 func_00436B50(Obj *arg0) {
    return *(s32 *)(0x622DE0 + (arg0->unk1158 * 4));
}
