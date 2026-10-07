typedef int s32;

struct Out {
    s32 unk0;
    s32 unk4;
};

extern "C" void func_0045B368(Out *out, s32 arg1, s32 arg2, const char *name);
extern "C" void func_003C2A58(s32 arg0, s32 arg1);

extern "C" void func_0033A5B8(s32 arg0, s32 arg1, s32 arg2) {
    Out sp;

    func_0045B368(&sp, arg1, arg0, "GDGT");
    if (sp.unk4 >= 0) {
        func_003C2A58(arg2, arg0);
    }
}
