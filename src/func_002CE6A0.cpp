typedef int s32;

struct Obj {
    char pad[8];
    s32 unk8;
};

extern "C" int func_002CE690(void) throw();

extern "C" void func_002CE6A0(struct Obj *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_002CE690();
    }
}
