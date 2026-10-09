extern char D_00645570[];
extern int func_004F68C8(void *);

struct Blob32 {
    char data[0x20];
};

void func_001F7330(void *ctx, const Blob32 *blob)
{
    if (func_004F68C8(D_00645570)) {
        *(Blob32 *)(D_00645570 + 0xF98) = *blob;
    }
}
