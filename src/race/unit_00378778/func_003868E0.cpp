extern "C" int func_0035A458(int b);
extern "C" void func_00401148(int a, int b, int c);
extern "C" void func_00402320(int a, int b, int c);

extern "C" void func_003868E0(int a, int b, int c)
{
    switch (func_0035A458(b)) {
    case 0:
        break;
    case 1:
        return func_00401148(a, b, c);
    }
    return func_00402320(a, b, c);
}
