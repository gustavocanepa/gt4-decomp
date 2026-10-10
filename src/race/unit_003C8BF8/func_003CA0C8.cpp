extern "C" void func_003CA0C8(int kind, float *x, float *y, float *z) {
    switch (kind) {
    case 5:
    case 10:
    case 11:
        *x = -0x1.9999980000000p-2f;
        *y = 0x1.83126e0000000p-1f;
        *z = -0x1.30a3d60000000p+0f;
        break;
    case 6:
    case 12:
    case 13:
        *x = -0x1.e353f60000000p-3f;
        *y = 0x1.ae147a0000000p-1f;
        *z = -0x1.3ba5e20000000p+0f;
        break;
    default:
        *x = 0.0f;
        *y = 0.0f;
        *z = 0.0f;
        break;
    }
}
