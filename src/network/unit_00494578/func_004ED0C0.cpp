extern "C" {
void free(int);
int func_005B6638(int, int, int, void *);
int func_005B6840(int);
int func_005B68D0(const char *);
extern char D_006C0238[];
extern char D_006895B8[];
}

/* The base class: its destructor is func_00578090 (named after it so the mangled _$_13func_00578090
   resolves). A real C++ destructor is needed: g++ 2.96 appends `if (in_chrg & 1)
   func_005C1628(this)` itself, and only that tail gives the non-likely beqz with the epilogue's
   `ld $s0` stolen into its delay slot; the same test written in C gives beql. */
struct func_00578090 {
    char pad[0x38];
    ~func_00578090();
};

struct PdiNetcnf : func_00578090 {
    char *vtable;
    int opened;
    int handles[5];
    ~PdiNetcnf();
};

PdiNetcnf::~PdiNetcnf() {
    char buf[0x10];

    vtable = D_006895B8;
    free(handles[0]);
    if (handles[1] != 0) free(handles[1]);
    if (handles[2] != 0) free(handles[2]);
    if (handles[3] != 0) free(handles[3]);
    if (handles[4] != 0) free(handles[4]);
    if (opened != 0) {
        int h = func_005B68D0(D_006C0238);
        func_005B6638(h, 0, 0, buf);
        func_005B6840(h);
    }
}
