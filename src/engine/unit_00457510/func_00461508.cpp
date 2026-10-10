extern char D_008468E8[]; /* mutex */
extern "C" int func_00461448(void *obj);
extern "C" void func_00576788(void *mutex);
extern "C" void func_005767C0(void *mutex);
extern "C" void func_004613F0(int index);

extern "C" void func_00461508(void *obj) {
    int index = -1;
    if (obj)
        index = func_00461448(obj);
    if (index >= 0) {
        func_00576788(D_008468E8);
        func_004613F0(index);
        func_005767C0(D_008468E8);
    }
}
