extern char D_006AD358[];
extern char D_006AD360[];
extern char D_006AD368[];

char *func_00472898(int *arg0) {
    int a0 = *arg0;
    char *v0 = D_006AD358;

    switch (a0) {
    case 1:
        return D_006AD360;
    default:
        v0 = D_006AD368;
    case 0:
        return v0;
    }
}
