struct func_00557838_Vec {
    double v[6];
};

struct func_00557838_Dev {
    int port;
    unsigned char line[0x40];
    unsigned char *wp;
    char pad48[0x268 - 0x48];
    int values[6];
};

extern char D_00655290[];
extern "C" int func_00566FF8(void *ctx, int port, char *buf, int size);
extern "C" void *func_005A4724(void *dst, const void *src, unsigned int n);
extern "C" char *func_005A5EF4(const char *s, int c);
extern "C" void func_00556EA0(func_00557838_Dev *self) throw();
extern "C" int func_00594470(const char *a, const char *b, unsigned int n);
extern "C" void func_00556F30(func_00557838_Dev *self) throw();
extern "C" void func_00556E48(func_00557838_Dev *self, func_00557838_Vec *v) throw();
extern "C" int func_005A5AD8(const char *s, const char *fmt, ...);
extern "C" void *func_005A48D8(void *dst, int c, unsigned int n);

extern "C" void func_00557838(func_00557838_Dev *self) {
    char buf[0x40];
    int n = func_00566FF8(D_00655290, self->port, buf, 0x40);
    if (n == 0) return;
    if (self->wp + n >= (unsigned char *)&self->wp) {
        self->wp = self->line;
        return;
    }
    func_005A4724(self->wp, buf, n);
    self->wp += n;
    if (func_005A5EF4((char *)self->line, '\n') == 0) return;
    if (self->line[0] == 'E') {
        func_00556EA0(self);
    } else if (self->line[0] == 'D') {
        switch (self->line[1]) {
        case 'E':
        case 'F':
            break;
        case 'M':
            if (func_00594470((char *)self->line, "DM  3  3  3  3  3  3", 0x14) == 0) {
                func_00557838_Vec v = { { 100.0, 100.0, 100.0, 0.0, 0.0, 0.0 } };
                func_00556F30(self);
                func_00556E48(self, &v);
            }
            break;
        case 'G':
            func_005A5AD8((char *)self->line, "%s %d %d %d %d %d %d", buf, &self->values[0], &self->values[1], &self->values[2], &self->values[3], &self->values[4], &self->values[5]);
            break;
        case 'V':
            break;
        }
    }
    func_005A48D8(self->line, 0, 0x40);
    self->wp = self->line;
}
