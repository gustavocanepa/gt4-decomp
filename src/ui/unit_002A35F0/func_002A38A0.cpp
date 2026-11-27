/* compiler: ee-gcc2.96-no-strict-aliasing */
/* mImageFace: recomputes the four texture coordinates of the selected cell of a
 * cols x rows grid (called by the grid and cell setters, 0x002A39F0 / 0x002A3A30).
 * The cell index is first clamped into the grid. Each coordinate is written through
 * a reference-returning accessor: under -fno-strict-aliasing the compiler cannot
 * tell the store apart from the byte fields until combine folds the address, so
 * every statement re-reads its cell index and recomputes its product, and only the
 * post-reload cse turns the duplicates into register copies (retail's five mov.s). */
struct Vec2 {
    float x, y;
    float &X() { return x; }
    float &Y() { return y; }
};
struct Self {
    char pad0[0xCC];
    Vec2 uv[4];             /* 0xCC: left-top, right-top, right-bottom, left-bottom */
    unsigned char cols;     /* 0xEC */
    unsigned char rows;     /* 0xED */
    unsigned char col;      /* 0xEE */
    unsigned char row;      /* 0xEF */
};
extern char D_00836D58[];
extern "C" void func_005769F0(void *);   /* lock */
extern "C" void func_00576A28(void *);   /* unlock */

extern "C" void func_002A38A0(Self *self)
{
    if (self->col > self->cols - 1)
        self->col = self->cols - 1;
    if (self->row > self->rows - 1)
        self->row = self->rows - 1;
    float sx = 1.0f / self->cols;
    float sy = 1.0f / self->rows;
    func_005769F0(D_00836D58);
    self->uv[0].X() = sx * self->col;
    self->uv[0].Y() = sy * self->row;
    self->uv[1].X() = sx * (self->col + 1);
    self->uv[1].Y() = sy * self->row;
    self->uv[2].X() = sx * (self->col + 1);
    self->uv[2].Y() = sy * (self->row + 1);
    self->uv[3].X() = sx * self->col;
    self->uv[3].Y() = sy * (self->row + 1);
    func_00576A28(D_00836D58);
}
