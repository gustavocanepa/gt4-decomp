struct Obj {
    char pad[0xB8];
    float unkB8;
};

extern "C" float func_00200EC8(struct Obj *arg0)
{
    return arg0->unkB8;
}
