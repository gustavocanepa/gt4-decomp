struct Date { int w[8]; };
struct Rec { unsigned long long stamp; };

extern "C" int func_00445808(Rec *r);
extern "C" void func_00448820(unsigned long long stamp, Date *out);
extern "C" int func_004489A0(Date *d, int flag);

extern "C" int func_00445828(Rec *r)
{
    int n = func_00445808(r);
    Date d;
    func_00448820(r->stamp, &d);
    if (func_004489A0(&d, 1))
        n--;
    return n;
}
