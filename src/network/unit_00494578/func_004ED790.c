void func_005A6AB0(void *, const char *, int);

typedef struct {
    int pad[20];
    unsigned char *buffer;
} Conn;

void func_004ED790(Conn *conn, int enable, int keep, const char *user, const char *password) {
    conn->buffer[0x600] = 0;
    conn->buffer[0x700] = 0;
    if (keep == 0) {
        if (user != 0) {
            func_005A6AB0(conn->buffer + 0x600, user, 0x100);
        }
        if (password != 0) {
            func_005A6AB0(conn->buffer + 0x700, password, 0x100);
        }
    }
    if (enable != 0 && keep != 0) {
        conn->buffer[0x1321] = 1;
    } else {
        conn->buffer[0x1321] = -1;
    }
    conn->buffer[0x1322] = conn->buffer[0x1321];
}
