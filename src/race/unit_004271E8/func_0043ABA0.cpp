struct Obj {
    virtual int v0(int);
    virtual int v1(int);
    virtual int v2(int);
    virtual int v3(int);
};
extern "C" {
int func_0043A398(int, int);
int func_0043B380(char *, int);
int func_00437608(char *, int);
void func_00430120(char *, int);
}
extern "C" void func_0043ABA0(Obj *arg0, int arg1) {
    char *b = (char *)arg0;
    func_00430120(b + 0x3A368, func_00437608(b + 0x38CB0, func_0043B380(b + 0x348, func_0043A398(arg1, 0x10))));
    arg0->v3(arg1);
}
