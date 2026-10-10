struct Obj;

extern "C" char *func_005ADA40(Obj *arg0);

extern "C" void func_005AE920(Obj *arg0) {
    func_005ADA40(arg0);
    __asm__ volatile("sync");
}
