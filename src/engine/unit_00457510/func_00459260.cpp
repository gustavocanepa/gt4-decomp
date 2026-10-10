extern "C" int func_00459260(unsigned int kind, int flag1, int flag2) {
    if (flag1) {
        switch (kind) {
        case 0: return 0;
        case 1: return 1;
        case 2: return 2;
        case 3: case 4: case 5: return 3;
        case 6: case 7: case 8: case 9: case 10: return flag2 ? 5 : 4;
        case 11: return 6;
        case 12: return 7;
        }
    } else {
        switch (kind) {
        case 0: return 0;
        case 1: return 1;
        case 2: return 2;
        case 3: case 4: case 5: return 3;
        case 6: case 7: case 8: case 9: case 10: return flag2 ? 5 : 4;
        case 11: return 6;
        case 12: return 7;
        }
    }
    return 0;
}
