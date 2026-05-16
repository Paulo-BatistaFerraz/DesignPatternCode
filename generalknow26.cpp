template<typename T>
class Box{
    T item;
    public:
        void put(T x){item = x;}
        T get(){return item;}
};


template<>
class Box<string> {
    string item;
    public:
    void put(string x){
        cout << "string " << x << endl;
        item = x;
    }
    string get(){return item;}
};

template<typename T>
class Box<T*> {
    T* item; // pointer to the item
    public: 
    void put(T* x){
        cout << "storing pointer to " << *x << endl;
        item = x;
    }
    T* get(){return item;}
};


Stack<string, vector<string>> s1;
stack<int, vector<int>> s2;

template<typename T>
using MyStack = Stack<T, vector<T>>;

MyStack<string> s3;
MyStack<int> s4;

std::vector<bool> v = {true, false, true};
auto x = v[0];




int main(){
    Box<int> b;
    b.put(10);
    cout << b.get() << endl;
    Box<string> s;
    s.put("Hello");
    cout << s.get() << endl;
    Box<int*> p; // Box points to p
    int x = 10;
    p.put(&x);
    cout << *p.get() << endl;
}