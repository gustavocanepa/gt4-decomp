struct C { char pad[0x34]; int f34; };
extern "C" void func_0025BB18(struct C *, int *, int, int, int, int);

extern "C" void func_0025BA38(struct C *arg0, int arg1, int arg2) {
    func_0025BB18(arg0, &arg0->f34, arg1, arg2, 0, 0);
}
