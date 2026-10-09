void func_004EF9F0(void *, int);
void func_004ED050(void *);
void func_004ED1F8(void *);
int func_004ED410(void *, const char *);
int func_004EF6B0(void *, int);
void func_004ED0C0(void *, int);

/* A PdiNetcnf object (constructor func_004ED050, destructor func_004ED0C0). */
typedef struct {
    char pad[0x60];
    int index;
    char pad64[0x0C];
} PdiNetcnf;

int func_004EEE70(void *self, const char *name) {
    PdiNetcnf netcnf;
    int result;

    func_004EF9F0(self, 1);
    func_004ED050(&netcnf);
    func_004ED1F8(&netcnf);
    if (func_004ED410(&netcnf, name) < 0) {
        func_004ED0C0(&netcnf, 2);
        return 0;
    }
    result = func_004EF6B0(self, netcnf.index) >= 0;
    func_004ED0C0(&netcnf, 2);
    return result;
}
