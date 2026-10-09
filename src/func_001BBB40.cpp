typedef int s32;

struct Obj {
    char pad[8];
    s32 unk8;
};

extern "C" int func_001BBB30(void) throw();

extern "C" void func_001BBB40(struct Obj *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_001BBB30();
    }
}
