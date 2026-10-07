extern "C" int func_0057F6F8(long long arg0, long long arg1) {
    register long long a0 asm("$4") = arg0;
    register long long a1 asm("$5") = arg1;
    register int v0 asm("$2");
    __asm__ volatile (
        "addiu $3, $0, 0x7FF\n"
        "dsll $6, $4, 1\n"
        "dsll32 $3, $3, 21\n"
        "dsll $7, $5, 1\n"
        "dsrl32 $8, $6, 21\n"
        "dsrl32 $9, $7, 21\n"
        "movz $6, $0, $8\n"
        "movz $7, $0, $9\n"
        "dsra32 $12, $4, 31\n"
        "dsra32 $13, $5, 31\n"
        "dsrl $10, $12, 1\n"
        "dsrl $11, $13, 1\n"
        "xor $4, $4, $10\n"
        "xor $5, $5, $11\n"
        "sltu $8, $3, $6\n"
        "sltu $9, $3, $7\n"
        "slt $10, $4, $5\n"
        "slt $11, $5, $4\n"
        "xor $24, $6, $7\n"
        "xor $15, $6, $3\n"
        "dsub $25, $12, $13\n"
        "or $1, $15, $24\n"
        "or $14, $8, $9\n"
        "movn $25, $0, $1\n"
        "dsub $2, $11, $10\n"
        "movz $2, $25, $24\n"
        "movn $2, $14, $14\n"
        : "=r"(v0), "+r"(a0), "+r"(a1)
        :
        : "$3", "$6", "$7", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "$1"
    );
    return v0;
}
