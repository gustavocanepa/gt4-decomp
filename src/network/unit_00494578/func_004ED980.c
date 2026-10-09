/* compiler: ee-gcc2.96-no-strict-aliasing */
int func_00578500(int);
int func_005A48D8(void *, int, int);
int func_005A6AB0(void *, const char *, int);
int func_00578168(void *, int, int, void *, int);
char *func_00575E60(int, int);
void func_00576B28(char *, int);
void func_00571BE0(char *, char *, int);

typedef struct {
    char *buffer;
    int value;
    int pad[2];
    char name[12];
    char text[255];
} Request;

typedef struct {
    int handle;
    int pad[15];
    Request *request;
    int pad44[3];
    char *buffer;
} Conn;

char *func_004ED980(Conn *conn, int value, const char *name, const char *text) {
    char line[0x100];

    char *buffer = conn->buffer;

    if (buffer == 0) {
        buffer = func_00575E60(0x40, 0x1340);
        conn->buffer = buffer;
    }
    func_00576B28(buffer, 0x1340);
    func_00578500(conn->handle);
    func_005A48D8(conn->request, 0, 0x20C);
    conn->request->buffer = conn->buffer;
    conn->request->value = value;
    func_005A6AB0(conn->request->name, name, 11);
    func_005A6AB0(conn->request->text, text, 255);
    func_00578168(conn, 4, 0, conn->request, 0x40);
    func_00571BE0(conn->buffer + 0xB00, line, 0x100);
    func_005A6AB0(conn->buffer + 0xB00, line, 0x100);
    return conn->request->buffer;
}
