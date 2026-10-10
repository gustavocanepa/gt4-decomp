typedef int s32;

extern "C" const char *func_001CC958(s32 id);
extern "C" char *func_005A609C(char *dst, const char *src);
extern "C" void func_001CBE60(char *dst, s32 id, s32 n);

extern "C" void func_001CD8A0(s32 id, s32 kind, char *out) {
    func_005A609C(out, func_001CC958(id));
    out += 0xC;
    *out++ = kind;
    func_001CBE60(out, id, 7);
}
