#include <iostream>
#include <algorithm>
using namespace std;

// Объявление шаблонной функции
template <typename T>
double median(T* mas, int size);

int main() {
    int n;
    cout << "Vvedite razmer massiva: ";
    cin >> n;
    int mas[n];
    for (int i = 0; i < n; i++) {
        cout << "Vvedite znachenie massiva: ";
        cin >> mas[i];
    }

    // Вызов шаблонной функции
    double result = median(mas, n);
    cout << "Mediana massiva: " << result << endl;
    return 0;
}

// Определение шаблонной функции
template <typename T>
double median(T* mas, int size) {
    sort(mas, mas + size);

    if (size % 2 != 0) {
        return mas[size / 2];
    } else {
        return (mas[size / 2 - 1] + mas[size / 2]) / 2.0;
    }
}
