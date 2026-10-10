typedef int s32;
typedef long long s64;
extern char D_006235A8[];
s32 SPEC_DATABASE__DatabaseStorage__IsExistID(char *a);
s32 SPEC_DATABASE__RaceSpec__setCourse(char *arg0, s64 arg1) {
    if (SPEC_DATABASE__DatabaseStorage__IsExistID(D_006235A8) == 0) return 0;
    *(s64 *)(arg0 + 0xA0) = arg1;
    return 1;
}
