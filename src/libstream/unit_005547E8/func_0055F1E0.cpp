typedef unsigned short u16;

struct S { char pad[4]; u16 unk4; };

extern "C" void *func_0055F1E0(S *arg0) {
    char *p = (char *)arg0 + 4;
    return p + *(u16 *)p;
}
