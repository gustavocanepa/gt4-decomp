typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" void func_004D65F0(Obj *arg0, Obj *arg1) {
    s32 temp_v1 = arg1->unk0;
    arg0->unk0 = temp_v1;
    arg0->unk4 = temp_v1 + (arg1->unk8 * 4);
}
