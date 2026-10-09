typedef void (*FuncPtr)(void);

extern "C" void func_005BCA00(void);

extern FuncPtr D_00659970;

extern "C" void func_005BC918(void) {
    D_00659970 = func_005BCA00;
}
