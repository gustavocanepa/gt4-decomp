struct Text5 { char c[5]; };
struct Owner { char pad[0x14]; int id; };

extern void *D_00624984;
extern "C" const Text5 D_0068F520;
extern "C" const char D_0068F528[];
extern "C" int func_00441248(int id);
extern "C" int func_004460C8(int x);
extern "C" void func_00490A40(void *mgr, char *buf, int size, int value, const char *fmt);

extern "C" void func_00146358(Owner *o, int size, char *buf) {
    int r = func_004460C8(func_00441248(o->id));
    if (r == 0) {
        *(Text5 *)buf = D_0068F520;
        return;
    }
    func_00490A40(D_00624984, buf, size, r, D_0068F528);
}
