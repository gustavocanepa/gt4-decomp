struct func_004AD1C8 { char pad0[0xC]; int mC; char pad10[0x94]; func_004AD1C8(); virtual ~func_004AD1C8(); };
extern char D_006B02B0[];
struct D_00689050 : func_004AD1C8 { const char *name; int mAC; D_00689050(const char *name, int b, int c); virtual ~D_00689050(); };
D_00689050::D_00689050(const char *n, int b, int c) : name(n ? n : D_006B02B0), mAC(b) {
    mC = c;
}
