typedef int s32;

extern "C" void func_0044E030(s32 arg0, char *arg1);

extern "C" void func_0044E008(s32 arg0, char arg1) {
    char buf[2];
    buf[0] = arg1;
    buf[1] = 0;
    func_0044E030(arg0, buf);
}
