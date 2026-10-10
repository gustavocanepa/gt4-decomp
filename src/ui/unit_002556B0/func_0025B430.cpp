struct C { char pad[0x34]; int f34; };
extern "C" void mWidget__getWindowGeometry(struct C *, int *, int, int, int, int);

extern "C" void func_0025B430(struct C *arg0, int arg1, int arg2) {
    mWidget__getWindowGeometry(arg0, &arg0->f34, arg1, arg2, 0, 0);
}
