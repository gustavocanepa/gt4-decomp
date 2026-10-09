typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad[0x1];
    u8 unk1;
    u8 unk2;
};

extern "C" s32 func_0035A058(Obj *arg0) {
    s32 var_v0 = 1;

    if (arg0->unk2 == 1) {
        return var_v0;
    }
    var_v0 = arg0->unk1 == 6;
    return var_v0;
}
