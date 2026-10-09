typedef int s32;

struct Obj0 {
    char pad[0x48];
    s32 unk48;
};

struct Obj1 {
    void *unk0;
    s32 unk4;
};

extern "C" void func_0055D120(struct Obj0 *arg0, struct Obj1 *arg1) {
    s32 temp_v1 = arg0->unk48;

    if (temp_v1 < arg1->unk4) {
        arg1->unk0 = arg0;
        arg1->unk4 = temp_v1;
    }
}
