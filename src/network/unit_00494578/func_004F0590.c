int func_00579358(void);
void func_005792E8(void *, int);
float mBlockTransition__getBlock(void *, float, float);
void func_005A48D8(void *, int, int);
void func_0052E510(void *);
int func_0052E568(void *, void *);
void func_004F8820(void *, int);
void func_00577F80(void);
int func_004F8C40(void *);
int func_004F96C8(void *);
void func_004F7090(void);

typedef struct {
    int pad0;
    int port;
    char pad8[0x4C];
    char *server;
    char *host;
    int timeout;
    int zero60;
    int mode;
    int zero68;
    int pad6C;
    void (*callback)(void);
    void *callback_data;
} ConnectRequest;

typedef struct {
    int port;
    int pad[2];
} Client;

static inline int client_port(Client *c) {
    return c->port;
}

typedef struct {
    char pad[0x40];
    Client client;
    char host[0x80];
    char server[0x88];
    int mode;
} Session;

int func_004F0590(Session *s, int wait) {
    char timer[0x10];
    ConnectRequest request;
    char reply[0x18];
    int result = 0;
    int error;

    func_005792E8(timer, func_00579358());
    do {
        func_005A48D8(&request, 0, 0x78);
        func_005A48D8(reply, 0, 0x18);
        func_0052E510(&request);
        request.port = client_port(&s->client);
        request.host = s->host;
        request.zero60 = 0;
        request.mode = s->mode;
        request.zero68 = 0;
        request.callback = func_004F7090;
        request.callback_data = s;
        if (s->mode == 0) {
            request.server = s->server;
            request.timeout = (int)mBlockTransition__getBlock(timer, 5000.0f, 6000.0f);
        }
        error = func_0052E568(&request, reply);
        if (error == 0) {
            result = 1;
            break;
        }
        func_004F8820(s, error);
        func_00577F80();
    } while (wait);
    if (!result) {
        return 0;
    }
    do {
        if (func_004F8C40(s)) {
            break;
        }
        func_00577F80();
    } while (wait);
    do {
        result = func_004F96C8(s);
        if (result) {
            break;
        }
        func_00577F80();
    } while (wait);
    return result;
}
