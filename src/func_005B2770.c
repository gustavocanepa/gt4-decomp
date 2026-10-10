/* compiler: ee-gcc2.9-991111 */
struct SemaParam {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    unsigned int attr;
    unsigned int option;
};

extern int D_00658344;
extern char D_006D2688[];
extern int func_005ADCA0(struct SemaParam *param);

void func_005B2770(void) {
    struct SemaParam param;

    if (D_00658344 == -1) {
        param.initCount = 1;
        param.maxCount = 1;
        param.option = (unsigned int)D_006D2688; /* "SceStdioFioSema" */
        D_00658344 = func_005ADCA0(&param);
    }
}
