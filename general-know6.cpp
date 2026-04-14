#include <iostream>
#include <memory>


struct ResourceHolder {
    void ReleaseResources() {

    }
}
struct ResourceHolderDeleter {
    void operator()(ResourceHolder* resource) {
        holder->ReleaseResources();
        delete resource;
    }
};

int main(){
    std::cout << sizeof(std::shared_ptr<ResourceHolder>) << std::endl;
}