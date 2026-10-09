
char *func_00472680(int *arg0) {
    int a0 = *arg0;
    char *v0 = "km/h";

    switch (a0) {
    case 1:
        return "mph";
    default:
        v0 = "VVV";
    case 0:
        return v0;
    }
}
