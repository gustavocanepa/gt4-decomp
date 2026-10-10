extern int func_002663F8(int);
extern int func_002663C8(int);

struct func_002E95D0_arg0 {
    char pad0[0xC4];
    int unkC4;
};

int func_002E95D0(void *arg0, int arg1)
{
    if (((struct func_002E95D0_arg0 *)arg0)->unkC4 != 0) {
        return func_002663F8(arg1);
    }
    return func_002663C8(arg1);
}
