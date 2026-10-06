struct Inner { char pad[0x4A0]; char f4a0[1]; };
struct Outer { char pad[0x14]; struct Inner *inner; };
extern int func_003434C8(void *);
extern int func_00472898(void *);
extern void func_00490A40(int, int, int, int, int);
extern char D_006244D8[];
extern int D_00624984;
void func_00146528(struct Outer *o, int a, int b)
{
    int r = func_003434C8(o->inner->f4a0);
    int s = func_00472898(D_006244D8);
    func_00490A40(D_00624984, b, a, r, s);
}
