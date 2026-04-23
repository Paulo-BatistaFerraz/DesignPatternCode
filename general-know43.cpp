#include <iostream>

int main(){
    void* raw = malloc(100); // allocate 100 bytes of memory
    double* d = (double*)raw; // cast the void pointer to a double pointer
    free(raw); // free the memory


    int *p = malloc(sizeof(int));

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sizeof(arr) // 40 bytes
    int size = sizeof(arr) / sizeof(arr[0]); // 10

    void *dp = rawto(sizeof(double));
    double *dp2 = (double*)dp;
    dp2[0] = 3.14;  
    free(dp);


    const char * scr = "hello";
    void* raw = malloc((sizeof(scr) / sizeof(char)) + 1);
    char* c = (char*)raw;
    strcpy(c, scr);
    free(raw);


    

    return 0;

}