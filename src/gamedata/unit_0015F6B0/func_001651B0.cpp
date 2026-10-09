typedef int s32;

struct Obj { char pad[0x10]; char *p10; };

extern "C" s32 *func_0015F3E0(s32 *arg0);
extern "C" void func_001C0E78(s32 *arg0, void *arg1);
extern "C" void func_001BFE50(s32 *arg0, int arg1);
extern "C" void func_0015F388(s32 *arg0, int arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_001651B0(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1 = buf1;
    s32 newVal;
    s32 oldVal;

    func_0015F3E0(p1);
    func_001C0E78(buf0, ((Obj *)*p1)->p10 + 0x38960);
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
    func_001BFE50(buf0, 2);
    func_0015F388(p1, 2);
}
