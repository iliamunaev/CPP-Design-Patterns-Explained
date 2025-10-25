# Mastering the Adapter Pattern in Modern C++: Bridging Legacy and New Code

## The Problem

 What if you can't modify the legacy code (it might be in use elsewhere), and you need it to work seamlessly with your new architecture?

This is where the **Adapter Pattern** becomes your best friend.

## What is the Adapter Pattern?

The Adapter Pattern is a structural design pattern that allows objects with incompatible interfaces to collaborate. Think of it like a power adapter when traveling abroad — it doesn't change the electricity itself, it just makes the plug compatible with different sockets.

In software terms, an adapter wraps an existing class with a new interface, making it compatible with the rest of your system without modifying the original code.

## Example: Frequency Range Management

### The Common Interface

We define a clean interface that our modern code expects:

```cpp
class IFrequencyRange {
  public:
    virtual ~IFrequencyRange() = default;

    virtual int adjustRange(int diff) = 0;
    virtual void getLastStatus() = 0;
};
```

This interface: adjust a frequency range and get status information.

### Modern Implementations

New classes implement this interface cleanly:

```cpp
class FrequencyRange2 : public IFrequencyRange {
  public:
    int adjustRange(int GHzToAdjust) override {
      int maxBand = 71;
      return maxBand - GHzToAdjust;
    }

    void getLastStatus() override {
      std::cout << "FR2 is loaded" << std::endl;
    }
};
```

### The Legacy Problem

But then we have our legacy `Range` class with a completely different signature:

```cpp
class Range {
  public:
    int changeRange(int GHzToAdjust, std::string& logMsg) {
      int maxBand = 7125;
      std::string Msg = logMsg;
      return maxBand - GHzToAdjust;
    }

    void getStatus() {
      std::cout << "Ranges: loaded" << std::endl;
    }
};
```

The problems:
- Method names don't match (`changeRange` vs `adjustRange`)
- `changeRange` requires an extra `std::string&` parameter
- Status method is named `getStatus()` instead of `getLastStatus()`

We can't change this class, and we can't use it directly with our `IFrequencyRange` interface.

## The Solution: RangeAdapter

```cpp
class RangeAdapter : public IFrequencyRange, private Range {
  public:
    int adjustRange(int GHzToAdjust) override {
      std::string logMsg = "Some msg";
      return changeRange(GHzToAdjust, logMsg);
    }

    void getLastStatus() override {
      getStatus();
    }
};
```

This adapter class does two things:

1. **Publicly inherits** from `IFrequencyRange` — making it compatible with modern code
2. **Privately inherits** from `Range` — reusing the legacy implementation without exposing it

The adapter translates method calls:
- `adjustRange()` creates the required log message and calls `changeRange()`
- `getLastStatus()` simply delegates to `getStatus()`

## Polymorphic Usage: The Payoff

We can treat all frequency ranges uniformly:

```cpp
int main() {
  const std::unique_ptr<IFrequencyRange> frequencyRanges[] {
    std::make_unique<FrequencyRange2>(),
    std::make_unique<FrequencyRange3>(),
    std::make_unique<RangeAdapter>()  // Legacy code adapted!
  };

  for (const auto &range : frequencyRanges) {
    std::cout << std::format("Adjusted to -> {}\n",
                             range->adjustRange(15));
    range->getLastStatus();
  }
}
```

## Key Benefits

1. **No modification of existing code** — The legacy `Range` class remains untouched
2. **Single Responsibility Principle** — Adapter handles only the interface conversion
3. **Open/Closed Principle** — We extended functionality without modifying existing classes
4. **Polymorphic uniformity** — All frequency ranges can be used interchangeably

## When to Use the Adapter Pattern

- You need to use a class with an incompatible interface
- You're integrating third-party libraries that don't match your interfaces
- You're gradually modernizing legacy code
- You want to create reusable classes that cooperate with unforeseen classes

## Conclusion

The Adapter Pattern is a powerful tool in your design patterns arsenal. It allows you to integrate legacy code into modern systems gracefully, maintain clean architectures, and write more flexible, maintainable software.

By wrapping incompatible interfaces with adapters, you can achieve seamless integration without compromising your codebase's integrity or rewriting working code.

---

## Source code

[Source code on GitHub](https://github.com/iliamunaev/CPP-Design-Patterns-Explained/tree/main/01_adapter).

**Author:** Ilia Munaev
**LinkedIn:** [linkedin.com/in/iliamunaev](https://www.linkedin.com/in/iliamunaev/)
**Email:** ilyamunaev@gmail.com
