extern "C" int func_004485B8(void);
extern "C" void func_004485D0(int index, char *name, int size);
extern "C" int func_00433AA0(void *o, char *name);

extern "C" void func_00433A30(void *o) {
    char name[32];
    int n = func_004485B8();
    for (int i = 0; i < n; i++) {
        func_004485D0(i, name, sizeof(name));
        func_00433AA0(o, name);
    }
}
