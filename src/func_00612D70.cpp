typedef int s32;

struct Pair {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_00572D48(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_00612D70(s32 arg0, struct Pair *arg1) {
    func_00572D48(arg0, arg1->unk0, arg1->unk4);
}
