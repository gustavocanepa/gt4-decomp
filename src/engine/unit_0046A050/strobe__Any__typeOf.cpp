/* strobe (Flash player) Any::typeOf: the ActionScript type name of a value. */
extern const char D_006AD760[]; /* "function" */
extern const char D_006AD770[]; /* "null" */
extern const char D_006AD778[]; /* "string" */
extern const char D_006AD780[]; /* "boolean" */
extern const char D_006AD788[]; /* "number" */
extern const char D_006AD790[]; /* "object" */
extern const char D_006AD798[]; /* "movieclip" */
extern const char D_006AD7A8[]; /* "undefined" */
extern const char D_006AD7B8[]; /* "unknown..." */

struct Any {
    int type;
    int getType() const { return type; }
    /* Separate inline predicates: the range test is not folded into one unsigned compare
       and the first comparison is materialised as a value (slti; xori 1; xori 0; movn). */
    bool isFunctionFirst() const { return getType() >= 13; }
    bool isFunction() const { return isFunctionFirst() && getType() < 28; }
};

extern "C" const char *strobe__Any__typeOf(Any *a) {
    if (a->isFunction())
        return D_006AD760;
    switch (a->getType()) {
    case 0: return D_006AD770;
    case 3: case 4: return D_006AD778;
    case 5: return D_006AD780;
    case 6: return D_006AD788;
    case 7: case 8: return D_006AD790;
    case 10: return D_006AD798;
    case 1: return D_006AD7A8;
    default: return D_006AD7B8;
    }
}
