extern "C" float func_00477460(void *v);
extern "C" void func_00476B30(void *v, int b);

extern "C" void func_004784E0(void *a, void *b)
{
    func_00476B30(a, (int)func_00477460(a) && (int)func_00477460(b));
}
