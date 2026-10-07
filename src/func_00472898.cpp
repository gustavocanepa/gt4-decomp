extern char D_006AD430[];
extern char D_006AD438[];
extern char D_006AD440[];

char *func_00472898(int *arg0) {
    int a0 = *arg0;
    char *v0 = D_006AD430;

    switch (a0) {
    case 1:
        return D_006AD438;
    default:
        v0 = D_006AD440;
    case 0:
        return v0;
    }
}
