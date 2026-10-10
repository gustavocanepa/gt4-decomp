typedef unsigned char u8;
typedef unsigned short u16;

extern "C" void func_002FFAF0(void *arg0, u8 arg1);

extern "C" void func_002FFB18(void *arg0, u16 arg1) {
    func_002FFAF0(arg0, arg1 & 0xFF);
    func_002FFAF0(arg0, arg1 >> 8);
}
