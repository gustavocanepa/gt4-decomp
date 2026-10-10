typedef struct func_0053B858_Resp func_0053B858_Resp;
struct func_0053B858_Resp {
    int status;
    int maxAge;
    int contentLength;
    char date[0x200];
    char usn[0x200];
    char ext[0x200];
    char location[0x200];
    char server[0x200];
    char st[0x200];
    char contentType[0x200];
    char contentLanguage[0x200];
};

extern char D_006C3B40[];

char *func_005A6E50(char *s, const char *delim);
int func_0053B5E0(const char *a, const char *b, int n);
long func_005A7170(const char *s, char **end, int base);
char *func_0053B538(char **s, const char *delim);
int func_0053B508(int c) __attribute__((const));
int func_0057F260(const char *s);
char *func_005A6AB0(char *dst, const char *src, int n);

int func_0053B858(char *buf, func_0053B858_Resp *resp) {
    short status = -1;
    char *val = 0;
    const char *names[11] = {
        "Cache-Control", "USN", "Location", "Server", "ST", "EXT", "Date",
        "Content-length", "Content-language", "Content-type", 0,
    };
    char *tok;
    int line;
    tok = func_005A6E50(buf, "\r\n");
    line = 0;
    if (tok == 0) goto out;
    do {
        if (line == 0) {
            if (func_0053B5E0(tok, "http/1.", 7) != 0) goto out;
            val = tok + 9;
            status = func_005A7170(tok + 9, 0, 10);
            resp->status = status;
            if (status != 200) goto out;
        } else {
            int n;
            int i;
            val = tok;
            func_0053B538(&val, D_006C3B40);
            while (func_0053B508(*val)) val++;
            n = func_0057F260(tok);
            while (n-- > 0) {
                if (func_0053B508(tok[n])) tok[n] = 0;
                else break;
            }
            for (i = 0; names[i] != 0; i++) {
                if (func_0053B5E0(names[i], tok, func_0057F260(names[i])) == 0) break;
            }
            switch (i) {
            case 0:
                if (func_0053B5E0(func_0053B538(&val, "="), "max-age", 7) == 0) {
                    resp->maxAge = func_005A7170(val, 0, 10);
                }
                break;
            case 1:
                func_005A6AB0(resp->usn, val, 0x200);
                break;
            case 2:
                func_005A6AB0(resp->location, val, 0x200);
                break;
            case 3:
                func_005A6AB0(resp->server, val, 0x200);
                break;
            case 4:
                func_005A6AB0(resp->st, val, 0x200);
                break;
            case 5:
                func_005A6AB0(resp->ext, val, 0x200);
                break;
            case 6:
                func_005A6AB0(resp->date, val, 0x200);
                break;
            case 7:
                resp->contentLength = func_005A7170(val, 0, 10);
                break;
            case 8:
                func_005A6AB0(resp->contentLanguage, val, 0x200);
                break;
            case 9:
                func_005A6AB0(resp->contentType, val, 0x200);
                break;
            }
        }
        tok = func_005A6E50(0, "\r\n");
        line++;
    } while (tok != 0);
out:
    return status;
}
