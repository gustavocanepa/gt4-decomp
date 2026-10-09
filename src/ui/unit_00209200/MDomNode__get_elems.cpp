typedef int s32;

extern "C" void func_00208F70(s32 *arg0);
extern "C" void func_00209928(s32 *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" void func_002ED5C0(s32 *arg0, s32 arg1);
extern "C" void func_00208F18(s32 *arg0, s32 arg1);

extern "C" void MDomNode__get_elems(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1 = buf1;
    s32 newVal;
    s32 oldVal;

    func_00208F70(p1);
    func_00209928(buf0, *p1);
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_002ED5C0(buf0, 2);
    func_00208F18(p1, 2);
}
