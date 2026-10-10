/* compiler: ee-gcc2.9-991111 */
typedef struct {
    int m0;
    int pad[3];
} Entry_005B9448;

extern Entry_005B9448 D_0088C348[];
extern Entry_005B9448 *D_00659310;
extern unsigned int D_00659314;

int func_005B9448(int id) {
    Entry_005B9448 *table;
    unsigned int count;
    if (id < 0) {
        id &= 0x7FFFFFFF;
        table = D_0088C348;
        count = 0x20;
    } else {
        table = D_00659310;
        count = D_00659314;
    }
    if ((unsigned int)id >= count) {
        return -0x69;
    }
    table[id].m0 = 0;
    return 0;
}
