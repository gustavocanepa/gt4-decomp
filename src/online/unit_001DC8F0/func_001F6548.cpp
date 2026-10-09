extern char D_00645570[];
extern char D_006959D0[];
extern "C" char *func_005A609C(char *, const char *);
extern "C" void func_005A6AB0(char *, const char *, int);
extern int func_00500750(void *, void *);
extern void func_00215298(int);
extern void func_001F1368(void *);

struct GameRequest {
    char pad[0x15];
    char name[0x40];
    char description[0x100];
    char password[0x27];
    int a;
    int b;
    int c;
    int d;
    int e;
    int f190;
    int f194;
    int f198;
    char pad19C[0x34];
    int f1D0;
    int pad1D4[3];
};

void func_001F6548(void *ctx, const char *name, const char *password, const char *description,
                   int a, int b, int c, int d, int e)
{
    GameRequest req;

    func_005A609C(req.name, name);
    func_005A609C(req.password, password ? password : D_006959D0);
    func_005A6AB0(req.description, description ? description : D_006959D0, 0x100);
    req.a = a;
    req.b = b;
    req.c = c;
    req.d = d;
    req.e = e;
    req.f1D0 = 1;
    req.f190 = 0;
    req.f194 = 0;
    req.f198 = 0;
    while (!func_00500750(D_00645570, &req))
        func_00215298(1);
    func_001F1368(ctx);
}
