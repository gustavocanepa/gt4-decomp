typedef int s32;

struct Obj001D0338 {
    char pad0[0x14C];
    s32 unk14C;
};

extern char D_00618D30[];
extern char D_00618D40[];

extern "C" s32 func_001D03C0(struct Obj001D0338 *arg0) {
    if (arg0->unk14C != 0) {
        return (s32)D_00618D30;
    }
    return (s32)D_00618D40;
}
