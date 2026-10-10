struct Entry {
    char pad[8];
    float value;
    char pad2[0x24];
};

extern "C" int func_004331F8(Entry *e, float x)
{
    int i;
    for (i = 0; i < 10; i++) {
        if (e[i].value == 0.0f || e[i].value < x)
            break;
    }
    int ok = i < 10;
    return ok ? i : -1;
}
