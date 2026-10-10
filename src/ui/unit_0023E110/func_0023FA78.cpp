typedef int s32;

struct Handle {
    s32 p;
};

struct Obj {
    char pad[0x14];
    Handle h;
};

extern "C" void func_002C3B60(s32);
extern "C" void func_002C3CA8(s32, s32);

extern "C" void func_0023FA78(Obj *self, s32 arg1, s32 arg2) {
    Handle *h = &self->h;
    func_002C3B60(h->p);
    func_002C3CA8(h->p, arg2);
}
