/* Opens and connects a socket in one of four modes, retrying random ports in mode 0
   (names provisional, inferred from the code). */
struct Host { int addr; int pad; };
enum Mode { MODE_0, MODE_1, MODE_2, MODE_3 };
struct Cfg { enum Mode mode; int f4; int f8; };
struct Opts {
    long long f0;
    int type;
    int port;
    char addr[0x10];
    int f20;
    char pad24[0x24];
};
struct Reply { char pad[0x20]; int port; char pad24[0x28]; };
extern int D_0064B444;
extern unsigned int D_0064B454;
extern char D_00863EC0[], D_00863F00[];
extern unsigned int func_00539528(void);
extern void *func_005A48D8(void *p, int c, int n);
extern void func_00522428(void *addr, int host);
extern int func_00570128(char *a, char *b, int *fd, struct Opts *o);
extern int func_00570250(char *a, char *b, int fd, int timeout);
extern int func_00570410(char *a, char *b, int fd, int code);
extern int func_00570BB0(char *a, char *b, int fd, int opt, void *val, int len);

int func_00522718(int *out, struct Host host, int *port, struct Cfg *cfg, int *flag)
{
    struct Opts opts;
    struct Reply reply;
    int fd = 0;
    int on;
    int addr = host.addr;
    int timeout;
    int i;
    int one;

    *out = 0;
    if (!D_0064B444) {
        return 5;
    }
    *flag = 0;
    if (cfg->mode == 0) {
        if (!addr) {
            return 2;
        }
        if (!*port) {
            return 2;
        }
    }
    func_005A48D8(&opts, 0, sizeof(opts));
    if (cfg->mode == 0) {
        unsigned int *seed = &D_0064B454;
        unsigned int t = func_00539528();
        *seed = t;
        opts.port = t % 0xEC77 + 5000;
        one = 1;
        opts.type = one;
        opts.f20 = *port;
        timeout = 10000;
        func_00522428(opts.addr, addr);
        timeout = cfg->f8 != one ? 10000 : 0;
    } else if (cfg->mode == 1) {
        if (cfg->f4 <= 0) {
            return 2;
        }
        if (*port) {
            opts.port = *port;
        } else {
            opts.port = -1;
        }
        timeout = 10000;
        opts.f20 = 0;
        opts.f0 = cfg->f4;
        opts.type = 0;
    } else if (cfg->mode == 3) {
        opts.port = 1;
        timeout = 10000;
        opts.type = 3;
        opts.f20 = 0;
        func_00522428(opts.addr, addr);
    } else if (cfg->mode == 2) {
        opts.type = 2;
        opts.port = *port;
        timeout = 0;
        opts.f20 = 0;
        func_00522428(opts.addr, addr);
    } else {
        return 4;
    }
    if (func_00570128(D_00863EC0, D_00863F00, &fd, &opts)) {
        if (cfg->mode != 0) goto fail;
        i = 0;
        while (1) {
            unsigned int t = func_00539528();
            D_0064B454 = t;
            i++;
            opts.port = t % 0xEC77 + 5000;
            if (!func_00570128(D_00863EC0, D_00863F00, &fd, &opts)) goto opened;
            if (i >= 5) break;
        }
    fail:
        /* placed here, not at the end: that gives the original's empty slot after the retry loop */
        return 0xC350;
    }
opened:
    {
        int r = func_00570250(D_00863EC0, D_00863F00, fd, timeout);
        if (r && (r != -500 || cfg->mode != 2)) {
            func_00570410(D_00863EC0, D_00863F00, fd, 500);
            goto fail;
        }
    }
    if (cfg->mode == 0 || cfg->mode == 2) {
        on = 1;
        if (func_00570BB0(D_00863EC0, D_00863F00, fd, 3, &on, 4)) goto fail;
    }
    if (cfg->mode == 1 && *port == 0) {
        func_005A48D8(&reply, 0, sizeof(reply));
        if (func_00570BB0(D_00863EC0, D_00863F00, fd, 1, &reply, sizeof(reply)) >= 0) goto fail;
        *port = reply.port;
    }
    if (cfg->mode == 0 && cfg->f8 == 1) {
        *flag = 0;
    } else {
        *flag = 1;
    }
    *out = fd;
    return 0;
}
