#include <iostream>

Struct Dog{
    public:
    virtualvoid bark(string name) {
        cout << "Woof, my name is " << name << endl;
    }
}
Struct DogBreed: Dog{
    public:
    void bark(string name, string breed) override {
        cout << "Woof, my name is " << name << " and I am a " << breed << endl;
    }
};


int main(){
    unique_ptr<Dog> dog = make_unique<Dog>();
    dog->bark("Rex", "Labrador");
    return 0;
}