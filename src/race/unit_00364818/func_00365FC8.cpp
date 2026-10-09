typedef signed char s8;

struct B {
    char pad[0xCCC8];
    s8 cell[1][6];
};

extern "C" s8 func_00365FC8(struct B *arg0, int row, int col) {
    return arg0->cell[row][col];
}
