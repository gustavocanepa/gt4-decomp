typedef unsigned short u16;
struct S;

extern "C" void *func_0055F1F0(struct S *arg0);

extern "C" void *func_0055F228(struct S *arg0) {
    u16 *p = (u16 *)func_0055F1F0(arg0);
    return (char *)p + *p;
}
