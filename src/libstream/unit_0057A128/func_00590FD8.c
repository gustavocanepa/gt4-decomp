/* compiler: ee-gcc2.9-991111 */
/* sceSifMCallRpc (Mrpc client): checks the 64-byte alignment of both buffers, fills a request
   packet from func_00590AB8, writes back the data cache and sends command 0x8000001A, waiting on
   a fresh semaphore unless mode bit 1 asks for a callback. Packet fields are ints (the stores keep
   source order only when they may alias the int-typed gp slot). */
struct Srv { int p0; int p4; int p8; int pc; int p10; int self; int p18; int cl; int rpc; int ssize; int recv; int rsize; int wait; int cmd; };
struct Cl { struct Srv *srv; int v4; int sema8; int pc; int v10; int p14; int gp; void (*func)(void *); void *arg; int v24; int sema; };
struct Sema { int a; int max; int init; int d; int e; const char *opt; };
extern void func_005B0750(const char *, ...);
extern int func_005ADCA0(struct Sema *);
extern int func_005ADCB0(int);
extern int func_005ADCE0(int);
extern char D_00885AC0[];
extern char D_006CF6F8[];
extern char D_006CF730[];
extern char D_006CF740[];
extern char D_006CF778[];
extern struct Srv *func_00590AB8(char *);
extern void func_00590B60(struct Srv *);
extern int func_005B0DB0(int, struct Srv *, int, void *, int, int);
extern void func_005B0F78(void *, int);
static __inline__ void *GetGP(void) { int gp; __asm__ volatile("move %0, $28" : "=r"(gp)); return gp; }
int func_00590FD8(struct Cl *cl, int rpc, int mode, void *send, int ssize, void *recv, int rsize,
                  void (*func)(void *), void *arg)
{
    struct Sema sp;
    struct Srv *s;
    int sem;
    if (mode != 0) {
        func_005B0750("mode must be 0 in this version.\n");
        return -1;
    }
    func_005ADCE0(cl->sema);
    if ((int)send & 0x3F) {
        func_005B0750(D_006CF6F8, D_006CF730, send);
        return -1;
    }
    if ((int)recv & 0x3F) {
        func_005B0750(D_006CF740, D_006CF730, recv);
        return -1;
    }
    s = func_00590AB8(D_00885AC0);
    if (s == 0) return -1;
    cl->arg = arg;
    cl->v4 = s->p18;
    cl->srv = s;
    cl->func = func;
    cl->gp = GetGP();
    s->rpc = rpc;
    s->self = (int)s;
    s->ssize = ssize;
    s->recv = (int)recv;
    s->rsize = rsize;
    s->cl = (int)cl;
    s->cmd = cl->v24;
    if (send == recv) {
        func_005B0F78(send, ssize < rsize ? rsize : ssize);
    } else {
        if (ssize > 0) func_005B0F78(send, ssize);
        if (rsize > 0) func_005B0F78(recv, rsize);
    }
    if (mode & 1) {
        if (func == 0) s->wait = 0;
        else s->wait = 1;
        cl->sema8 = -1;
        if (func_005B0DB0(0x8000001A, s, 0x40, send, cl->p14, ssize) == 0) {
            func_00590B60(s);
            return -2;
        }
        return 0;
    }
    sp.init = 0; sp.max = 1; sp.opt = D_006CF778;
    sem = func_005ADCA0(&sp);
    cl->sema8 = sem;
    if (sem < 0) {
        func_00590B60(s);
        return -3;
    }
    s->wait = 1;
    if (func_005B0DB0(0x8000001A, s, 0x40, send, cl->p14, ssize) == 0) {
        func_00590B60(s);
        func_005ADCB0(sem);
        return -2;
    }
    func_005ADCE0(sem);
    func_005ADCB0(sem);
    return 0;
}
