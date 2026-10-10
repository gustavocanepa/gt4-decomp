struct Obj;

extern "C" char *func_005ADA50(Obj *arg0);

extern "C" void func_005AE940(Obj *arg0) {
    func_005ADA50(arg0);
    __asm__ volatile("sync");
}
