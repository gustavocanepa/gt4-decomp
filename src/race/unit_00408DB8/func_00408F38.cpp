extern "C" void func_00408350(void *self, int axis, float v);

extern "C" void func_00408F38(void *self, float v)
{
    func_00408350(self, 0, v);
    func_00408350(self, 1, v);
    func_00408350(self, 2, v);
}
