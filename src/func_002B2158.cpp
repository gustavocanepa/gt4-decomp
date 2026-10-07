typedef int s32;

struct Obj {
    char pad[0xB0];
    s32 unkB0;
    char pad2[0x11C - 0xB0 - 4];
    s32 unk11C;
};

extern "C" s32 func_0025B370(s32 arg0);
extern "C" s32 func_0025B370(s32 arg0);

extern "C" s32 func_002B2158(Obj *arg0) {
    s32 cond = arg0->unkB0;
    s32 val = arg0->unk11C;
    if (cond == 0) {
        return func_0025B370(val);
    }
    return func_0025B370(val);
}
