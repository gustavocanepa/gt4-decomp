extern const char D_006A2E78[], D_006A2E88[], D_006A2E98[], D_006A2EA8[];

extern "C" const char *func_003C9FC8(int k) {
    switch (k) {
    case 3: return D_006A2E78;
    case 4: return D_006A2E88;
    case 5: case 10: case 11: return D_006A2E98;
    case 6: case 12: case 13: return D_006A2EA8;
    default: return 0;
    }
}
