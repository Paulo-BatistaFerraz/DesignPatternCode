#include <iostream>
#include <range>
#include <sstream>
#include <vector>

int main() {
    std::istringstream input("1 2 3 4 5 6 7 8 9 10");
    auto streamA = std::ranges::istream_view<int>(input);

    auto streamAIterator = streamA.begin();
    std::cout << "First element: " << *streamAIterator << std::endl;

    while (streamAIterator != streamA.end()) {
        std::cout << "Element: " << *streamAIterator << std::endl;
        streamAIterator++;
    }

    return 0;
}