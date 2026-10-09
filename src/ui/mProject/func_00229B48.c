int func_00206868(void);
int func_0025C300(int);
int func_00305570(int);
int func_0057F260(int);
int func_005CD320(int, int, int, int);

int func_00229B48(int self, int name) {
    int found = 0;
    int it;
    for (it = func_00206868(); it != 0; it = func_0025C300(it)) {
        int s = func_00305570(it);
        if (func_005CD320(name, s, 0, func_0057F260(s)) == 0)
            found = it;
    }
    return found;
}
