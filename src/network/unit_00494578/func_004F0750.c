void func_005A48D8(void *, int, int);
int func_0050B168(void *, int *);
void func_004F87B0(void *, int);
void func_00577F80(void);
void func_004F8128(void);
void func_004F6D40(void);
void func_004F6E28(void);
void func_004F6EE8(void);

int func_004F0750(void *s, int wait) {
    int callbacks[12];
    int status[4];
    int done = 0;

    do {
        int result;

        func_005A48D8(callbacks, 0, 0x2C);
        status[0] = 0;
        callbacks[0] = (int)func_004F8128;
        callbacks[1] = (int)s;
        callbacks[4] = (int)func_004F6D40;
        callbacks[5] = (int)s;
        callbacks[6] = (int)func_004F6E28;
        callbacks[7] = (int)s;
        callbacks[8] = (int)func_004F6EE8;
        callbacks[9] = (int)s;
        result = func_0050B168(callbacks, status);
        if (result == 0) {
            done = 1;
            break;
        }
        func_004F87B0(s, result);
        func_00577F80();
    } while (wait);
    return done;
}
