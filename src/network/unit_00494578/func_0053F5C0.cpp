struct func_0053F5C0_Data {
    unsigned int flags;
    char str[19][0x100];
};

struct func_0053F5C0_Ctx {
    void *parser;
    int type;
    char name[0x100];
    char stack[0x100];
    int depth;
    int done;
    func_0053F5C0_Data *data;
};

extern const char *D_0064C158;
extern const char *D_0064C15C;
extern const char *D_0064C160;
extern const char *D_0064C164;
extern const char *D_0064C168;
extern const char *D_0064C16C;
extern const char *D_0064C170;
extern const char *D_0064C174;
extern const char *D_0064C178;
extern const char *D_0064C17C;
extern const char *D_0064C180;
extern const char *D_0064C184;
extern const char *D_0064C188;
extern const char *D_0064C18C;
extern char D_006C49C8[];

extern "C" {
const char *func_0053F398(char *stack, int depth) throw();
int func_00594470(const char *a, const char *b, int n);
char *func_005A6AB0(char *dst, const char *src, int n);
}

static inline void func_0053F5C0_set(char *dst, const char *s, int len) {
    func_005A6AB0(dst, s, len);
    dst[len] = 0;
}

extern "C" void func_0053F5C0(const char *s, int len, func_0053F5C0_Ctx *ctx) {
    int i = 0;
    func_0053F5C0_Data *data = ctx->data;
    const char *names[20] = {
        "major", "minor", "URLBase", "deviceType", "friendlyName", "manufacturer",
        "manufacturerURL", "modelDescription", "modelName", "modelNumber", "modelURL",
        "serialNumber", "UDN", "UPC", "serviceType", "serviceId", "controlURL",
        "eventSubURL", "SCPDURL", 0,
    };
    if (ctx->done != 0) return;
    if (len == 0) return;
    if (s[0] == ' ') return;
    const char *parent = func_0053F398(ctx->stack, ctx->depth);
    for (; names[i] != 0; i++) {
        if (func_00594470(names[i], parent, 0x100) == 0) break;
    }
    switch (i) {
    case 0:
        if (func_00594470(D_006C49C8, ctx->name, 0x100) != 0 || s[0] != '1') ctx->done = 1;
        break;
    case 1:
        if (func_00594470(D_006C49C8, ctx->name, 0x100) != 0 || s[0] != '0') ctx->done = 1;
        break;
    case 2:
        func_0053F5C0_set(data->str[0], s, len);
        break;
    case 3:
        if (func_00594470(D_0064C158, s, len) == 0) data->flags |= 0x1;
        else if (func_00594470(D_0064C15C, s, len) == 0) data->flags |= 0x2;
        else if (func_00594470(D_0064C160, s, len) == 0) {
            data->flags |= 0x4;
            func_0053F5C0_set(ctx->name, s, len);
        } else if (func_00594470(D_0064C164, s, len) == 0) data->flags |= 0x10;
        break;
    case 4:
        if (func_00594470(D_0064C160, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[1], s, len);
            data->str[1][len] = 0;
        }
        break;
    case 5:
        if (func_00594470(D_0064C160, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[2], s, len);
            data->str[2][len] = 0;
        }
        break;
    case 6:
        if (func_00594470(D_0064C160, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[3], s, len);
            data->str[3][len] = 0;
        }
        break;
    case 7:
        if (func_00594470(D_0064C160, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[4], s, len);
            data->str[4][len] = 0;
        }
        break;
    case 8:
        if (func_00594470(D_0064C160, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[5], s, len);
            data->str[5][len] = 0;
        }
        break;
    case 9:
        if (func_00594470(D_0064C160, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[6], s, len);
            data->str[6][len] = 0;
        }
        break;
    case 10:
        if (func_00594470(D_0064C160, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[7], s, len);
            data->str[7][len] = 0;
        }
        break;
    case 11:
        if (func_00594470(D_0064C160, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[8], s, len);
            data->str[8][len] = 0;
        }
        break;
    case 12:
        if (func_00594470(D_0064C160, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[9], s, len);
            data->str[9][len] = 0;
        }
        break;
    case 13:
        if (func_00594470(D_0064C160, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[10], s, len);
            data->str[10][len] = 0;
        }
        break;
    case 14:
        if (func_00594470(D_0064C16C, s, len) == 0) data->flags |= 0x20;
        else if (func_00594470(D_0064C170, s, len) == 0) data->flags |= 0x40;
        else if (func_00594470(D_0064C174, s, len) == 0) data->flags |= 0x80;
        else if (func_00594470(D_0064C178, s, len) == 0) data->flags |= 0x100;
        else if (func_00594470(D_0064C17C, s, len) == 0) data->flags |= 0x200;
        else if (func_00594470(D_0064C180, s, len) == 0) data->flags |= 0x400;
        else if (func_00594470(D_0064C184, s, len) == 0) {
            data->flags |= 0x800;
            func_0053F5C0_set(ctx->name, s, len);
        } else if (func_00594470(D_0064C188, s, len) == 0) {
            data->flags |= 0x1000;
            func_0053F5C0_set(ctx->name, s, len);
        } else if (func_00594470(D_0064C18C, s, len) == 0) data->flags |= 0x2000;
        break;
    case 15:
        if (func_00594470(D_0064C184, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[11], s, len);
            data->str[11][len] = 0;
        } else if (func_00594470(D_0064C188, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[15], s, len);
            data->str[15][len] = 0;
        }
        break;
    case 16:
        if (func_00594470(D_0064C184, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[13], s, len);
            data->str[13][len] = 0;
        } else if (func_00594470(D_0064C188, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[17], s, len);
            data->str[17][len] = 0;
        }
        break;
    case 17:
        if (func_00594470(D_0064C184, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[14], s, len);
            data->str[14][len] = 0;
        } else if (func_00594470(D_0064C188, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[18], s, len);
            data->str[18][len] = 0;
        }
        break;
    case 18:
        if (func_00594470(D_0064C184, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[12], s, len);
            data->str[12][len] = 0;
        } else if (func_00594470(D_0064C188, ctx->name, 0x100) == 0) {
            func_005A6AB0(data->str[16], s, len);
            data->str[16][len] = 0;
        }
        break;
    }
}
