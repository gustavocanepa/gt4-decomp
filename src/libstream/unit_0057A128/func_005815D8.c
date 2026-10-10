/* compiler: ee-gcc2.9-991111 */
#define BCD2DEC(x) (((x) >> 4) * 10 + ((x) & 0xF))

int func_005815D8(const unsigned char *msf)
{
    return (BCD2DEC(msf[0]) * 60 + BCD2DEC(msf[1])) * 75 + BCD2DEC(msf[2]) - 150;
}
