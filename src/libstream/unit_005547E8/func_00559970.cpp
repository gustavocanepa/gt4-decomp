extern "C" void func_00576100(void *lock);
extern "C" void func_00576140(void *lock);
extern "C" char D_00655340[];

/* test-and-set under the global lock */
extern "C" int func_00559970(int *flag)
{
    func_00576100(D_00655340);
    int ok = *flag == 0;
    if (ok)
        *flag = 1;
    func_00576140(D_00655340);
    return ok;
}
