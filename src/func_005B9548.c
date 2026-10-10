/* compiler: ee-gcc2.9-991111 */
int func_005B9548(void *ctx, int ret) {
    if (ret >= 0)
        return ret;
    switch (ret) {
    case -0x10004:
        return 0x81078009;
    case -5:
        return 0x81079001;
    default:
        return 0x81070000 | (-ret & 0xFFFF);
    }
}
