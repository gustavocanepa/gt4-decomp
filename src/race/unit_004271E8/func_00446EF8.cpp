typedef int s32;

extern "C" s32 func_00443ED0(void *arg0, s32 arg1, void *arg2);
extern "C" char *func_00443E60(void *arg0, s32 arg1);
extern "C" void func_005A609C(void *arg0, const char *arg1);
extern char D_006235A8[];

extern "C" void func_00446EF8(s32 arg0, void *arg1) {
    char buf[0x10];

    if (arg0 != -1 && func_00443ED0(D_006235A8, arg0, buf) != 0) {
        func_005A609C(arg1, func_00443E60(D_006235A8, arg0));
    }
}
