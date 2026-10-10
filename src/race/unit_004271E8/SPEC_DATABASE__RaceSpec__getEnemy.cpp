typedef long long s64;
struct RaceSpec;
extern "C" int SPEC_DATABASE__RaceSpec__getEnemyCode(RaceSpec *, int);
extern "C" int func_00444690(void *, int);
extern "C" s64 func_00447458(RaceSpec *, int);
extern "C" void func_00445880(void *, int);

extern "C" int SPEC_DATABASE__RaceSpec__getEnemy(RaceSpec *s, int idx, void *out)
{
    int r = func_00444690(out, SPEC_DATABASE__RaceSpec__getEnemyCode(s, idx));
    s64 id = func_00447458(s, idx);
    if (id != -1) func_00445880(out, id - 1);
    else func_00445880(out, -1);
    return r;
}
