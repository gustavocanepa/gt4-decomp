extern char MADHOC__SymbolMap[];
extern int MSymbolMap__getSymbolName(void *, int);

int HSymID__GetName(int arg0)
{
    return MSymbolMap__getSymbolName(MADHOC__SymbolMap, arg0);
}
