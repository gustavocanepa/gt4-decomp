typedef int s32;

struct Obj {
    char pad[8];
    s32 unk8;
};

extern "C" int func_00254260(void) throw();

extern "C" void func_00254270(struct Obj *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00254260();
    }
}
