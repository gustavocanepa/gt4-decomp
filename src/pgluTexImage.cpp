typedef unsigned long long u64;

/* GS TEX0 and MIPTBP1/2 register images (libgraph sceGsTex0 / sceGsMiptbp1 layouts) */
struct func_0049AC98_Tex0 {
    u64 TBP0 : 14;
    u64 TBW : 6;
    u64 PSM : 6;
    u64 TW : 4;
    u64 TH : 4;
    u64 TCC : 1;
    u64 TFX : 2;
    u64 CBP : 14;
    u64 CPSM : 4;
    u64 CSM : 1;
    u64 CSA : 5;
    u64 CLD : 3;
};

struct func_0049AC98_Miptbp {
    u64 TBP1 : 14;
    u64 TBW1 : 6;
    u64 TBP2 : 14;
    u64 TBW2 : 6;
    u64 TBP3 : 14;
    u64 TBW3 : 6;
    u64 pad : 4;
};

struct func_0049AC98_Obj {
    func_0049AC98_Tex0 tex0;
    u64 tex1;
    func_0049AC98_Miptbp miptbp1;
    func_0049AC98_Miptbp miptbp2;
};

extern "C" void pgluTexImage(func_0049AC98_Obj *self, int level, unsigned int addr, unsigned int psm, int width) {
    unsigned int tbp = addr >> 6;
    int tbw = width >> 6;
    switch (level) {
    case 0:
        self->tex0.TBP0 = tbp;
        self->tex0.TBW = tbw;
        self->tex0.PSM = psm;
        self->tex0.TCC = 1;
        break;
    case 1:
        self->miptbp1.TBP1 = tbp;
        self->miptbp1.TBW1 = tbw;
        break;
    case 2:
        self->miptbp1.TBP2 = tbp;
        self->miptbp1.TBW2 = tbw;
        break;
    case 3:
        self->miptbp1.TBP3 = tbp;
        self->miptbp1.TBW3 = tbw;
        break;
    case 4:
        self->miptbp2.TBP1 = tbp;
        self->miptbp2.TBW1 = tbw;
        break;
    case 5:
        self->miptbp2.TBP2 = tbp;
        self->miptbp2.TBW2 = tbw;
        break;
    case 6:
        self->miptbp2.TBP3 = tbp;
        self->miptbp2.TBW3 = tbw;
        break;
    }
}
