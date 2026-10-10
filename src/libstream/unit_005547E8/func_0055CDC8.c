/* compiler: ee-gcc2.96-nsa-nosib */
extern char D_00655340[];
void func_00576100(void *lock);
void func_00576140(void *lock);
void func_0055DE18(void *dev, int port, int arg);

void func_0055CDC8(void *dev, int port, int arg) {
    int i;
    func_00576100(D_00655340);
    if (port != 2) {
        func_0055DE18(dev, port, arg);
    } else {
        for (i = 0; i < 2; i++)
            func_0055DE18(dev, i, arg);
    }
    func_00576140(D_00655340);
}
