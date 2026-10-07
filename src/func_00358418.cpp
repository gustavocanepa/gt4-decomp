struct D_Struct {
    char pad[0xF89C];
    unsigned int val;
};

extern "C" unsigned int func_00358418(D_Struct *arg0) {
    return arg0->val / 3u;
}
