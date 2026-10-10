struct Reader { int w[4]; };
struct Obj { char pad[0xD0]; void *data; };
extern "C" void func_00427820(Reader *r);
extern "C" void GT4_Motion__MotionSetPlayer__set(Reader *r, int pos, void *data);
extern "C" int func_0042A0D0(Reader *r, int key);

extern "C" int func_003EB9A8(Obj *self, int key)
{
    if (!self->data)
        return -1;
    Reader r;
    func_00427820(&r);
    GT4_Motion__MotionSetPlayer__set(&r, 0, self->data);
    return func_0042A0D0(&r, key);
}
