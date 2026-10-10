/* compiler: ee-gcc2.9-991111 */
int func_005AE0B0(int);
void func_005AE120(void);
void func_005B94A0(int, int);

int func_005B7148(void) {
    if (func_005AE0B0(4) & 0x40000) {
        func_005AE120();
        func_005B94A0(1, 1);
        func_005B94A0(0, 1);
        return 1;
    }
    return 0;
}
