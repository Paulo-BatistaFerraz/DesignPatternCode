#include <iostream>
using namespace std;

struct FixGatewayAdpter: Ordergateway {
    LegacyFixGateway* gateway; // base class is pointing to the gateway
    FixGatewayAdpter(LegacyFixGateway* gateway): gateway(gateway){} // constructor is pointing to the gateway
    void SubmitOrder(int instrument_id, int side, int quantity) override{
        string msg = "INSTR=" + to_string(instrument_id) + "SIDE=" + to_string(side) + "QTY=" + to_string(quantity);
        gateway->SendMessage(msg);
    }
};