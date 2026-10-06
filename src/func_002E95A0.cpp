extern int func_002663C8(int);
extern int func_002663F8(int);

int func_002E95A0(void *arg0, int arg1)
{
    if (*(int *)((char *)arg0 + 0xC4) != 0) {
        return func_002663C8(arg1);
    }
    return func_002663F8(arg1);
}
