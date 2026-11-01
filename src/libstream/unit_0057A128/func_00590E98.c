/* compiler: ee-gcc2.9-991111 */
/* sceSifMUnbindRpc (Mrpc client): sends command 0x8000001D for the bound client and waits on a
   fresh semaphore; returns the status the request-end handler stored. The first read of cl->sema
   is volatile (its load stays out of the jal slot) while the later one is not. */
struct Srv { int p0; int p4; int p8; int pc; int p10; int self; int p18; int cl; int rpc; int ssize; };
struct Cl { int srv; int v4; volatile int sema8; int pc; int v10; int p14; int gp; int func; int arg; int v24; int sema; volatile int status; };
struct Sema { int a; int max; int init; int d; int e; int opt; };
extern void func_005B0750(const char *, ...);
extern int func_005ADCA0(struct Sema *);
extern int func_005ADCB0(int);
extern int func_005ADCE0(int);
extern char D_00885AC0[];
extern char D_006CF6E8[];
extern struct Srv *func_00590AB8(char *);
extern void func_00590B60(struct Srv *);
extern int func_005B0DB0(int, struct Srv *, int, int, int, int);
int func_00590E98(struct Cl *cl, int mode)
{
    struct Sema sp;
    struct Srv *s;
    int sem;
    if (mode != 0) {
        func_005B0750("mode must be 0 in this version.\n");
        return -1;
    }
    func_005ADCE0(*(volatile int *)&cl->sema);
    s = func_00590AB8(D_00885AC0);
    if (s == 0) return -1;
    cl->v4 = s->p18;
    cl->srv = (int)s;
    s->self = (int)s;
    s->rpc = cl->v10;
    s->cl = (int)cl;
    s->ssize = cl->v24;
    sp.init = 0; sp.max = 1; sp.opt = (int)D_006CF6E8;
    cl->sema8 = func_005ADCA0(&sp);
    sem = cl->sema8;
    if (sem < 0) {
        func_00590B60(s);
        return -3;
    }
    if (func_005B0DB0(0x8000001D, s, 0x40, 0, 0, 0) == 0) {
        func_00590B60(s);
        func_005ADCB0(sem);
        return -2;
    }
    func_005ADCE0(sem);
    func_005ADCB0(sem);
    if (cl->status == 1) func_005ADCB0(cl->sema);
    return cl->status;
}
