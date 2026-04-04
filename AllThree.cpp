class Box{
    public:
    int* data;

    Box(int value): data(new int(value)){
        cout << "Box created with value " << endl; // constructoring the box with a int value
    }
    Box(const Box&o): data(new int(*o.data)){ // copying the box with a int value
        cout << "Box copied with value" << endl;
    }
    Box(Box&& o) noexcept: data(o.data){ // moving the box with a int value, noexcept means that the function will not throw an exception
        o.data = nullptr; // after moving the box, set the data to nullptr
        std::cout << "move " << *data << endl;
    };
    Box& operator=(const Box& ) noexcept{ // assigning the box with a int value, noexcept means that the function will not throw an exception
        if (this == &o) return * this; // if the box is the same as the otherbox, return the box
        delete data; // delete the data as the key here is that we are assigning the box with a int value
        o.data = nullptr; // after assigning the box, set the data to nullptr
        std::cout << "move-assign " << *data << endl;
        return *this; // return the box
    }
    ~Box(){ // destroying the box
        std::cout << "Box destroyed with value " << (data ? *data : -1) << endl; // if data is nullptr, print -1
        delete data;
    }
}

int main(){
    Box b1(10); // constructoring the box with a int value
    Box b2(b1); // copying the box with a int value
    Box b3(Box(20)); // constructing the box with a int value
    b1 = Box(30); // assigning the box with a int value
    return 0; // returning 0
}