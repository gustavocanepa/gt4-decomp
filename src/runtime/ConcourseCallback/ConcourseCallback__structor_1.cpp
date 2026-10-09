extern "C" void func_004574A0(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *ConcourseCallback__vtable;

extern "C" void ConcourseCallback__structor_1(void *arg0, int arg1) {
    *(void **)arg0 = &ConcourseCallback__vtable;
    func_004574A0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
