typedef void (*FuncPtr)(int);

extern "C" FuncPtr func_002EAA10();

extern "C" int func_002EB758(int arg0, int arg1, int arg2)
{
    FuncPtr fn = func_002EAA10();
    if (fn != 0) {
        fn(arg2);
        return 1;
    }
    return (int)fn;
}
