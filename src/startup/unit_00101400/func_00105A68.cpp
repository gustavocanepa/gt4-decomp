struct View {
    int target;
    char pad[0xC];
    int x, y, w, h;
};

extern "C" int GSBuffer__getBufferWidth(View *v);
extern "C" void func_004A4F48(int target, int a, int b, int x0, int y0, int x1, int y1, int c);
extern "C" void func_004A2038(int n);

extern "C" void func_00105A68(View *v, int c, int a)
{
    func_004A4F48(v->target, a, GSBuffer__getBufferWidth(v), v->x, v->y, v->x + v->w, v->y + v->h, c);
    func_004A2038(1);
}
