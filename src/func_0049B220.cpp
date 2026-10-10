/* Bytes needed by a GS texture of format psm (PSMCT32 = 0 ... PSMZ16S = 0x3A), rounded up to whole pages. */
extern "C" int func_0049B220(unsigned int psm, int w, int h, int *outWidth) {
    int pw, ph, shift;
    switch (psm) {
    case 0x00: case 0x01: case 0x1B: case 0x24: case 0x2C: case 0x30: case 0x31:
        pw = 64; ph = 32; shift = 11;
        break;
    case 0x02: case 0x0A: case 0x32: case 0x3A:
        pw = 64; ph = 64; shift = 12;
        break;
    case 0x13:
        pw = 128; ph = 64; shift = 13;
        break;
    case 0x14:
        pw = 128; ph = 128; shift = 14;
        break;
    default:
        return -1;
    }
    int rw = (w + pw - 1) & -pw;
    int rh = (h + ph - 1) & -ph;
    if (outWidth)
        *outWidth = rw;
    return (rw * rh << 11) >> shift;
}
