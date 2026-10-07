struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *func_003194F0(struct Derived *self);
extern "C" char D_00675B50[];
extern "C" struct Derived *func_0031D0C8(struct Derived *self)
{
    struct Derived *r = func_003194F0(self);
    self->vtbl = D_00675B50;
    return r;
}
