/* compiler: ee-gcc2.96-no-strict-aliasing */
int func_00578500(int);
int func_005A48D8(void *, int, int);
int func_005A6AB0(void *, const char *, int);
int func_00578168(void *, int, int, void *, int);

typedef struct {
    int value;
    int pad[3];
    char name[12];
    char text[255];
} Request;

typedef struct {
    int handle;
    int pad[15];
    Request *request;
} Conn;

int func_004EDC38(Conn *conn, int value, const char *name, const char *text) {
    func_00578500(conn->handle);
    func_005A48D8(conn->request, 0, 0x20C);
    conn->request->value = value;
    func_005A6AB0(conn->request->name, name, 11);
    func_005A6AB0(conn->request->text, text, 255);
    func_00578168(conn, 7, 0, conn->request, 0x40);
    return conn->request->value;
}
