extern "C" int func_005208F8(unsigned int *p, int size) {
    unsigned int *end = (unsigned int *)((char *)p + size);
    for (; p < end; p++) {
        unsigned int w = *p;
        switch (w >> 26) {
        case 0: case 2: case 3:
            *p = w & 0xFC000000;
            break;
        case 1: case 4: case 5: case 6: case 7: case 16: case 17: case 18: case 19:
            break;
        case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
        default:
            *p = w & 0xFFFF0000;
            break;
        }
    }
    return 0;
}
