typedef unsigned long long u64;

/* GS TEX0, TEX1 and CLAMP registers (bitfields as in the GS manual). */
struct func_0049AFD0_Tex0 {
    u64 tbp0 : 14;
    u64 tbw : 6;
    u64 psm : 6;
    u64 tw : 4;
    u64 th : 4;
    u64 tcc : 1;
    u64 tfx : 2;
    u64 cbp : 14;
    u64 cpsm : 4;
    u64 csm : 1;
    u64 csa : 5;
    u64 cld : 3;
};

struct func_0049AFD0_Tex1 {
    u64 lcm : 1;
    u64 pad1 : 1;
    u64 mxl : 3;
    u64 mmag : 1;
    u64 mmin : 3;
    u64 mtba : 1;
    u64 pad10 : 9;
    u64 l : 2;
    u64 pad21 : 11;
    u64 k : 12;
    u64 pad44 : 20;
};

struct func_0049AFD0_Clamp {
    u64 wms : 2;
    u64 wmt : 2;
    u64 minu : 10;
    u64 maxu : 10;
    u64 minv : 10;
    u64 maxv : 10;
    u64 pad44 : 20;
};

struct func_0049AFD0_Regs {
    func_0049AFD0_Tex0 tex0;
    func_0049AFD0_Tex1 tex1;
    u64 pad10[2];
    func_0049AFD0_Clamp clamp;
};

extern "C" void func_0049AFD0(func_0049AFD0_Regs *r, unsigned int field, int v) {
    switch (field) {
    case 0:
        r->tex0.tcc = v;
        break;
    case 1:
        r->tex0.tfx = v;
        break;
    case 2:
        r->tex1.mmin = v;
        break;
    case 3:
        r->tex1.mmag = v;
        break;
    case 4:
        r->clamp.wms = v;
        break;
    case 5:
        r->clamp.wmt = v;
        break;
    case 6:
        r->tex1.lcm = v;
        break;
    case 7:
        r->tex1.mxl = v;
        break;
    case 8:
        r->tex1.k = v;
        break;
    case 9:
        r->tex1.l = v;
        break;
    }
}
