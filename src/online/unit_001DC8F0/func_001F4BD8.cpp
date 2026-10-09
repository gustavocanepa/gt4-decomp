extern char D_00645570[];
extern char D_006959D0[];
extern "C" void func_005A6AB0(char *, const char *, int);
extern int func_004F5F38(void *, void *);
extern void func_00215298(int);
extern void func_001F1368(void *);

struct Request {
    int pad[11];
    int a2C;
    int a30;
    int a34;
    char name[0x40];
    char text[0x20];
    int pad98[8];
    int b8;
    int bc;
    int c0;
    int c4;
    int c8;
    int padCC[5];
};

void func_001F4BD8(void *ctx, const char *name, const char *text)
{
    Request req;

    req.a2C = 1;
    req.a30 = 6;
    req.a34 = 1;
    req.b8 = 1;
    req.bc = 1;
    req.c0 = 0;
    req.c4 = 2;
    req.c8 = 0;
    func_005A6AB0(req.name, name, 0x40);
    func_005A6AB0(req.text, text ? text : D_006959D0, 0x20);
    while (!func_004F5F38(D_00645570, &req))
        func_00215298(1);
    func_001F1368(ctx);
}
