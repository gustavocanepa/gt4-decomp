struct Self { char pad[0x24]; char name[1]; };
extern char D_00694E80[];
extern "C" int func_0057DA20(char *, const char *, ...);

extern "C" char *func_001CF3C0(Self *self, char *buf) {
    func_0057DA20(buf, D_00694E80, self->name);
    return buf;
}
