struct NameId {
    const char *name;
    int id;
};

struct Request {
    int pad[10];
    int kind;
    int type;
    int value;
    int pad34[3];
};

extern char D_00645570[];
extern NameId D_00696FD0[];
extern NameId D_00697098[];
extern "C" int func_0057F238(const char *, const char *);
extern int func_004F5890(void *, Request *);
extern void func_00215298(int);
extern int func_001F1368(void *);

int func_001F4778(void *ctx, const char *kind_name, const char *type_name, int value)
{
    Request request;
    int kind = 0xFFFFFF;
    int type;
    int i;
    int j;

    for (i = 0; i < 10; i++) {
        if (func_0057F238(D_00696FD0[i].name, kind_name) == 0) {
            kind = D_00696FD0[i].id;
            break;
        }
    }
    if (kind == 0xFFFFFF) {
        return 0;
    }
    type = 0xFFFFFF;
    for (j = 0; j < 6; j++) {
        if (func_0057F238(D_00697098[j].name, type_name) == 0) {
            type = D_00697098[j].id;
            break;
        }
    }
    if (type == 0xFFFFFF) {
        return 0;
    }
    request.kind = kind;
    request.type = type;
    request.value = value;
    while (!func_004F5890(D_00645570, &request))
        func_00215298(1);
    return func_001F1368(ctx);
}
