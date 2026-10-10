typedef int s32;

struct Handle {
    s32 obj;
    char pad4[0xC];
};

extern char D_0069C7B8[]; /* "cursor" */
extern "C" void func_0023FB80(Handle *h);
extern "C" void func_0023F8C8(s32 obj, const char *name);
extern "C" void func_0023DDF0(Handle *h, s32 flags);
extern "C" void func_002C8D68(void *self, void *arg);

extern "C" void func_002C8DD0(void *self, void *arg) {
    Handle h;
    func_0023FB80(&h);
    func_0023F8C8(h.obj, D_0069C7B8);
    func_0023DDF0(&h, 2);
    func_002C8D68(self, arg);
}
