void func_00577F80(void);
extern "C" int func_0058F780(void);
extern "C" void func_00551810(void);
extern "C" void func_0054C430(void);

extern "C" void func_00101970(void) {
    while (func_0058F780() != 1)
        func_00577F80();
    func_00551810();
    func_0054C430();
}
