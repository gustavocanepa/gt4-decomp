struct Info {
    int w[8];
};

extern "C" void *func_00441248(void *o);
extern "C" void *func_004454C0(void *p);
extern "C" int func_00448820(void *p, Info *info);
extern "C" int func_00448990(Info *info);
extern "C" int func_0043F4C8(void *o, int id);

extern "C" bool func_0013F528(void *o) {
    Info info;
    if (!func_00448820(func_004454C0(func_00441248(o)), &info))
        return false;
    bool r;
    if (func_00448990(&info))
        r = true;
    else
        r = func_0043F4C8(o, 0x1C) == 1;
    return r;
}
