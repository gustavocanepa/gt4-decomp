extern "C" {
int func_005354B8(int arg0);
int func_00535780(int arg0);
int func_00536CF8(void);
int func_00536D38(void);

int func_0052FBD8(int arg0) {
    int s0 = arg0;
    int v0 = func_00535780(func_00536CF8());
    if (v0 == 0) {
        int t0 = func_005354B8(s0);
        int t1 = func_00535780(func_00536D38());
        v0 = (t1 == 0) ? t0 : t1;
    }
    return v0;
}
}
