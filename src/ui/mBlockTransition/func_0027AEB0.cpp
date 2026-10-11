typedef int s32;

struct Obj0027AEB0 {
    char pad[0x38];
    s32 unk38;
};

extern "C" void free(s32 arg0);

extern "C" void func_0027AEB0(struct Obj0027AEB0 *arg0) {
    s32 temp_v0 = arg0->unk38;

    if (temp_v0 != 0) {
        arg0->unk38 = 0;
        free(temp_v0);
    }
}
