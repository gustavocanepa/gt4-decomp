typedef int s32;

struct Obj_00328A00 {
    char pad0[0x38];
    s32 unk38;
};

extern "C" void free(s32 arg0);

extern "C" void func_00328A00(struct Obj_00328A00 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk38;
    if (temp_v0 != 0) {
        free(temp_v0);
    }
    arg0->unk38 = 0;
}
