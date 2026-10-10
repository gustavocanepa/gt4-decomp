typedef unsigned short u16;

struct Node {
    u16 flag : 1;
};

extern "C" void func_004CA610(void *, Node *, int);
extern "C" void func_004CA938(void *, Node *);

extern "C" void func_004CA9F8(void *ctx, Node *n) {
    if (n->flag)
        func_004CA610(ctx, n, 0);
    func_004CA938(ctx, n);
}
