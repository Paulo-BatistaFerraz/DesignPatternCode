class Singleton{
    static Singleton* getInstance(){
        static Singleton object;
        return &object;
    }
    Singleton(const Singleton&) = delete;//no move (ex Singleton a = b)
    Singleton(const Singleton&&) = delete; // no copy (ex Singleton a = b)
    void operator=(const Singleton&) = delete;// copy assignment operator (ex Singleton a = Singleton b)
    void operator=(const Singleton&&) = delete; // no move (ex Singleton a = move(Singleton b))
    private:
        Singleton() = default;
}