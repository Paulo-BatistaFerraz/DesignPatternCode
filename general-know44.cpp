#include <fcntl.h>
#include <unistd.h>
#include <cstring>

int main() {
    // This looks like a normal function call. It isn't.
    int fd = open("data.txt", O_RDONLY); // open the file in read only mode
    
    char buf[128]; // buffer to read the file into (128 bytes is a common buffer size)
    read(fd, buf, sizeof(buf)); // read the file into the buffer
    
    close(fd); // close the file
    return 0;
}