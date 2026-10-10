typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct Date_0042E660 {
    s16 year;
    u8 month;
    u8 day;
};

extern "C" void func_005A6AB0(char *dst, const char *src);
extern "C" s32 func_005A5A30(char *buf, s32 size, const char *fmt, ...);
extern "C" char D_006A4FC0[];
extern "C" char D_006A4FC8[];

extern "C" void func_0042E660(Date_0042E660 *date, char *buf, s32 size) {
    if (date == 0) {
        return func_005A6AB0(buf, D_006A4FC0);
    }
    func_005A5A30(buf, size, D_006A4FC8, date->year, date->month, date->day);
}
