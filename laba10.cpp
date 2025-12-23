#include <iostream>

constexpr auto factorial = [](int n) {
    int prod = 1;
    for (int i = 1; i <= n; ++i) {
        prod *= i;
    }
    return prod;
};

constexpr auto gcd = [](int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
};

int main() {

    // Вычисление во время компиляции
    constexpr int fact_result = factorial(5);
    constexpr int gcd_result = gcd(48, 18);

    std::cout << "Факториал 5 = " << fact_result << std::endl;
    std::cout << "НОД(48, 18) = " << gcd_result << std::endl;

    return 0;
}
