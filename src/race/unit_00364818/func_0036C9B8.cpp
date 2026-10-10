
struct func_0036C9B8_Obj { unsigned char pad[0x546]; unsigned char k; };
extern "C" int func_0036C9B8(func_0036C9B8_Obj *p) {
    switch (p->k) {
    case 0: case 2: return 0;
    case 1: case 3: case 4: case 5: case 6: return 1;
    default: return 0;
    }
}
