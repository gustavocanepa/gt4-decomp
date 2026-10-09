extern "C" {
int func_00531618(int arg0, int arg1);
int func_00535780(int arg0);
int func_00536CF8(void);
int func_00536D38(void);

int func_0052F6F0(int arg0, int arg1) {
    int s0 = arg0;
    int s1 = arg1;
    int v0 = func_00535780(func_00536CF8());
    if (v0 == 0) {
        int t0 = func_00531618(s0, s1);
        int t1 = func_00535780(func_00536D38());
        v0 = (t1 == 0) ? t0 : t1;
    }
    return v0;
}
}
