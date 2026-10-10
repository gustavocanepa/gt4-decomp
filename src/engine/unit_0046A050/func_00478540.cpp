extern "C" float func_00477460(void *v);
extern "C" void func_00476BC0(void *v, int i);

extern "C" void func_00478540(void *a, void *b)
{
    float x = func_00477460(a);
    func_00476BC0(a, (int)x | (int)func_00477460(b));
}
