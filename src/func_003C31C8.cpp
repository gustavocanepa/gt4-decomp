struct Loader {
    int pad0[4];
    void *obj;
    int pad14[3];
};

struct Matrix {
    float m[12];
};

struct Obj {
    int pad0[4];
    void *model;
    int pad14;
    int kind;
};

extern const char D_006A2A60[];
extern "C" void func_003EC2B8(Loader *l, const char *name, int flags);
extern "C" void func_00473CC0(void *model);
extern "C" void func_003EBE80(void *model);
extern "C" void func_00472DE8(Matrix *m);
extern "C" void func_004741B0(void *model, Matrix *m);

extern "C" void func_003C31C8(Obj *self, int kind)
{
    self->kind = kind;
    Loader l;
    func_003EC2B8(&l, D_006A2A60, 1);
    self->model = l.obj;
    func_00473CC0(self->model);
    func_003EBE80(self->model);
    Matrix m;
    func_00472DE8(&m);
    func_004741B0(self->model, &m);
}
