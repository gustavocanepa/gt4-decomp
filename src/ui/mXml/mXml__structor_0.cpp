typedef int s32;

extern void *D_0026CD80;
extern void *D_0026D108;
extern void *D_0026D2B8;
extern void *mXml__vtable;
extern "C" void *hObject__structor_0(void *);
extern "C" void *func_00209200(void *);
extern "C" void *func_0026CAA0(void *, void *);
extern "C" void *func_004CE828(s32);
extern "C" void *func_004CF370(void *, void *);
extern "C" void *func_004CF3F0(void *, void *, void *);
extern "C" void *func_004CF410(void *, void *);

extern "C" void mXml__structor_0(void *arg0) {
    hObject__structor_0(arg0);
    *(void **)((char *)arg0 + 0x4) = &mXml__vtable;
    func_00209200((char *)arg0 + 0x10);
    func_0026CAA0((char *)arg0 + 0x14, (char *)arg0 + 0x10);
    void *r3 = func_004CE828(0x0);
    *(void **)((char *)arg0 + 0x42c) = r3;
    func_004CF370(r3, (char *)arg0 + 0x14);
    func_004CF3F0(*(void **)((char *)arg0 + 0x42c), &D_0026CD80, &D_0026D108);
    func_004CF410(*(void **)((char *)arg0 + 0x42c), &D_0026D2B8); return;
}
