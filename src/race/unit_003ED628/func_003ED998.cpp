typedef int s32;

extern "C" s32 func_003ED6F0(void);
extern "C" void free(s32 arg0);
extern "C" void func_003ED710(void *arg0);

extern char D_00621F78[];
extern s32 D_00621F74;

extern "C" void func_003ED998(void) {
    free(func_003ED6F0());
    func_003ED710(D_00621F78);
    D_00621F74 = 0;
}
