typedef int s32;

extern "C" {
s32 func_00535268(void);
s32 func_00535780(s32 arg0);
s32 func_00536CF8(void);
s32 func_00536D38(void);

s32 func_0052FB28(void) {
    s32 v0 = func_00535780(func_00536CF8());
    if (v0 == 0) {
        s32 t0 = func_00535268();
        s32 t1 = func_00535780(func_00536D38());
        v0 = (t1 == 0) ? t0 : t1;
    }
    return v0;
}
}
