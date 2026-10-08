typedef int s32;

struct Obj {
    s32 unk0;
    char pad[0x18 - 4];
    s32 unk18;
};

extern "C" void func_0042A260(struct Obj *arg0, s32 arg1) {
    s32 temp_v1 = arg0->unk0;
    s32 temp_a2 = arg0->unk18;
    arg0->unk0 = (temp_v1 == 0) ? 0 : (temp_v1 + arg1);
    arg0->unk18 = (temp_a2 == 0) ? 0 : (temp_a2 + arg1);
}
