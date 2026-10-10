struct Anim {
    int state;
    float speed;
    char pad[0x20 - 8];
};
extern "C" void func_003A96F8(Anim *a, float x, float y);
extern "C" void func_003A9708(Anim *a, float x, float y);
extern "C" void func_003A9738(Anim *a, int i, int j);
extern "C" void func_003A99A8(void *p);
struct Obj {
    int m0;
    Anim anim;
    char m24[4];
};

extern "C" void func_003A3930(Obj *o)
{
    Anim *a = &o->anim;
    func_003A96F8(a, 60.0f, 0.5f);
    func_003A9708(a, 3.0f, 3.0f);
    func_003A9738(a, -1, 0);
    a->speed = 54.0f;
    a->state = 0;
    func_003A99A8(o->m24);
}
