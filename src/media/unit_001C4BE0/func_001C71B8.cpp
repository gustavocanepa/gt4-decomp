typedef int s32;

struct Obj {
    char pad[0xBCC];
    s32 unkBCC;
};

extern "C" void *func_001C71B8(char *arg0) {
    s32 temp_v1 = ((Obj *)arg0)->unkBCC;
    void *var_v0 = 0;

    if (temp_v1 >= 0) {
        var_v0 = arg0 + temp_v1 * 0x2B8 + 0x64C;
    }
    return var_v0;
}
