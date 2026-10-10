typedef unsigned int u32;

extern "C" int func_0035FBC8(u32 v) {
    switch (v) {
    case 1:
    case 2:
    case 8:
    case 9:
    case 10:
        return 1;
    case 0:
    case 3:
        return 2;
    case 4:
    case 7:
    case 11:
    case 15:
        return 3;
    default:
        return 4;
    }
}
