#include <iostream>
using namespace std;

struct MarketData {
    size_t TimeSinceEpoch;
    double Open, High, Low, Close;
};

using MarketDatas = std::vector<MarketData>;
using PcapData = std::vector<std::string>;
using LiveMarketData = std::vector<std::vector<std::byte>>;

struct IMarketDataSource {
    virtual ~IMarketDataSource() = default;
    virtual MarketDatas Parse(std::variant<PcapData, LiveMarketData> raw) const = 0;
};

// Implement the two classes below
struct PcapDataSource : public IMarketDataSource{

};
struct LiveMarketDataSource : public IMarketDataSource{
    
};

class Processor {
public:
    MarketData Ingest(const std::variant<PcapData, LiveMarketData>& source) {
        return { };
    }
};


int main(){


}