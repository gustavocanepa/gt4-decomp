extern char D_00686E00[];

struct Obj {
    int a;
    void *vt;
    int b;
    int c;
    float m[4][4];
};

extern "C" void func_0042AD90(Obj *self)
{
    self->a = 0;
    self->vt = D_00686E00;
    self->b = 0;
    self->c = 0;
    self->m[0][0] = 1.0f;
    self->m[1][0] = 0;
    self->m[2][0] = 0;
    self->m[3][0] = 0;
    self->m[0][1] = 0;
    self->m[1][1] = 1.0f;
    self->m[2][1] = 0;
    self->m[3][1] = 0;
    self->m[0][2] = 0;
    self->m[1][2] = 0;
    self->m[2][2] = 1.0f;
    self->m[3][2] = 0;
    self->m[0][3] = 0;
    self->m[1][3] = 0;
    self->m[2][3] = 0;
    self->m[3][3] = 1.0f;
}
