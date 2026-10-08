typedef int s32;

struct Obj {
    char pad[0xE408];
    s32 unkE408;
};

extern "C" void func_0038B990(struct Obj *arg0, s32 arg1);

extern "C" void func_005F6B50(struct Obj *arg0) {
    func_0038B990(arg0, arg0->unkE408);
}
