struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *hValue__structor_0(struct Derived *self);
extern "C" char hFunctionValue__vtable[];
extern "C" struct Derived *hFunctionValue__structor_0(struct Derived *self)
{
    struct Derived *r = hValue__structor_0(self);
    self->vtbl = hFunctionValue__vtable;
    return r;
}
