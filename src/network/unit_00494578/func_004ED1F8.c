/* compiler: ee-gcc2.96-no-strict-aliasing */
int func_005B68D0(const char *);
void func_00577340(void *, const char *, int, void *, void *);
int func_00577198(void *);
int func_00577878(void *, void *, int, int);
void func_005778F8(void *, void *);
void func_00577948(void *);
void func_00577910(void *, int);
void func_00578148(void *, int);

extern char D_006C0238[];   /* "PDI_NETCNF" */
extern char D_006C0248[];   /* "pdinetcnf.irx" */
extern char D_00655880[];
extern int D_00645434;
extern int D_00645438;
extern char D_00851190[];
extern char D_008511E0[];
extern int D_006182B4;
extern int D_006182B8;

typedef struct {
    char pad[0x3C];
    int opened;
} Netcnf;

void func_004ED1F8(Netcnf *n) {
    char loader[0x10];

    if (func_005B68D0(D_006C0238) < 0) {
        if (!D_00645434) {
            func_00577340(D_00851190, D_006C0248, 0, D_00655880, D_00655880);
            func_00577198(D_00851190 + 0x28);
            D_00645434 = 1;
        }
        if (!D_00645438) {
            func_00577878(D_008511E0, D_00851190, D_006182B4, D_006182B8);
            func_00577878(D_008511E0 + 0xC, 0, 0, 0);
            D_00645438 = 1;
        }
        func_005778F8(loader, D_008511E0);
        func_00577948(loader);
        func_00577910(loader, 2);
    }
    func_00578148(n, 0x504E4346);
    n->opened = 1;
}
