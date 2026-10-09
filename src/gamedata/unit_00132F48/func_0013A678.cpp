typedef int s32;

extern "C" void func_0025A7E0(void *buf, void *arg1);
extern "C" void func_0026AC20(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern "C" void func_0026A118(void *buf, s32 arg1);
extern "C" void func_0021B328(void *buf, void *arg1);
extern "C" void func_00154290(s32 arg0, void *buf);
extern "C" void func_0021B340(void *arg0, s32 arg1);

struct ObjA {
    char pad[0x2A4];
    s32 unk2A4;
};

extern "C" void func_0013A678(ObjA *arg0, s32 arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1 = buf1;

    func_0025A7E0(p1, arg0);
    func_0026AC20(buf0, *p1, arg1, 1, 0, 1);
    func_0026A118(p1, 2);
    if (buf0[0] != 0) {
        func_0021B328(p1, buf0);
        func_00154290(arg0->unk2A4, p1);
    }
    func_0021B340(buf0, 2);
}
