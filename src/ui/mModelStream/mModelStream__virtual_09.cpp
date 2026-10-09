typedef int s32;

struct Obj {
    char pad[8];
    s32 unk8;
};

extern "C" int func_0021CC38(void) throw();

extern "C" void mModelStream__virtual_09(struct Obj *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_0021CC38();
    }
}
