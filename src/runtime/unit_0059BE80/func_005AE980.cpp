struct Obj;

extern "C" char *func_005ADA70(Obj *arg0);

extern "C" void func_005AE980(Obj *arg0) {
    func_005ADA70(arg0);
    __asm__ volatile("sync");
}
