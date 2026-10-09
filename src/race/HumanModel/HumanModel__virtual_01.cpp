typedef int s32;

struct Obj_003B0FF0 {
    s32 unk0;
    char pad[0x6B0 - 4];
    s32 *unk6B0;
};

extern "C" void func_004573B8(s32 arg0, s32 *arg1, struct Obj_003B0FF0 *arg2);

extern "C" void HumanModel__virtual_01(struct Obj_003B0FF0 *arg0) {
    s32 *temp_a0;

    if (arg0->unk0 != 0) {
        temp_a0 = arg0->unk6B0;
        if (temp_a0 != 0) {
            func_004573B8(*temp_a0, temp_a0, arg0);
        }
    }
}
