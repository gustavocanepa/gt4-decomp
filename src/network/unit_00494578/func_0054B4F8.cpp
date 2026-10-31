/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Under the D_0064C3E4 lock: queries slot id (func_00562020 on id/4, id%4),
   stores the result in *out when it is not negative, records the status in the
   slot record (func_00549858) and returns it; sibling of func_0054B9F0. */
extern char *D_0064C3E4;
extern "C" int func_0054A370(int) throw();
extern "C" int func_0054A8A8(int,int) throw() __attribute__((const));
extern "C" void func_00549858(char *,int,int) throw();
extern "C" int func_00562020(int,int,int);
extern "C" void func_00576788(char *);
extern "C" void func_005767C0(char *);
extern "C" int func_0054B4F8(int id,int a,int *out) {
    int status=1;
    func_00576788(D_0064C3E4+0x34);
    *out=0;
    if (func_0054A370(id)) {
        int q=id/4;
        int r=id%4;
        int result=func_00562020(q,r,a);
        if(result>=0) {
            *out=result;
            status=0;
        }
        status=func_0054A8A8(status,result);
        int offset=(q*111+r*27)*4;
        func_00549858((char *)(offset+(int)D_0064C3E4)+0x78,result,status);
        *((char *)(offset+(int)D_0064C3E4)+0x78)=0;
    }
    func_005767C0(D_0064C3E4+0x34);
    return status;
}
