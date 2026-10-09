typedef int s32;

struct Obj_001C6D78 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" void func_001C6D78(struct Obj_001C6D78 *arg0, s32 arg1) {
    s32 v1 = arg0->unk4;

    if (v1 >= 0) {
        v1 = v1 + 1;
        if (v1 >= arg0->unk0) {
            v1 = 0;
            if (arg1 == 0) {
                v1 = -1;
                arg0->unk8 = 1;
            }
        }
        arg0->unk4 = v1;
    }
}
