struct Obj {
    char pad[0x14];
    unsigned char locked;
};

extern "C" void func_00343578(Obj *o, float v);
extern "C" void func_00343698(Obj *o, float v);
extern "C" void func_00343978(Obj *o, float v);

extern "C" void func_00343420(Obj *o, int locked)
{
    if (!o->locked && locked) {
        func_00343578(o, 0.0f);
        func_00343698(o, 0.0f);
        func_00343978(o, 0.0f);
    }
    o->locked = locked;
}
