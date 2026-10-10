/* compiler: ee-gcc2.9-991111 */
struct RpcBuf {
    int result;
    int pad;
    char name[0x100];
};

extern struct RpcBuf D_00889C80;
extern int D_00889E80;

extern int func_005B6268(void);
extern int func_005B6368(void);
extern char *func_005A6AB0(char *dst, const char *src, unsigned int n);
extern int func_005B19B0(void *cd, int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *param);

int func_005B68D0(const char *name)
{
    if (func_005B6268() < 0) {
        return -0x10000;
    }
    if (func_005B6368() != 0) {
        return -0x10004;
    }
    func_005A6AB0(D_00889C80.name, name, 0xFC);
    D_00889C80.name[0xFB] = 0;
    if (func_005B19B0(&D_00889E80, 9, 0, &D_00889C80, 0x200, &D_00889C80, 4, 0, 0) < 0) {
        return -0x10001;
    }
    return D_00889C80.result;
}
