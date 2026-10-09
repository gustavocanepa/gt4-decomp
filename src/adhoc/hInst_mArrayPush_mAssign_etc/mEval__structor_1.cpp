struct Derived { int base0; void *vtbl; };
extern "C" struct Derived *RefCounter__structor_0(struct Derived *self);
extern "C" char mEval__vtable[];
extern "C" struct Derived *mEval__structor_1(struct Derived *self)
{
    struct Derived *r = RefCounter__structor_0(self);
    self->vtbl = mEval__vtable;
    return r;
}
