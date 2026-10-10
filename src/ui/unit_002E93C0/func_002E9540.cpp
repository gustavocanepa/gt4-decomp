extern int func_00266368(int);
extern int func_00266398(int);

struct func_002E9540_arg0 {
    char pad0[0xC4];
    int unkC4;
};

int func_002E9540(void *arg0, int arg1)
{
    if (((struct func_002E9540_arg0 *)arg0)->unkC4 != 0) {
        return func_00266368(arg1);
    }
    return func_00266398(arg1);
}
