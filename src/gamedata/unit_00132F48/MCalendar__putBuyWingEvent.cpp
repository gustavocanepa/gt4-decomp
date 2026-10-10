struct Str {
    char *p;
    int length() const { return ((int *)p)[-4]; }
    const char *c_str() const {
        if (length() == 0)
            return "";
        p[length()] = 0;
        return p;
    }
};

struct Data { char pad[0x10]; int id; };

extern "C" void func_00132DB8(void *self, void *src);
extern "C" void func_00132D60(void *self, int flags);
extern "C" void func_00312370(void *self, void *argv);
extern "C" void func_00312318(void *self, int flags);
extern "C" Str *func_00314920(void *rep);
extern "C" void func_0042F408(int id, const char *name);

extern "C" void MCalendar__putBuyWingEvent(void *ret, void *self, int argc, void *argv) {
    if (argc > 0) {
        int buf[4];
        int id;
        func_00132DB8(buf, self);
        id = ((Data *)buf[0])->id;
        func_00132D60(buf, 2);
        func_00312370(buf, argv);
        func_0042F408(id, func_00314920((void *)buf[0])->c_str());
        func_00312318(buf, 2);
    }
}
