#include <iostream>
#include <algorithm>
using namespace std;

// Базовый случай рекурсии
template <typename T>
T sum(T value)
{
    return value;
}

// Рекурсивное извлечение параметров
template <typename First, typename... Rest>
auto sum(First first, Rest... rest)
{
    return first + sum(rest...);
}

template <typename... Args>
auto Sum17(Args... args)
{
    return (args + ...);
}

// Базовый случай рекурсии
template <typename T>
T minOf(T value)
{
    return value;
}

// Рекурсивное сравнение
template <typename First, typename... Rest>
auto minOf(First first, Rest... rest)
{
    auto tailMin = minOf(rest...);
    return (first < tailMin) ? first : tailMin;
}

template <typename... Args>
auto Min17(Args... args)
{
    return min({args...});
}

int main()
{
    cout << "C++11 sum:     " << sum(1, 2, 3, 4, 5) << endl;
    cout << "C++17 Sum17:   " << Sum17(1, 2, 3, 4, 5) << endl;

    cout << "C++11 minOf:   " << minOf(10, 4, 7, 2, 9) << endl;
    cout << "C++17 Min17:   " << Min17(10, 4, 7, 2, 9) << endl;

    return 0;
}
