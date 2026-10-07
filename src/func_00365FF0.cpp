typedef float f32;

struct B { char pad[0xCCEC]; f32 cell[1][6]; };

f32 func_00365FF0(struct B *b, int row, int col) {
    return b->cell[row][col];
}
