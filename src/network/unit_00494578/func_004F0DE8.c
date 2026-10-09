int func_004F0C88(void);
void func_005A48D8(void *, int, int);
void func_004F0CD0(void *, int);
void func_004F8128(void);
void func_004F6D40(void);
void func_004F6E28(void);
void func_004F6EE8(void);
void func_004F7090(void);

typedef struct {
    int field[16];
} Callbacks;

typedef struct {
    char pad[0x40];
    int port;
    int pad44[2];
    char host[0x80];
    char server[0x88];
    int mode;
    char pad158[0x5A8 - 0x158];
    Callbacks *callbacks;
} Session;

void func_004F0DE8(Session *s, int mode) {
    Callbacks *cb;

    if (func_004F0C88() == 0) {
        return;
    }
    func_005A48D8(s->callbacks, 0, 0x40);
    cb = s->callbacks;
    s->mode = mode;
    cb->field[2] = (int)s;
    cb->field[14] = (int)s->host;
    cb->field[0] = mode ? 0 : (int)s->server;
    cb->field[1] = (int)func_004F8128;
    cb->field[5] = (int)func_004F6D40;
    cb->field[7] = (int)func_004F6E28;
    cb->field[6] = (int)s;
    cb->field[9] = (int)func_004F6EE8;
    cb->field[11] = (int)func_004F7090;
    cb->field[12] = (int)s;
    cb->field[13] = s->port;
    func_004F0CD0(s, 1);
}
