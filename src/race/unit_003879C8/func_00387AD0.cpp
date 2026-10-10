struct Obj {
    char pad[0x64];
    virtual ~Obj();
};

extern "C" void func_00387AD0(Obj *o, int free_memory)
{
    if (free_memory)
        delete o;
    else
        o->~Obj();
}
