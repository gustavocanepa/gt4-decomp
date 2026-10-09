void func_0057FBEC(char *, char *);

typedef struct {
    char first[0x40];
    char second[0x40];
} NamePair;

NamePair func_004EFF48(void) {
    NamePair names;

    func_0057FBEC(names.first, names.second);
    return names;
}
