void func_004F0F50(void *, int);
void func_004EFEF0(void *);
int func_004F0590(void *, int);
int func_004F0750(void *, int);
void func_005034B0(void *);
void func_004F08B8(void *);
void func_004EFF40(void *);
void func_004F0320(void *);

typedef struct {
    char pad[0x3C];
    int connected;
    char client[0x114];
    int mode;
} Session;

int func_004F04C8(Session *s, int mode, int param) {
    if (s->connected) {
        return 1;
    }
    s->mode = mode;
    func_004F0F50(s, 1);
    func_004EFEF0(s->client);
    if (func_004F0590(s, param)) {
        if (s->mode != 0 || func_004F0750(s, param)) {
            func_005034B0(s);
            s->connected = 1;
            return 1;
        }
        func_004F08B8(s);
    }
    func_004EFF40(s->client);
    func_004F0320(s);
    return 0;
}
