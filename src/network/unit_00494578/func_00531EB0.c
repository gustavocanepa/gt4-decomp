/* Sends one message through the network API table (slot 0x30); a port of -1 means the
   default port 0xFFFE. On failure the error is reported and mapped by func_00535780.
   The port is fixed up through its own address: that keeps the parameter addressable in the C
   front end until after CSE, so the test becomes a late conditional move (li -1, xor, movz)
   instead of the early nor + movn. */
typedef struct Api Api;
typedef struct Conn Conn;
struct Api { char pad[0x30]; int (*send)(int handle, int port, char channel, int arg, unsigned short id); };
struct Conn { char pad[0x160]; int handle; };
extern Api *D_0064B4A8;
extern const char D_006C35C8[];
void func_0057D9C0(const char *fmt, ...);
int func_00535780(int);
int func_00531EB0(char channel, Conn *conn, int port, int id, int arg) {
    int r;
    if (*&port == -1) *&port = 0xFFFE;
    r = D_0064B4A8->send(conn->handle, port, channel, arg, id);
    if (r != 0) {
        func_0057D9C0(D_006C35C8, r);
        return func_00535780(r);
    }
    return r;
}
