extern "C" {
unsigned char *malloc(int);
void free(void *);
void func_00574B18(void *, unsigned char *, unsigned char *, int);
void func_00574BA0(void *, int);
}
extern int func_001F7AE8(void *, unsigned char *, int);

unsigned char *func_001F7B58(void *file, int *size)
{
    unsigned char *data = malloc(*size);
    if (!func_001F7AE8(file, data, *size)) {
        free(data);
        return 0;
    }
    if ((data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24)) == (int)0xFFF7EEC5) {
        int length = data[4];
        length |= data[5] << 8;
        length |= data[6] << 16;
        length |= data[7] << 24;
        length = -length;
        unsigned char *out = malloc(length);
        char inflator[0x3050];
        func_00574B18(inflator, out, data, 1);
        func_00574BA0(inflator, 2);
        free(data);
        *size = length;
        return out;
    }
    return data;
}
