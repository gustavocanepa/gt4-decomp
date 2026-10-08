typedef unsigned short u16;
struct S;

extern "C" void *func_0055F1E0(struct S *arg0);

extern "C" void *func_0055F200(struct S *arg0) {
    u16 *p = (u16 *)func_0055F1E0(arg0);
    return (char *)p + *p;
}
