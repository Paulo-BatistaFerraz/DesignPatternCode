#include <iostream>
#include <vector>
#include <string>
#include <variant>
#include <memory>
#include <cstddef>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <stdexcept>
#include <optional>

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

struct PcapDataSource : public IMarketDataSource {
    MarketDatas Parse(std::variant<PcapData, LiveMarketData> raw) const override {
        if (!std::holds_alternative<PcapData>(raw))
            throw std::logic_error("PcapDataSource expects PcapData");

        const auto& lines = std::get<PcapData>(raw);
        MarketDatas result;

        for (const auto& line : lines) {
            size_t t;
            double o, h, l, c;
            char pipe;

            std::istringstream ss(line);
            ss >> t >> pipe >> o >> pipe >> h >> pipe >> l >> pipe >> c;
            result.push_back({t, o, h, l, c});
        }

        return result;
    }
};

struct LiveMarketDataSource : public IMarketDataSource {
    MarketDatas Parse(std::variant<PcapData, LiveMarketData> raw) const override {
        if (!std::holds_alternative<LiveMarketData>(raw))
            throw std::logic_error("LiveMarketDataSource expects LiveMarketData");

        const auto& lines = std::get<LiveMarketData>(raw);
        MarketDatas result;

        for (const auto& line : lines) {
            MarketData md;
            std::memcpy(&md, line.data(), sizeof(MarketData));
            result.push_back(md);
        }

        return result;
    }
};

class Processor {
public:
    MarketData Ingest(const std::variant<PcapData, LiveMarketData>& source) {
        std::unique_ptr<IMarketDataSource> src;

        if (std::holds_alternative<PcapData>(source))
            src = std::make_unique<PcapDataSource>();
        else
            src = std::make_unique<LiveMarketDataSource>();

        MarketDatas data = src->Parse(source);

        auto best = std::max_element(data.begin(), data.end(),
            [](const MarketData& a, const MarketData& b) {
                return a.High < b.High;
            });

        return *best;
    }
};
