extern char MADHOC__SymbolMap[];
extern int MSymbolMap__getSymbolID(void *, int);

int HSymID__GetID(int arg0)
{
    return MSymbolMap__getSymbolID(MADHOC__SymbolMap, arg0);
}
