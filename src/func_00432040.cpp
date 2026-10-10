/* compiler: ee-gcc2.96-as2004 */
struct Entry {
    unsigned int id;
    char pad4[0x28];
};

extern "C" int func_00432040(Entry *e, unsigned int key) {
    int i;
    for (i = 0; i < 10; i++) {
        if (e[i].id == 0x157529FF || key < e[i].id)
            break;
    }
    return i < 10 ? i : -1;
}
