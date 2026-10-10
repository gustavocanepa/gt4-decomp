struct Z { int x, y; };
extern void func_00578968(struct Z *, int, int);
void func_005750C0(int a, int b) {
    struct Z z;
    z.x = 0; z.y = 0;
    func_00578968(&z, a, b);
}
