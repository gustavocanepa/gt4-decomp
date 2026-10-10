extern "C" void func_00266060(void *node, void *arg);
extern "C" int func_00265D98(void *node);
extern "C" void *func_0025C2A0(void *node);

extern "C" void func_00265FF0(void *node, void *arg)
{
    func_00266060(node, arg);
    if (func_00265D98(node)) {
        func_00266060(node, arg);
        if (func_0025C2A0(node))
            func_00265FF0(func_0025C2A0(node), arg);
    }
}
