// 1. Break circular reference:
struct Node {
    shared_ptr<Node> next;
    weak_ptr<Node> prev;   // weak to break the cycle
};

struct Node {
    shared_ptr<Node> next;
    weak_ptr<Node> prev;
}
class EventSystem {
    vector<weak_ptr<Listener>> listeners;
    public:
        void notify() {
            for ( auto& wl : listeners){
                if (auto l = wl.lock()){
                    l->onEvent();
                }
            }
        }
}
// If prev were shared_ptr, A→B and B→A would never be freed

// 2. Observer pattern (safe non-owning handle):
class EventSystem {
    vector<weak_ptr<Listener>> listeners;
public:
    void notify() {
        for (auto& wl : listeners) {
            if (auto l = wl.lock()) {  // lock() → shared_ptr or nullptr
                l->onEvent();           // safe: l is alive
            }
            // expired listeners are just skipped
        }
    }
};

weak_ptr<int> w = make_shared<int>(42);
if (auto s = w.lock()) { /* use s */ }  // always check before use