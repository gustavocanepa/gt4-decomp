struct File { int pad; unsigned char *data; };
extern "C" int func_004B38A0(File *f)
{
    unsigned char *p = f->data;
    unsigned int m = p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
    if (m == 0x53466F52)
        return 0;
    return m == 0xACB990AD;
}
