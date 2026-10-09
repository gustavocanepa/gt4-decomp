extern char D_006AD448[];
extern char D_006AD438[];
extern char D_006AD440[];

char *func_00472908(int *arg0) {
    int a0 = *arg0;
    char *v0 = D_006AD448;

    switch (a0) {
    case 1:
        return D_006AD438;
    default:
        v0 = D_006AD440;
    case 0:
        return v0;
    }
}
