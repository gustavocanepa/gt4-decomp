extern "C" void func_004F8EC0(void *, unsigned int *, int);
extern "C" void func_004F8EE8(void *, unsigned int *, int);
extern "C" void func_004F8F70(void *, unsigned int *, int);
extern "C" void func_004F8FB8(void *, unsigned int *, int);
extern "C" void func_004F9018(void *, unsigned int *, int);
extern "C" void func_004F9078(void *, unsigned int *, int);
extern "C" void func_004F90A0(void *, unsigned int *, int);
extern "C" void func_004F90D0(void *, unsigned int *, int);
extern "C" void func_004F90F8(void *, unsigned int *, int);

extern "C" int func_004F9120(void *arg0, int arg1, int arg2, int arg3, unsigned int *arg4) {
    switch (*arg4) {
    case 0:
        func_004F8EC0(arg0, arg4, arg3);
        return 0xC;
    case 1:
        func_004F8EE8(arg0, arg4, arg3);
        return 0x2C;
    case 2:
        func_004F8F70(arg0, arg4, arg3);
        return 0xC;
    case 3:
        func_004F8FB8(arg0, arg4, arg3);
        return 0x34;
    case 4:
        func_004F9018(arg0, arg4, arg3);
        return 0xC;
    case 5:
        func_004F9078(arg0, arg4, arg3);
        return 0xC;
    case 6:
        func_004F90A0(arg0, arg4, arg3);
        return 0x34;
    case 7:
        func_004F90D0(arg0, arg4, arg3);
        return 8;
    case 8:
        func_004F90F8(arg0, arg4, arg3);
        return 8;
    default:
        return 0;
    }
}
