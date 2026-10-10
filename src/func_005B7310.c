/* compiler: ee-gcc2.9-991111 */
struct SemaParam {
    int count;
    int max_count;
    int init_count;
    int wait_threads;
    unsigned int attr;
    unsigned int option;
};
extern char D_006D28F0[];
extern char D_006D2900[];
extern int D_00658378;
extern int D_0065837C;
int func_005ADCA0(struct SemaParam *p);

void func_005B7310(void)
{
    struct SemaParam p1, p2;

    p1.max_count = 1;
    p1.init_count = 1;
    p1.option = (unsigned int)D_006D28F0;
    p2.max_count = 1;
    p2.init_count = 1;
    p2.option = (unsigned int)D_006D2900;
    D_00658378 = func_005ADCA0(&p1);
    D_0065837C = func_005ADCA0(&p2);
}
