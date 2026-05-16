#include <iostream>
#include <vector>
using namespace std;

enum class Stream { A, B};


struct Packet {
    Stream Source;
    size_t ReceiveTime;
    int SequenceNumber;
};

using Packets = std::vector<Packet>;

ostream& operator<<(ostream& os, const Packet& p) {
    os << "{Source=" << (p.Source == Stream::A ? "A" : "B")
       << ", RecvTime=" << p.ReceiveTime
       << ", Seq=" << p.SequenceNumber << "}";
    return os;
}


Packets ArbitrageStreams(const Packets& streamA, const Packets& streamB) {
    Packets packets;
    auto streamAIterator = streamA.begin();
    auto streamBIterator = streamB.begin();

    while (streamAIterator != streamA.end() && streamBIterator != streamB.end())
    {
        if (streamAIterator)
    }
}

Packets ArbitrageStreams(const Packets& streamA, const Packets& streamB) {
    Packets packets; // initialize the packets vector

    auto streamAIterator = streamA.begin(); // stream operator get the beginning of the stream ie first element
    auto streamBIterator = streamB.begin();

    cout << "streamAIterator: " << *streamAIterator << endl;
    cout << "streamBIterator: " << *streamBIterator << endl;

    return packets;
}

int main() {
    Packets streamA = {
        {Stream::A, 10, 1},
        {Stream::A, 20, 2},
        {Stream::A, 35, 3},
        {Stream::A, 50, 5},
    };

    Packets streamB = {
        {Stream::B, 12, 1},
        {Stream::B, 18, 2},
    };

    ArbitrageStreams(streamA, streamB);
    return 0;
}
