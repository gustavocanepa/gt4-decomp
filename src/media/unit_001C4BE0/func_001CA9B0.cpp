extern const char D_00693F88[], D_00693F98[], D_00693FA0[], D_00693FA8[], D_00693FB0[],
    D_00693FB8[], D_00693FC0[], D_00693FC8[], D_00693FD0[], D_00693FE0[], D_00693FF0[],
    D_00694008[], D_00694020[], D_00694028[];

struct func_001CA9B0_Obj {
    char pad[0x6C];
    int kind;
};

extern "C" const char *func_001CA9B0(func_001CA9B0_Obj *p) {
    switch (p->kind) {
    case -1: return D_00693F88;
    case 42: return D_00693F98;
    case 37: return D_00693FA0;
    case 39: return D_00693FA8;
    case 38: return D_00693FB0;
    case 54: return D_00693FB8;
    case 50: return D_00693FC0;
    case 51: return D_00693FC8;
    case 43: return D_00693FD0;
    case 76: return D_00693FE0;
    case 77: return D_00693FF0;
    case 80: return D_00694008;
    case 57: return D_00694020;
    default: return D_00694028;
    }
}
