typedef int s32;

extern s32 D_006214CC;
extern char D_006214B0[];
extern "C" void *func_00463840(char *);
extern "C" void func_00575DA0(void *);

extern "C" void func_00394B80(void) {
    if (D_006214CC != 0) {
        func_00575DA0(func_00463840(D_006214B0));
    }
    D_006214CC = 0;
}
