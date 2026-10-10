typedef unsigned char u8;
u8 *func_004C9198(u8 *arg0, u8 *arg1) {
    u8 *r = arg0;
    while ((*arg0++ = *arg1++) != 0) ;
    return r;
}
