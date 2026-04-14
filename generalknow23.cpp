tempalte <typename Type>
struct X{
    void bar() { std::cout << Type::identify() << std::endl;}
    static std::string_view identify() { return "X"; }
};

template <typename Type>
struct Y: Type{
    void bar() { std::cout << Type::identify() << std::endl;}
    static std::string_view identify() { return "Y"; }
};
class Z {
    protected:
    void bar() { std::cout << identify() << std::endl;}
    static std::string_view identify() { return "Z"; }
}
int main(){
    X<Y<Z>>{}.bar();
}