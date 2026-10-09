/* compiler: ee-gcc2.96-no-strict-aliasing */
char *strcpy(char *, const char *);
void func_005A6AB0(char *, const char *, int);

typedef struct {
    char head[0x300];
    char vendor[0x100];
    char product[0x100];
    char location[0x600];
    char user[0x100];
    char password[0x100];
    char phone[0x600];
    int type;
    int mtu;
    int flags;
    char pad130C[0x14];
    unsigned char c1320;
    unsigned char c1321;
    unsigned char c1322;
    unsigned char c1323;
    unsigned char c1324;
    unsigned char c1325;
    unsigned char c1326;
    unsigned char c1327;
    unsigned char c1328;
} __attribute__((aligned(8))) NetcnfData;

typedef struct {
    int pad[20];
    NetcnfData *data;
} Conn;

void func_004ED588(Conn *conn, const char *user, const char *password) {
    conn->data->vendor[0] = 0;
    conn->data->product[0] = 0;
    conn->data->location[0] = 0;
    func_005A6AB0(conn->data->user, user, 0x100);
    func_005A6AB0(conn->data->password, password, 0x100);
    strcpy(conn->data->phone, "*");
    conn->data->type = 2;
    conn->data->mtu = 0x5AE;
    conn->data->flags = 0;
    conn->data->c1320 = 0;
    conn->data->c1323 = 1;
    conn->data->c1324 = 4;
    conn->data->c1325 = 1;
    conn->data->c1326 = 0;
    conn->data->c1327 = 0;
    conn->data->c1328 = 0;
}
