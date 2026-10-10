struct B0 { int a; B0(int v) { a = v; } virtual ~B0(); };
struct D_0068A258 : B0 {
    int c;
    D_0068A258(int x, int y);
    virtual ~D_0068A258();
};
D_0068A258::D_0068A258(int x, int y) : B0(x) {
    c = y;
}
