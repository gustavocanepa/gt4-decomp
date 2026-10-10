extern "C" int func_00466B28(int kind, int sub) {
    int r = 0;
    switch (kind) {
    case 1:
        r = 1;
        break;
    case 2:
        switch (sub) {
        case 0:
            r = 1;
            break;
        case 3:
            r = 3;
            break;
        case 5:
            break;
        default:
            r = 2;
            break;
        }
        break;
    }
    return r;
}
