typedef long long s64;

struct Obj {
    char pad[0xA0];
    s64 unkA0;
};

extern "C" s64 SPEC_DATABASE__RaceSpec__getCourseCode(struct Obj *arg0) {
    return arg0->unkA0;
}
