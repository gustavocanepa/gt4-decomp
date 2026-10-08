extern "C" void func_003B7470(void *arg0);
extern "C" void func_00576090(void);
extern "C" char D_0067FC40[];

extern "C" void func_003B73D0(void *arg0) {
    *(void **)((char *)arg0 + 0x828) = D_0067FC40;
    func_00576090();
    return func_003B7470(arg0);
}
