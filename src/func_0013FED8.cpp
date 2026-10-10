typedef int s32;

struct Handle {
    s32 obj;
    char pad4[0xC];
};

extern "C" void func_0013BDC0(Handle *h, void *src);
extern "C" void func_0013BD68(Handle *h, s32 flags);
extern "C" void func_00147D08(s32 obj);
extern "C" void func_00147D50(s32 obj);

extern "C" void func_0013FED8(void *self, void *src) {
    Handle h;
    func_0013BDC0(&h, src);
    func_00147D08(h.obj);
    func_0013BD68(&h, 2);
    func_0013BDC0(&h, src);
    func_00147D50(h.obj);
    func_0013BD68(&h, 2);
}
