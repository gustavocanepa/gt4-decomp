typedef int s32;

extern char D_00621200[];
extern char D_00621228[];

extern "C" void *func_0037CDD8(s32 arg0, s32 arg1) {
    char *var_v0;

    var_v0 = D_00621200;
    if (arg1 != 0) {
        var_v0 = D_00621228;
    }
    return var_v0 + (arg0 * 8);
}
