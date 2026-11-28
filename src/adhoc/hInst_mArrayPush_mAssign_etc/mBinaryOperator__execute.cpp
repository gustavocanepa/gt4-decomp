/* compiler: ee-gcc2.96-no-strict-aliasing */
/* mBinaryOperator::execute: pops both operands, calls the operator's member function on the left
   operand (or on a nil object when either operand is empty) and pushes the result. */
typedef int s32;

struct Object;
extern "C" void func_003285A8(Object *);
extern "C" void func_003285F8(Object *);

struct Value {
    Object *p;
    Value() __asm__("func_0030BB18");
    Value(const Value &);
    ~Value() __asm__("func_00309378");
    Object *get() const { return p; }
    Value &operator=(const Value &o) {
        if (this != &o) {
            Object *n = o.p;
            if (n) func_003285A8(n);
            if (p) func_003285F8(p);
            p = n;
        }
        return *this;
    }
};
struct Nil : Value {
    Nil() __asm__("func_00300A60");
    ~Nil() __asm__("func_003005D8");
};
struct Object {
    s32 refCount;
};
typedef void (Object::*Operator)(Value *result, Value *self, int argc, Value *argv);

/* Takes the pointer by const reference: the temporary it binds to lives in memory until the
   address-of purge, and that store keeps the first CSE pass from reusing the left operand's
   pointer as the receiver (the second pass then leaves the original's register copy). */
static inline bool isNull(Object *const &p) { return p == 0; }
struct Stack {
    char pad[0x14];
    Value *items;
    char pad2[8];
    s32 count;
    Value &pop() { return items[--count]; }
    void push(const Value &v) { items[count] = v; ++count; }
};
struct Thread {
    char pad[0x2C];
    Stack *stack;
};
struct mBinaryOperator {
    char pad[0xC];
    Operator op;
};

extern "C" void mBinaryOperator__execute(mBinaryOperator *self, Thread *thread) {
    Value &right = thread->stack->pop();
    Value &left = thread->stack->pop();
    Value result;
    if (left.get() == 0 || isNull(right.get())) {
        Nil nil;
        (nil.get()->*self->op)(&result, &left, 1, &right);
    } else {
        (left.get()->*self->op)(&result, &left, 1, &right);
    }
    thread->stack->push(result);
}
