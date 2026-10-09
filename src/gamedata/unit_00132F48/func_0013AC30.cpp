typedef int s32;

struct Obj {
    char pad[0x2A0];
    s32 unk2A0;
};

extern "C" s32 func_0013AC30(Obj *arg0) {
    return *(s32 *)(0x618890 + (arg0->unk2A0 * 4));
}
