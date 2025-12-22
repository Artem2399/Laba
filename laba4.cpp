#include <iostream>
#include <cmath>
using namespace std;

class Vector3D {
private:
    double x, y, z;
    
public:
    // Конструкторы
    Vector3D() : x(0), y(0), z(0) {}
    Vector3D(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {}
    
    // Геттеры
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
    
    // Длина вектора
    double length() const {
        return sqrt(x*x + y*y + z*z);
    }
    
    // Унарные операции (методы класса)
    Vector3D operator-() const {
        return Vector3D(-x, -y, -z);
    }
    
    // Операции с присваиванием (методы класса)
    Vector3D& operator+=(const Vector3D& b) {
        x += b.x;
        y += b.y;
        z += b.z;
        return *this;
    }
    
    Vector3D& operator-=(const Vector3D& b) {
        x -= b.x;
        y -= b.y;
        z -= b.z;
        return *this;
    }
    
    Vector3D& operator*=(double k) {
        x *= k;
        y *= k;
        z *= k;
        return *this;
    }
    
    // Дружественные функции для бинарных операций
    friend Vector3D operator+(Vector3D a, const Vector3D& b);
    friend Vector3D operator-(Vector3D a, const Vector3D& b);
    friend double operator*(const Vector3D& a, const Vector3D& b);
    friend Vector3D operator*(Vector3D v, double k);
    friend Vector3D operator*(double k, Vector3D v);
    friend bool operator==(const Vector3D& a, const Vector3D& b);
    friend bool operator!=(const Vector3D& a, const Vector3D& b);
    friend bool operator<(const Vector3D& a, const Vector3D& b);
    friend bool operator>(const Vector3D& a, const Vector3D& b);
    friend ostream& operator<<(ostream& os, const Vector3D& v);
    friend istream& operator>>(istream& is, Vector3D& v);
};

// Реализация дружественных функций
Vector3D operator+(Vector3D a, const Vector3D& b) {
    return a += b;
}

Vector3D operator-(Vector3D a, const Vector3D& b) {
    return a -= b;
}

double operator*(const Vector3D& a, const Vector3D& b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vector3D operator*(Vector3D v, double k) {
    return v *= k;
}

Vector3D operator*(double k, Vector3D v) {
    return v *= k;
}

bool operator==(const Vector3D& a, const Vector3D& b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

bool operator!=(const Vector3D& a, const Vector3D& b) {
    return !(a == b);
}

bool operator<(const Vector3D& a, const Vector3D& b) {
    return a.length() < b.length();
}

bool operator>(const Vector3D& a, const Vector3D& b) {
    return a.length() > b.length();
}

ostream& operator<<(ostream& os, const Vector3D& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

istream& operator>>(istream& is, Vector3D& v) {
    cout << "Введите x y z: ";
    is >> v.x >> v.y >> v.z;
    return is;
}

int main() {
    cout << "=== ПЕРЕГРУЗКА ОПЕРАЦИЙ VECTOR3D ===\n" << endl;
    
    // Создание объектов
    Vector3D a(1, 2, 3);
    Vector3D b(4, 5, 6);
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "Длина a = " << a.length() << endl;
    cout << "Длина b = " << b.length() << endl;
    
    // Арифметические операции
    cout << "\nАрифметические операции:" << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "-a = " << -a << endl;
    cout << "a * b (скаляр) = " << a * b << endl;
    cout << "a * 2 = " << a * 2 << endl;
    cout << "3 * b = " << 3 * b << endl;
    
    // Операции с присваиванием
    cout << "\nОперации с присваиванием:" << endl;
    Vector3D c = a;
    c += b;
    cout << "c = a; c += b;  c = " << c << endl;
    
    Vector3D d = a;
    d *= 2;
    cout << "d = a; d *= 2;  d = " << d << endl;
    
    // Сравнение
    cout << "\nСравнение:" << endl;
    cout << "a == b? " << (a == b ? "да" : "нет") << endl;
    cout << "a != b? " << (a != b ? "да" : "нет") << endl;
    cout << "a < b? " << (a < b ? "да" : "нет") << " (по длине)" << endl;
    cout << "a > b? " << (a > b ? "да" : "нет") << " (по длине)" << endl;
    
    // Ввод/вывод
    cout << "\nВвод/вывод:" << endl;
    Vector3D v;
    cin >> v;
    cout << "Вы ввели: " << v << endl;
    
    // Массив объектов
    cout << "\nМассив объектов:" << endl;
    Vector3D arr[3] = {Vector3D(1,0,0), Vector3D(0,1,0), Vector3D(0,0,1)};
    
    for (int i = 0; i < 3; i++) {
        cout << "arr[" << i << "] = " << arr[i] 
             << " длина = " << arr[i].length() << endl;
    }
    
    cout << "\n=== КОНЕЦ ===" << endl;
    
    return 0;
}
