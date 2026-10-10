struct func_0050AC90_Token {
    int status;
};

struct func_0050AC90_Error {
    char pad0[0x18];
    int code;
    char pad1C[0xC4 - 0x1C];
};

extern "C" int func_0057D9C0(const char *fmt, ...);
extern "C" void func_005062C8(char *buf, int size);
extern "C" void func_00506330(char *buf, int size);
extern "C" int func_0050BC50(void *p);
extern "C" void *func_005A48D8(void *dst, int c, unsigned int n);
extern char D_00853768[];
extern void (*D_008A03C8)(func_0050AC90_Error *error, int user);
extern int D_008A01A0;

extern "C" void func_0050AC90(void *ctx, func_0050AC90_Token *token) {
    int code = -995;
    int ok;
    char buf[0x40];
    func_0057D9C0("IDF... BillingLoginCallback\n");
    func_005062C8(buf, 0x40);
    func_0057D9C0("IDF...%s\n", buf);
    func_00506330(buf, 0x40);
    func_0057D9C0("IDF...%s\n", buf);
    func_0057D9C0("IDF...Billing Token Status %d.\n", token->status);
    switch (token->status) {
    case 0:
        func_0057D9C0("MBILL...FAILURE.\n");
        ok = 0;
        break;
    case 1:
        func_0057D9C0("MBILL...REJECTED.\n");
        ok = 0;
        break;
    case 2:
        func_0057D9C0("MBILL...POSTED.\n");
        ok = 1;
        break;
    case 3:
        func_0057D9C0("MBILL...BUMPED.\n");
        ok = 1;
        break;
    case 4:
        code = -997;
        func_0057D9C0("MBILL...INUSE.\n");
        ok = 0;
        break;
    case 5:
        code = -954;
        func_0057D9C0("MBILL...INVALID TITLE.\n");
        ok = 0;
        break;
    case 6:
        code = -998;
        func_0057D9C0("MBILL...INVALID_ACCOUNT.\n");
        ok = 0;
        break;
    case 7:
        code = -978;
        func_0057D9C0("MBILL...INVALID PASSWORD.\n");
        ok = 0;
        break;
    case 8:
        func_0057D9C0("MBILL...INVALID PURCAHSE.\n");
        ok = 0;
        break;
    case 9:
        func_0057D9C0("MBILL...INVALID PRODUCT.\n");
        ok = 0;
        break;
    case 10:
        func_0057D9C0("MBILL...TOKEN TIMEOUT.\n");
        ok = 0;
        break;
    default:
        func_0057D9C0("MBILL...default.\n");
        ok = 0;
        break;
    }
    if (!ok || func_0050BC50(D_00853768) != 0) {
        func_0050AC90_Error error;
        func_005A48D8(&error, 0, sizeof(error));
        error.code = code;
        if (D_008A03C8 != 0) {
            D_008A03C8(&error, D_008A01A0);
        }
    }
}
