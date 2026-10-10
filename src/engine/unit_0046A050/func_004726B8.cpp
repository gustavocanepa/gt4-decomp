extern const char D_006AD370[], D_006AD378[], D_006AD380[], D_006AD388[], D_006AD390[], D_006AD398[], D_006AD3A0[], D_006AD3A8[];
struct func_004726B8_Obj { int pad; int k; };
extern "C" const char *func_004726B8(func_004726B8_Obj *p) {
    switch (p->k) {
    case 0: return D_006AD370;
    case 1: return D_006AD378;
    case 2: return D_006AD380;
    case 3: return D_006AD388;
    case 5: return D_006AD390;
    case 4: return D_006AD398;
    case 6: return D_006AD3A0;
    default: return D_006AD3A8;
    }
}
