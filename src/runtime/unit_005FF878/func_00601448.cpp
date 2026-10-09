typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
};

extern "C" struct Obj *func_00601448(struct Obj *arg0, s32 arg1) {
    arg0->unk0 = arg1;
    arg0->unk4 = 0x3E8;
    return arg0;
}
