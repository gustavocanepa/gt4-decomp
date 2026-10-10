struct Obj;

extern "C" char *func_005ADA60(Obj *arg0);

extern "C" void func_005AE960(Obj *arg0) {
    func_005ADA60(arg0);
    __asm__ volatile("sync");
}
