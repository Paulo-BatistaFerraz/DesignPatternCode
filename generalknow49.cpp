#include <iostream>
#include <vector>

enum class Stream { A, B };

struct Packet {
    Stream Source;
    size_t ReceiveTime;
    int SequenceNumber;
};

using Packets = std::vector<Packet>;

Packets ArbitrageStreams(const Packets& streamA, const Packets& streamB) { 
    Packets packets; // initialize the packets vector

    auto streamAIterator = streamA.begin(); // stream operator get the beginning of the stream ie first element
    auto streamBIterator = streamB.begin();

    while (streamAIterator != streamA.end() && streamBIterator != streamB.end()) {
        const auto aPacket = *streamAIterator;
        const auto bPacket = *streamBIterator;
        if (aPacket.SequenceNumber == bPacket.SequenceNumber) {
            if (aPacket.ReceiveTime <= bPacket.ReceiveTime) {
                packets.push_back(aPacket);
            } else {
                packets.push_back(bPacket);
            }

            streamAIterator++;
            streamBIterator++;
        } else if (aPacket.SequenceNumber < bPacket.SequenceNumber) {
            packets.push_back(aPacket);
            streamAIterator++;
        } else {
            packets.push_back(bPacket);
            streamBIterator++;
        }
    }

    while (streamAIterator != streamA.end()) {
        packets.push_back(*streamAIterator);
        streamAIterator++;
    }

    while (streamBIterator != streamB.end()) {
        packets.push_back(*streamBIterator);
        streamBIterator++;
    }

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
        {Stream::B, 40, 4},
        {Stream::B, 55, 5},
    };

    auto merged = ArbitrageStreams(streamA, streamB);

    for (const auto& p : merged) {
        std::cout << "Seq=" << p.SequenceNumber
                  << " Source=" << (p.Source == Stream::A ? "A" : "B")
                  << " RecvTime=" << p.ReceiveTime << "\n";
    }
    return 0;
}
