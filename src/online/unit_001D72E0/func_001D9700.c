void func_0057B850(void *);
int func_0057F260(const char *);
void func_0057C718(void *, const char *, int);
void func_0057C808(void *, unsigned char *);
void func_0057C8B0(unsigned char *, char *);

typedef struct {
    char state[0x60];
} HashContext;

void func_001D9700(const char *a, const char *b, const char *c, char *out) {
    HashContext ctx;
    unsigned char digest[16];

    func_0057B850(&ctx);
    func_0057C718(&ctx, a, func_0057F260(a));
    func_0057C718(&ctx, b, func_0057F260(b));
    func_0057C718(&ctx, c, func_0057F260(c));
    func_0057C808(&ctx, digest);
    func_0057C8B0(digest, out);
}
