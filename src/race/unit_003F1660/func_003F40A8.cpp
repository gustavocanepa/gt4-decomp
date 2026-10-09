typedef unsigned char u8;

struct B {
    char pad[0xCCA4];
    u8 cell[1][6];
};

extern "C" u8 func_003F40A8(struct B *arg0, int row, int col) {
    return arg0->cell[row][col];
}
