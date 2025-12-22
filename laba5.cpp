#include <iostream>
#include <string>
using namespace std;

// Базовый класс Pair
class Pair {
protected:
    int first;   // первое число
    int second;  // второе число
    
public:
    // Конструкторы
    Pair() : first(0), second(0) {}
    Pair(int f, int s) : first(f), second(s) {}
    
    // Геттеры
    int getFirst() const { return first; }
    int getSecond() const { return second; }
    
    // Сеттеры
    void setFirst(int f) { first = f; }
    void setSecond(int s) { second = s; }
    
    // Сравнение пар
    bool isGreater(const Pair& other) const {
        return (first > other.first) || 
               (first == other.first && second > other.second);
    }
    
    // Метод toString
    string toString() const {
        return "(" + to_string(first) + ", " + to_string(second) + ")";
    }
    
    // Ввод/вывод
    friend ostream& operator<<(ostream& os, const Pair& p);
};

ostream& operator<<(ostream& os, const Pair& p) {
    os << "first=" << p.first << ", second=" << p.second;
    return os;
}

// Производный класс Fraction
class Fraction : public Pair {
private:
    int whole;      // целая часть
    int fraction;   // дробная часть
    
public:
    // Конструкторы
    Fraction() : Pair(), whole(0), fraction(0) {}
    Fraction(int f, int s, int w, int fr) : Pair(f, s), whole(w), fraction(fr) {}
    
    // Геттеры
    int getWhole() const { return whole; }
    int getFraction() const { return fraction; }
    
    // Сеттеры
    void setWhole(int w) { whole = w; }
    void setFraction(int fr) { fraction = fr; }
    
    // Полный набор сравнений
    bool operator>(const Fraction& other) const {
        return (whole > other.whole) || 
               (whole == other.whole && fraction > other.fraction);
    }
    
    bool operator<(const Fraction& other) const {
        return (whole < other.whole) || 
               (whole == other.whole && fraction < other.fraction);
    }
    
    bool operator==(const Fraction& other) const {
        return whole == other.whole && fraction == other.fraction;
    }
    
    bool operator!=(const Fraction& other) const { return !(*this == other); }
    bool operator>=(const Fraction& other) const { return !(*this < other); }
    bool operator<=(const Fraction& other) const { return !(*this > other); }
    
    // Метод toString
    string toString() const {
        return to_string(whole) + "." + to_string(fraction) + 
               " [база: " + Pair::toString() + "]";
    }
    
    // Ввод/вывод
    friend ostream& operator<<(ostream& os, const Fraction& f);
};

ostream& operator<<(ostream& os, const Fraction& f) {
    os << "whole=" << f.whole << ", fraction=" << f.fraction 
       << " [наследовано: " << static_cast<const Pair&>(f) << "]";
    return os;
}

int main() {
    cout << "=== НАСЛЕДОВАНИЕ ===\n" << endl;
    
    // 1. Работа с Pair
    cout << "1. Класс Pair:" << endl;
    Pair p1(5, 10);
    Pair p2(3, 8);
    Pair p3(5, 7);
    
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p1 > p2? " << (p1.isGreater(p2) ? "да" : "нет") << endl;
    cout << "p1 > p3? " << (p1.isGreater(p3) ? "да" : "нет") << endl;
    
    // 2. Работа с Fraction
    cout << "\n2. Класс Fraction:" << endl;
    Fraction f1(1, 2, 3, 75);  // 3.75
    Fraction f2(2, 3, 2, 50);  // 2.50
    Fraction f3(4, 5, 3, 75);  // 3.75
    
    cout << "f1: " << f1 << endl;
    cout << "f2: " << f2 << endl;
    cout << "f3: " << f3 << endl;
    
    cout << "\nСравнение дробей:" << endl;
    cout << "f1 > f2? " << (f1 > f2 ? "да" : "нет") << endl;
    cout << "f1 < f2? " << (f1 < f2 ? "да" : "нет") << endl;
    cout << "f1 == f3? " << (f1 == f3 ? "да" : "нет") << endl;
    cout << "f1 != f2? " << (f1 != f2 ? "да" : "нет") << endl;
    
    // 3. Принцип подстановки
    cout << "\n3. Принцип подстановки:" << endl;
    
    // Указатель базового класса на объект производного
    Pair* ptr = &f1;
    cout << "Pair* ptr = &f1: " << *ptr << endl;
    
    // Ссылка базового класса на объект производного
    Pair& ref = f2;
    cout << "Pair& ref = f2: " << ref << endl;
    
    // Присваивание (срезка)
    Pair p4 = f1;
    cout << "Pair p4 = f1: " << p4 << endl;
    
    // 4. Массивы
    cout << "\n4. Массивы объектов:" << endl;
    
    // Массив Pair
    Pair arr1[2] = {Pair(1, 2), Pair(3, 4)};
    cout << "Массив Pair: ";
    for (int i = 0; i < 2; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    // Массив Fraction
    Fraction arr2[2] = {Fraction(1,1,2,50), Fraction(2,2,3,75)};
    cout << "Массив Fraction: ";
    for (int i = 0; i < 2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    // 5. Динамические объекты
    cout << "\n5. Динамические объекты:" << endl;
    Pair* dyn1 = new Pair(10, 20);
    Fraction* dyn2 = new Fraction(5,5,7,25);
    
    cout << "dyn1: " << *dyn1 << endl;
    cout << "dyn2: " << *dyn2 << endl;
    
    // Полиморфный указатель
    Pair* poly = new Fraction(1,1,4,50);
    cout << "poly (Pair* на Fraction): " << *poly << endl;
    
    delete dyn1;
    delete dyn2;
    delete poly;
    
    cout << "\n=== КОНЕЦ ===" << endl;
    
    return 0;
}
