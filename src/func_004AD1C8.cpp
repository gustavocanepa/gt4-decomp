struct D_00688D48;
struct func_0060A738 {
    func_0060A738(D_00688D48 *owner);
    int d[3];
};
struct func_00574D78 {
    func_00574D78();
    int d[12];
};
struct func_0060A480 {
    func_0060A480();
    int d[3];
};
struct Pair {
    int a, b;
    Pair() : a(0), b(0) {}
};

struct D_00688D48 {
    func_0060A738 link;
    int m0C;
    func_00574D78 m10;
    func_0060A480 m40;
    func_0060A480 m4C;
    func_0060A480 m58;
    func_00574D78 m64;
    int m94;
    Pair m98;
    int mA0;
    D_00688D48();
    virtual ~D_00688D48();
};

D_00688D48::D_00688D48() : link(this), m0C(0), m94(0), mA0(0) {}
