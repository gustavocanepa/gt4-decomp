struct Mat3 {
    float m[3][3];
    float &operator()(int r, int c) { return m[r][c]; }
};

/* The transposed copy through the inline element accessor: the shared diagonal offsets stay in
   a register (li 0x10 / 0x20 + addu), which explicit m[r][c] statements fold into the offsets. */
extern "C" void func_00486B38(Mat3 &dst, Mat3 &src)
{
    dst(0, 0) = src(0, 0);
    dst(1, 0) = src(0, 1);
    dst(2, 0) = src(0, 2);
    dst(0, 1) = src(1, 0);
    dst(1, 1) = src(1, 1);
    dst(2, 1) = src(1, 2);
    dst(0, 2) = src(2, 0);
    dst(1, 2) = src(2, 1);
    dst(2, 2) = src(2, 2);
}
