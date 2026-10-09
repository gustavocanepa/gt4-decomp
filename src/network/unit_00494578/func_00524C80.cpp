typedef int s32;
typedef unsigned short u16;

struct Obj {
    char pad[0x9C];
    u16 unk9C;
};

extern "C" s32 func_00524C80(struct Obj *arg0, s32 *arg1) {
    if (arg1 == 0) {
        return 2;
    }
    *arg1 = 0;
    if (arg0 == 0) {
        return 2;
    }
    *arg1 = arg0->unk9C;
    return 0;
}
