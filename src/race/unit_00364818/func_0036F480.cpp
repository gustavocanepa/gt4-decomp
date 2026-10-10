struct Cam { int a; int b; float c; int d; float e; float f; };
extern "C" void func_0036F540(Cam *c, float v);

extern "C" void func_0036F480(Cam *c)
{
    c->a = 500;
    c->b = 140;
    c->c = -1.0f;
    c->d = -12500;
    c->e = 36.0f;
    c->f = 24.0f;
    func_0036F540(c, 30.0f);
}
