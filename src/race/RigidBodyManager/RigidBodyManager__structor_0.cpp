typedef unsigned int size_t;

extern "C" void *func_005C15B0(size_t n); /* operator new[] */

struct RigidBody {
    int state;
    char pad4[0x5C];
    RigidBody() : state(0) {}
    static void *operator new[](size_t n) { return func_005C15B0(n); }
};

class RigidBodyManager {
public:
    RigidBodyManager();
    virtual ~RigidBodyManager();

    RigidBody *bodies;
    int capacity;
    int pad8[2];
    int count;
};

RigidBodyManager::RigidBodyManager() : capacity(160)
{
    bodies = new RigidBody[160];
    count = 0;
}
