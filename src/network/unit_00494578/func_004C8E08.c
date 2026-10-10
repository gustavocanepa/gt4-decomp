typedef unsigned short u16;
u16 *func_004C8E08(u16 *arg0, u16 *arg1) {
    u16 *p = arg0;
    while ((*p++ = *arg1++) != 0) ;
    return arg0;
}
