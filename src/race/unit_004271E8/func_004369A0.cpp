typedef int s32;

struct Obj {
    char pad[0x10D0];
    s32 unk10D0;
    s32 unk10D4;
};

extern "C" s32 func_00436930(s32 arg0, s32 arg1);

extern "C" s32 func_004369A0(struct Obj *arg0) {
    return func_00436930(arg0->unk10D4, arg0->unk10D0);
}
