/* compiler: ee-gcc2.96-nsa-nosib */
typedef struct { int b[4]; } Block16;

void func_005CBE00(char *obj, Block16 *src) {
    *(Block16 *)(*(char **)(obj + 0x10) + 0x1184) = *src;
}
