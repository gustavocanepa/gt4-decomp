/* One work buffer of the movie decoder: requested size and the address it was given. */
struct WorkBuffer {
    int size;
    int addr;
};
extern WorkBuffer D_00874340[7];

extern "C" void func_0054FB38(int xbits, int ybits);
extern "C" int func_0054FE50(void);
extern "C" int func_0054FE68(void);
extern "C" int func_00562778(int size);

/* Size the decoder's seven work buffers for a width x height picture and allocate them.
 * A macroblock (16x16 pixels) takes 384 bytes: six 8x8 blocks of coefficients. */
extern "C" void func_005632B8(int width, int height) {
    int i;
    int macroblockBytes;

    func_0054FB38(6, 14);
    macroblockBytes = ((width + 15) / 16) * ((height + 15) / 16) * 384;
    D_00874340[0].size = 0xA000;
    D_00874340[1].size = func_0054FE50();
    D_00874340[2].size = func_0054FE68();
    D_00874340[3].size = macroblockBytes;
    D_00874340[4].size = macroblockBytes;
    D_00874340[5].size = macroblockBytes;
    D_00874340[6].size = width * height * 8;
    for (i = 0; i < 7; i++)
        D_00874340[i].addr = func_00562778(D_00874340[i].size);
}
