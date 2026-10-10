/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair {
    int a;
    int b;
};

extern "C" Pair D_00655878;
extern "C" int func_00577478(int a);

struct func_00577340 {
    Pair m0;
    Pair m8;
    Pair m10;
    int m18;
    int m1C;
    int m20;
    int m24;
    func_00577340(int a, int b, const Pair *p, const Pair *q);
};

func_00577340::func_00577340(int a, int b, const Pair *p, const Pair *q)
    : m0(D_00655878), m8(*p), m10(*q), m18(a), m1C(b), m20(func_00577478(b)), m24(1)
{
}
