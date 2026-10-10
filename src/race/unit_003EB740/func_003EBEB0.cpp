extern "C" unsigned int func_00426A68(void *);
extern "C" int func_004269D0(void *, unsigned int);
extern "C" void func_00476380(void *, int);
extern "C" int func_00476478(void *, int);

extern "C" bool func_003EBEB0(void *o, void *pad, unsigned int mask, int c)
{
    if (func_00426A68(pad) & mask) {
        func_00476380(o, c);
    } else if (func_004269D0(pad, mask)) {
        func_00476478(o, c);
    } else {
        return false;
    }
    return true;
}
