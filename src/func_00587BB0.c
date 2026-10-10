/* compiler: ee-gcc2.9-991111 */
typedef struct Ctx {
    int unk0;
    int unk4;
    int doneSema;
    int idleSema;
    int request;
} Ctx;

extern Ctx D_0087E180;
extern int func_005ADBC0(void);
extern int func_00587C08(int);
extern int func_005ADCC0(int);

void func_00587BB0(void *arg) {
    for (;;) {
        func_005ADBC0();
        if (func_00587C08(D_0087E180.request)) {
            D_0087E180.request = 0;
            func_005ADCC0(D_0087E180.doneSema);
        } else {
            func_005ADCC0(D_0087E180.idleSema);
        }
    }
}
