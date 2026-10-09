typedef int s32;

struct Node {
    s32 unk0;
    void *unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" char __class_type_info__vtable[];

extern "C" void func_005BFB40(struct Node *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != 0) {
        arg0->unk0 = arg1;
        arg0->unk4 = __class_type_info__vtable;
        arg0->unk8 = arg2;
        arg0->unkC = arg3;
    }
}
