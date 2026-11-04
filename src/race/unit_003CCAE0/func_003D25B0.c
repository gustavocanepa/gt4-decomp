/* Picks an entry's follow-up: active entries with fewer than two of six slots off state 2 go to
   func_003D2550, others to func_003D1BE0, unknown ones to func_003D1BA0. The bound is set again in
   the loop so gcse cannot fold it, and loop.c counts down from it (li 6 / bnez) as in retail. */
struct S { char pad[0x3C]; int x3C[0x30]; int fc[6]; };
int func_0034C750(int);
int Pitmen__isValid(void);
void func_003D1BA0(struct S *, int, int);
void func_003D1BE0(struct S *, int, int, int);
void func_003D2550(struct S *, int, int, int);
int Pitmen__isRenderPitmenPeriod(struct S *, int);
void func_003D25B0(struct S *self, int id, int a, int b) {
    int i, n, c;
    if (Pitmen__isValid() != 0 && func_0034C750(a) != 0) {
        if (Pitmen__isRenderPitmenPeriod(self, id) != 0) {
            if (self->x3C[id] != 0) {
                n = 0;
                c = 6;
                for (i = 0; i < c; i++) {
                    if (self->fc[i] != 2)
                        n++;
                    c = 6;
                }
                if (n < 2) {
                    func_003D2550(self, id, a, b);
                    return;
                }
            }
            func_003D1BE0(self, id, a, b);
        } else
            func_003D1BA0(self, a, b);
    }
}
