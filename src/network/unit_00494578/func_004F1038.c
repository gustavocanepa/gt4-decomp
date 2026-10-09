/* compiler: ee-gcc2.96-no-strict-aliasing */
int func_004F0C88(void);
int func_004F0CD0(void *, int);
int func_005A48D8(void *, int, int);

typedef struct {
    int pad[6];
    int size;
    int kind;
    int value;
} Request;

typedef struct {
    char pad[0x5A8];
    Request *request;
    char pad2[0xA38 - 0x5AC];
    int state;
} Session;

void func_004F1038(Session *session, int value) {
    Request *request;

    if (func_004F0C88() != 0) {
        func_005A48D8(session->request, 0, 0x24);
        request = session->request;
        request->size = 0x3FE;
        request->kind = 2;
        request->value = value;
        func_005A48D8((char *)session->request + 0x1D8, 0, 0x4E08);
        session->state = 1;
        func_004F0CD0(session, 3);
    }
}
