typedef int s32;

struct Obj001C71E0 {
    char pad[0xBC8];
    s32 unkBC8;
};

extern "C" void *func_001C71E0(char *arg0) {
    s32 temp_v1 = ((struct Obj001C71E0 *)arg0)->unkBC8;
    void *var_v0 = 0;

    if (temp_v1 >= 0) {
        var_v0 = arg0 + temp_v1 * 0x2B8 + 0x64C;
    }
    return var_v0;
}
