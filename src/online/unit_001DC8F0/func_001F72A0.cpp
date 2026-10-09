extern char D_00645570[];
extern char *func_004FA008(void *);
extern void func_004FA048(void *, char *);

struct Blob32 {
    char data[0x20];
};

void func_001F72A0(void *ctx, const Blob32 *blob)
{
    char *entry = func_004FA008(D_00645570);
    if (entry) {
        *(Blob32 *)(entry + 0xBA) = *blob;
    }
    func_004FA048(D_00645570, entry);
}
