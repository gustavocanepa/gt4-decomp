typedef int s32;

struct Obj {
    char pad[0xD0];
    s32 unkD0;
};

extern "C" void func_002DFA10(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_002DF968(Obj *arg0, s32 arg1) {
    func_002DFA10((s32)arg0, arg0->unkD0, arg1);
}
