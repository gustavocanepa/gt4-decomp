/* compiler: ee-gcc2.96-no-strict-aliasing */
int func_004ED318(void *, int, const char *);
int func_00578500(int);
int func_005A48D8(void *, int, int);
int func_005A6AB0(void *, const char *, int);
int func_00578168(void *, int, int, void *, int);
char *func_00575E60(int, int);
void func_00576B28(char *, int);
void func_00575DA0(void *);

typedef struct {
    char *buffer;
    int value;
    int pad[2];
    char name[12];
} Request;

typedef struct {
    int handle;
    int pad[15];
    Request *request;
} Conn;

int func_004ED888(Conn *conn, int value, const char *name, char **buffer, int entry_size) {
    int count = func_004ED318(conn, value, name);

    if (count <= 0) {
        return count;
    }
    entry_size *= count;
    if (*buffer) {
        func_00575DA0(*buffer);
        *buffer = 0;
    }
    *buffer = func_00575E60(0x40, entry_size);
    func_00576B28(*buffer, entry_size);
    func_00578500(conn->handle);
    func_005A48D8(conn->request, 0, 0x20C);
    conn->request->buffer = *buffer;
    conn->request->value = value;
    func_005A6AB0(conn->request->name, name, 11);
    func_00578168(conn, 2, 0, conn->request, 0x40);
    return (int)conn->request->buffer;
}
