typedef unsigned int u32;

extern "C" void func_00613DD8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D62D8;

extern int D_008A0110;

extern "C" void *func_0060FA50(void) {
    if (D_008A0110 == 0) {
        func_00613DD8();
        func_005BFB68(&D_008A0110, ((char *)"Q26PDISTDt12ListManagerT1ZQ27PDICOMM10rtCommSock"), &D_006D62D8);
    }
    return &D_008A0110;
}
