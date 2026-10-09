extern "C" int func_00448A58(void *arg0, void *buf);

struct Dest {
    long long f0;
    long long f8;
    long long f10;
};

extern "C" int func_00448820(void *arg0, Dest *dest) {
    long long buf[3];
    if (func_00448A58(arg0, buf) != 0) {
        dest->f0 = buf[0];
        dest->f8 = buf[1];
        dest->f10 = buf[2];
        return 1;
    }
    return 0;
}
