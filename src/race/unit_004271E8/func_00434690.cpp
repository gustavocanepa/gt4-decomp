extern "C" int func_0057F238(const char *a, const char *b);
extern const char *D_00622D90[];

extern "C" void func_00434690(int *out, const char *name) {
    for (int i = 0; i < 5; i++) {
        if (func_0057F238(name, D_00622D90[i]) == 0) {
            *out = i;
            return;
        }
    }
    *out = 0;
}
