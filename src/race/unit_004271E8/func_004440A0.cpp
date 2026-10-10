struct Entry { int key; int value; };
extern "C" Entry D_006237A0[];

extern "C" int func_004440A0(void *self, int key)
{
    int r = D_006237A0[0].value; for (int i = 0; D_006237A0[i].key != -1; i++) { if (D_006237A0[i].key == key) { r = D_006237A0[i].value; break; } } return r;
}
