struct S00541150 {
    char pad[0x8C18];
    int unk8C18;
};

extern "C" int func_00541150(S00541150 *arg0, int arg1) {
    int var_v0;

    var_v0 = 2;
    if (arg0 != 0) {
        arg0->unk8C18 = arg1;
        var_v0 = 0;
    }
    return var_v0;
}
