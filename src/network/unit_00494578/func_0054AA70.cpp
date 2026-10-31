/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Slot request id (func_00562330 on id/4, id%4 with flag 1): a non-negative
   handle goes through func_00561E00 (status 0 or 4), else status 10; records the
   status in the slot record like its siblings func_0054AB88 and func_0054B4F8. */
extern char *D_0064C3E4;
extern "C" int func_0054A370(int) throw();
extern "C" int func_0054A8A8(int, int) throw() __attribute__((const));
extern "C" void func_00549858(char *, int, int) throw();
extern "C" int func_00562330(int, int, int, int);
extern "C" int func_00561E00(int);
extern "C" int func_0054AA70(int id, int arg1) {
    int status;
    if (!func_0054A370(id)) return 1;
    {
        int q = id / 4;
        int r = id % 4;
        status = 10;
        int result = func_00562330(q, r, arg1, 1);
        if (result >= 0) {
            status = 4;
            result = func_00561E00(result);
            if (result == 0) status = 0;
        }
        status = func_0054A8A8(status, result);
        int off = (q * 111 + r * 27) * 4;
        func_00549858((char *)(off + (int)D_0064C3E4) + 0x78, result, status);
        *((char *)(off + (int)D_0064C3E4) + 0x78) = 0;
    }
    return status;
}
