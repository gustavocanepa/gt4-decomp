typedef unsigned short u16;

struct S { char pad[0x60E]; u16 unk60E; };

extern "C" u16 AutomobileGetCrashPenalty(S *arg0) {
    return arg0->unk60E;
}
