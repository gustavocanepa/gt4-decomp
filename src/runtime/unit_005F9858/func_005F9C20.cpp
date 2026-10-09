typedef int s32;

struct S003A4D80;

extern "C" void func_003A4D80(S003A4D80 *arg0, s32 arg1, s32 arg2);

struct Obj {
    char pad[0x3C];
};

extern "C" void func_005F9C20(Obj *arg0, s32 arg1) {
    func_003A4D80((S003A4D80 *)(arg0 + 1), arg1, 0);
}
