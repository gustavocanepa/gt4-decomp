struct B { char pad[0xCCA4]; unsigned char cell[1][6]; };
void func_003F4080(struct B *b, int row, int col, unsigned char v)
{
    b->cell[row][col] = v;
}
