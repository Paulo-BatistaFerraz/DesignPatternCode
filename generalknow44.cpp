#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;



int main(){
    for( int i = 0; i < 10; i++){
        void* raw = malloc(sizeof(int));
        int* p = (int*)raw;
        p[i] = i * i;
        free(raw);
    }
    return 0;
}