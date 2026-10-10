struct G { char pad[0x2238]; int cnt; };
extern struct G D_00645570;
extern void func_00503300(int, int, int);
void func_004FFAC8(int *s) {
    func_00503300(s[2], s[1], 0);
    D_00645570.cnt++;
}
