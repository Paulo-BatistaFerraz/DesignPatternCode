// ============================================================
//  TradeLogger — Singleton Problem
//  Design Patterns | GetCraked Practice
// ============================================================
//
//  CONTEXT
//  -------
//  You are building the logging subsystem for a trading system
//  at a quant firm. All components — the order router, risk
//  engine, and execution engine — must write to the SAME log.
//  If each component created its own logger, trade records
//  would be split across separate buffers and the audit trail
//  would be incomplete.
//
//  There must be exactly one TradeLogger in the process.
//
//  REQUIREMENTS
//  ------------
//  static TradeLogger& GetInstance()
//      Returns a reference to the single shared instance.
//      Must be thread-safe (C++11 guarantee via static local).
//
//  void Log(const std::string& trade)
//      Appends trade to the internal log.
//
//  std::vector<std::string> GetLog() const
//      Returns all logged entries in insertion order.
//
//  void Clear()
//      Removes all entries from the log.
//
//  The class must NOT be copyable or movable (compile errors).
//
//  FOLLOW-UP QUESTIONS (answer after implementation)
//  --------------------------------------------------
//  1. Why return TradeLogger& instead of TradeLogger*?
//  2. What C++11 mechanism makes the static local thread-safe?
//     What would you need to do in C++03?
//  3. Colleague suggests a static member variable for the log.
//     What is the difference vs an instance variable?
//  4. How would you refactor so components can be tested
//     without this global Singleton? (Hint: interfaces)
//
// ============================================================

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

// ── YOUR IMPLEMENTATION ──────────────────────────────────────

class TradeLogger {
public:
    static TradeLogger& GetInstance();

    void Log(const std::string& trade);
    std::vector<std::string> GetLog() const;
    void Clear();


    // TODO: delete the four special members that must not compile
    TradeLogger(const &TradeLogger) = delete; // copy constructor
    TradeLogger(const &&TradeLogger) = delete; // move constructor
    void operator =(TradeLogger&&) = delete; // move assignment operator
    TradeLogger(TradeLogger&&) = delete; // move constructor

private:
    TradeLogger() = default;
    // TODO: private constructor + data member(s)
};

// ── TEST HARNESS ─────────────────────────────────────────────
//  DO NOT modify below this line.
//  All assertions must pass.

static int passed = 0;
static int failed = 0;

#define TEST(name, expr)                                        \
    do {                                                        \
        if (expr) { std::cout << "[PASS] " #name "\n"; ++passed; } \
        else      { std::cout << "[FAIL] " #name "\n"; ++failed; } \
    } while(0)

int main() {
    std::cout << "=== TradeLogger Tests ===\n\n";

    // 1. Same address every time
    TradeLogger& a = TradeLogger::GetInstance();
    TradeLogger& b = TradeLogger::GetInstance();
    TEST(single_instance, &a == &b);

    // 2. State is shared across references
    a.Clear();
    a.Log("BUY  AAPL  100  @  182.50");
    TEST(shared_state, b.GetLog().size() == 1);

    // 3. Insertion order preserved
    a.Clear();
    a.Log("BUY  AAPL  100  @  182.50");
    a.Log("SELL MSFT  200  @  415.00");
    a.Log("BUY  TSLA   50  @  172.30");
    auto log = a.GetLog();
    TEST(log_order,
         log.size() == 3 &&
         log[0] == "BUY  AAPL  100  @  182.50" &&
         log[1] == "SELL MSFT  200  @  415.00" &&
         log[2] == "BUY  TSLA   50  @  172.30");

    // 4. Clear empties the log
    a.Clear();
    TEST(clear_works, a.GetLog().empty());

    // 5. Compile-time tests — uncomment ONE at a time to verify
    //    Each line below must NOT compile.
    //
    // TradeLogger copy = TradeLogger::GetInstance();       // no_copy
    // TradeLogger moved = std::move(TradeLogger::GetInstance()); // no_move
    // TradeLogger t2; t2 = TradeLogger::GetInstance();    // no_copy_assign
    // TradeLogger t3; t3 = std::move(TradeLogger::GetInstance()); // no_move_assign

    std::cout << "\n--- Results: " << passed << " passed, " << failed << " failed ---\n";
    return failed == 0 ? 0 : 1;
}
