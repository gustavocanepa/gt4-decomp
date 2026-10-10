typedef int s32;

extern "C" s32 func_00471F90(s32 *a) {
    s32 i;
    for (i = 0; i < 6; i++) {
        s32 v = a[i];
        if (v != 1 && v != 2 && v != 4) return 0;
    }
    return 1;
}
