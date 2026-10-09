extern "C" void func_003B7470(void *arg0);
extern "C" void func_00576090(void);
extern "C" char RaceEventQueue__vtable[];

extern "C" void RaceEventQueue__structor_0(void *arg0) {
    *(void **)((char *)arg0 + 0x828) = RaceEventQueue__vtable;
    func_00576090();
    return func_003B7470(arg0);
}
