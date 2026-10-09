typedef int s32;

struct Obj001FE288 {
    char pad[0xE0];
    s32 unkE0;
};

extern "C" void func_001FE2B8(struct Obj001FE288 *arg0, s32 arg1, s32 arg2);

extern "C" void func_001FE288(struct Obj001FE288 *arg0, s32 arg1) {
    s32 v0 = arg0->unkE0;

    arg0->unkE0 = v0 + 1;
    func_001FE2B8(arg0, arg1, v0 < 1);
}
