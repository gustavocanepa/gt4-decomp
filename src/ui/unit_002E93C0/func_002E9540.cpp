extern int func_00266368(int);
extern int func_00266398(int);

int func_002E9540(void *arg0, int arg1)
{
    if (*(int *)((char *)arg0 + 0xC4) != 0) {
        return func_00266368(arg1);
    }
    return func_00266398(arg1);
}
