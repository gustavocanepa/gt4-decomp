int func_004F1BA0(void *, void *);
void func_00215298(int);
void func_001F1368(void *);

extern char D_00645570[];

typedef struct {
    int pad[6];
    int timeout;
    int a;
    int b;
    int c;
    int d;
    int size;
} WaitParams;

void func_001F29A8(void *self) {
    WaitParams params;

    params.timeout = 0x7FFFFFFF;
    params.a = -1;
    params.b = -1;
    params.c = -1;
    params.d = 0;
    params.size = 0x40;
    while (func_004F1BA0(D_00645570, &params) == 0) {
        func_00215298(1);
    }
    func_001F1368(self);
}
