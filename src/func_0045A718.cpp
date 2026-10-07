struct Obj1 {
    char pad[0x2DC];
    int bufIndex;
};

extern "C" void func_00459470(void *arg0, void *dst, void *src, int size);

extern "C" void *func_0045A718(void *arg0, Obj1 *arg1, int arg2)
{
    char *v1 = (char *)arg1;
    void *s0 = arg0;
    int t0 = arg2 - 1;
    int a1 = 1;
    int v0 = arg1->bufIndex;
    int a2 = v0 * 0x16C;
    a1 = a1 - v0;
    char *p0 = a2 + v1;
    a2 = a1 * 0x16C;
    p0 = p0 + 4;
    char *p1 = a2 + v1;
    char *idxBuf = p0 + t0;
    p1 = p1 + 4;
    char *otherBuf = p1 + t0;
    func_00459470(s0, otherBuf, idxBuf, 0x16C);
    return s0;
}
