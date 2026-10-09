struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *hObject__structor_1(struct Derived *self);
extern "C" char hNumeric__vtable[];
extern "C" struct Derived *hNumeric__structor_1(struct Derived *self)
{
    struct Derived *r = hObject__structor_1(self);
    self->vtbl = hNumeric__vtable;
    return r;
}
