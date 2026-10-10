struct Pool { char *base; int used; char *func_00575DA0; };

extern "C" int func_003C1310(Pool *self);

extern "C" void func_003C2070(Pool *self)
{
    self->used = 0;
    self->func_00575DA0 = self->base;
    int size = func_003C1310(self);
    char *p = self->func_00575DA0;
    for (int i = 0; i < 127; i++) {
        char *next = p + size;
        *(char **)p = next;
        p = next;
    }
    *(char **)p = 0;
}
