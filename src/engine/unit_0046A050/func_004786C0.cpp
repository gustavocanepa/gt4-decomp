extern "C" float func_00477460(void *);
extern "C" void func_00476BC0(void *, unsigned int);

extern "C" void func_004786C0(void *a, void *b)
{
    float x = func_00477460(a);
    float y = func_00477460(b);
    func_00476BC0(a, (unsigned int)x >> (int)y);
}
