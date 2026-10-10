/* compiler: ee-gcc2.9-991111 */
struct SemaParam {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    unsigned int attr;
    unsigned int option;
};

extern int D_00658348;
extern int D_0065834C;
extern char D_006D2600[];
extern char D_006D2610[];
extern int func_005ADCA0(struct SemaParam *p); /* CreateSema */

void func_005B20E0(void)
{
    struct SemaParam p;

    if (D_00658348 == -1) {
        p.initCount = 1;
        p.maxCount = 1;
        p.option = (unsigned int)D_006D2600;
        D_00658348 = func_005ADCA0(&p);
        p.option = (unsigned int)D_006D2610;
        D_0065834C = func_005ADCA0(&p);
    }
}
