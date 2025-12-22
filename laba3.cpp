#include <iostream>
#include <cmath>
using namespace std;

// Класс vector3D с конструкторами
class Vector3D {
private:
    double x, y, z;
    
public:
    // 1. Конструктор без аргументов (по умолчанию)
    Vector3D() : x(0), y(0), z(0) {
        cout << "Вызван конструктор без аргументов" << endl;
    }
    
    // 2. Конструктор инициализации
    Vector3D(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {
        cout << "Вызван конструктор инициализации (" << x << ", " << y << ", " << z << ")" << endl;
    }
    
    // 3. Конструктор с одним параметром (исправил)
    Vector3D(double val) : x(val), y(val), z(val) {
        cout << "Вызван конструктор с одним параметром (" << x << ", " << y << ", " << z << ")" << endl;
    }
    
    // 4. Конструктор копирования
    Vector3D(const Vector3D& other) : x(other.x), y(other.y), z(other.z) {
        cout << "Вызван конструктор копирования" << endl;
    }
    
    // Деструктор
    ~Vector3D() {
        cout << "Вызван деструктор для (" << x << ", " << y << ", " << z << ")" << endl;
    }
    
    // Методы класса
    void read() {
        cout << "Введите x y z: ";
        cin >> x >> y >> z;
    }
    
    void display() const {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }
    
    // toString возвращает строку (исправил)
    string toString() const {
        char buffer[100];
        sprintf(buffer, "(%.2f, %.2f, %.2f)", x, y, z);
        return string(buffer);
    }
    
    // Сложение векторов
    Vector3D add(const Vector3D& b) const {
        return Vector3D(x + b.x, y + b.y, z + b.z);
    }
    
    // Вычитание векторов
    Vector3D subtract(const Vector3D& b) const {
        return Vector3D(x - b.x, y - b.y, z - b.z);
    }
    
    // Скалярное произведение
    double dotProduct(const Vector3D& b) const {
        return x * b.x + y * b.y + z * b.z;
    }
    
    // Умножение на скаляр
    Vector3D multiplyByScalar(double k) const {
        return Vector3D(x * k, y * k, z * k);
    }
    
    // Сравнение векторов (равны ли)
    bool isEqual(const Vector3D& b) const {
        const double EPSILON = 1e-10;  // Для сравнения чисел с плавающей точкой
        return (fabs(x - b.x) < EPSILON && 
                fabs(y - b.y) < EPSILON && 
                fabs(z - b.z) < EPSILON);
    }
    
    // Вычисление длины вектора
    double length() const {
        return sqrt(x * x + y * y + z * z);
    }
    
    // Сравнение длин векторов
    bool isLonger(const Vector3D& b) const {
        return length() > b.length();
    }
    
    // Геттеры
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
    
    // Оператор присваивания
    Vector3D& operator=(const Vector3D& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
            cout << "Вызван оператор присваивания" << endl;
        }
        return *this;
    }
};

// Глобальная функция для демонстрации передачи параметров
void showVectorByValue(Vector3D v) {
    cout << "Функция showVectorByValue: ";
    v.display();
    cout << endl;
}

void showVectorByReference(const Vector3D& v) {
    cout << "Функция showVectorByReference: ";
    v.display();
    cout << endl;
}

int main() {
    cout << "=== ЛАБОРАТОРНАЯ РАБОТА №3. КОНСТРУКТОРЫ VECTOR3D ===\n" << endl;
    
    cout << "1. Различные способы создания объектов:" << endl;
    cout << "=========================================" << endl;
    
    // 1. Конструктор без аргументов
    cout << "\na) Конструктор без аргументов:" << endl;
    Vector3D v1;
    cout << "v1 = "; v1.display(); cout << endl;
    
    // 2. Конструктор инициализации
    cout << "\nb) Конструктор инициализации:" << endl;
    Vector3D v2(1.0, 2.0, 3.0);
    cout << "v2 = "; v2.display(); cout << endl;
    
    // 3. Конструктор с одним параметром
    cout << "\nc) Конструктор с одним параметром:" << endl;
    Vector3D v3(5.0);
    cout << "v3 = "; v3.display(); cout << endl;
    
    // 4. Конструктор копирования
    cout << "\nd) Конструктор копирования:" << endl;
    Vector3D v4(v2);
    cout << "v4 = "; v4.display(); cout << endl;
    
    // 5. Копирование через присваивание
    cout << "\ne) Копирование через присваивание:" << endl;
    Vector3D v5 = v2;
    cout << "v5 = "; v5.display(); cout << endl;
    
    // 6. Явный вызов конструктора
    cout << "\nf) Явный вызов конструктора:" << endl;
    Vector3D v6 = Vector3D(10.0, 20.0, 30.0);
    cout << "v6 = "; v6.display(); cout << endl;
    
    // 7. Присваивание
    cout << "\ng) Присваивание:" << endl;
    Vector3D v7;
    v7 = v2;  // Используется оператор присваивания
    cout << "v7 = "; v7.display(); cout << endl;
    
    cout << "\n\n2. Создание динамических объектов:" << endl;
    cout << "===================================" << endl;
    
    // 8. Динамический объект (конструктор без аргументов)
    cout << "\na) Динамический объект (конструктор без аргументов):" << endl;
    Vector3D* pv1 = new Vector3D;
    cout << "*pv1 = "; pv1->display(); cout << endl;
    
    // 9. Динамический объект (конструктор инициализации)
    cout << "\nb) Динамический объект (конструктор инициализации):" << endl;
    Vector3D* pv2 = new Vector3D(7.0, 8.0, 9.0);
    cout << "*pv2 = "; pv2->display(); cout << endl;
    
    // 10. Динамический объект (конструктор копирования)
    cout << "\nc) Динамический объект (конструктор копирования):" << endl;
    Vector3D* pv3 = new Vector3D(*pv2);
    cout << "*pv3 = "; pv3->display(); cout << endl;
    
    cout << "\n\n3. Создание массива объектов:" << endl;
    cout << "===============================" << endl;
    
    // 11. Массив с конструктором по умолчанию
    cout << "\na) Массив из 3 элементов (конструктор по умолчанию):" << endl;
    Vector3D arr1[3];
    for (int i = 0; i < 3; i++) {
        cout << "arr1[" << i << "] = "; 
        arr1[i].display();
        cout << endl;
    }
    
    // 12. Массив с инициализацией
    cout << "\nb) Массив с инициализацией:" << endl;
    Vector3D arr2[3] = { Vector3D(1, 0, 0), Vector3D(0, 1, 0), Vector3D(0, 0, 1) };
    for (int i = 0; i < 3; i++) {
        cout << "arr2[" << i << "] = "; 
        arr2[i].display();
        cout << " длина = " << arr2[i].length() << endl;
    }
    
    // 13. Сокращенная форма инициализации массива (исправил)
    cout << "\nc) Сокращенная форма инициализации массива:" << endl;
    Vector3D arr3[2] = { Vector3D(1.0, 2.0, 3.0), Vector3D(4.0, 5.0, 6.0) };
    for (int i = 0; i < 2; i++) {
        cout << "arr3[" << i << "] = "; 
        arr3[i].display();
        cout << endl;
    }
    
    cout << "\n\n4. Константные объекты:" << endl;
    cout << "========================" << endl;
    
    // 14. Константный объект
    const Vector3D constVec(100.0, 200.0, 300.0);
    cout << "constVec = "; constVec.display(); 
    cout << " (toString: " << constVec.toString() << ")" << endl;
    cout << "Длина constVec = " << constVec.length() << endl;
    
    // 15. Константный объект с копированием
    const Vector3D constCopy = constVec;
    cout << "constCopy = "; constCopy.display(); cout << endl;
    
    cout << "\n\n5. Передача объектов в функции:" << endl;
    cout << "================================" << endl;
    
    // 16. Передача по значению (вызывается конструктор копирования)
    cout << "\na) Передача по значению:" << endl;
    showVectorByValue(v2);
    
    // 17. Передача по ссылке (конструкторы не вызываются)
    cout << "\nb) Передача по ссылке:" << endl;
    showVectorByReference(v2);
    
    // 18. Передача выражения (вызывается конструктор инициализации)
    cout << "\nc) Передача выражения:" << endl;
    showVectorByValue(Vector3D(99.0, 88.0, 77.0));
    
    cout << "\n\n6. Операции над векторами:" << endl;
    cout << "===========================" << endl;
    
    Vector3D a(1, 2, 3);
    Vector3D b(4, 5, 6);
    
    cout << "a = "; a.display(); cout << endl;
    cout << "b = "; b.display(); cout << endl;
    
    cout << "a + b = "; a.add(b).display(); cout << endl;
    cout << "a - b = "; a.subtract(b).display(); cout << endl;
    cout << "a * b (скаляр) = " << a.dotProduct(b) << endl;
    cout << "a * 2.5 = "; a.multiplyByScalar(2.5).display(); cout << endl;
    cout << "Длина a = " << a.length() << endl;
    cout << "Длина b = " << b.length() << endl;
    cout << "a == b? " << (a.isEqual(b) ? "да" : "нет") << endl;
    cout << "a длиннее b? " << (a.isLonger(b) ? "да" : "нет") << endl;
    
    cout << "\n\n7. Освобождение динамической памяти:" << endl;
    cout << "===================================" << endl;
    
    delete pv1;
    delete pv2;
    delete pv3;
    
    cout << "\n=== ПРОГРАММА ЗАВЕРШЕНА ===" << endl;
    cout << "\nОбратите внимание на вызовы деструкторов при выходе из программы" << endl;
    
    // Дополнительная проверка работы toString
    cout << "\nДемонстрация метода toString(): " << a.toString() << endl;
    
    return 0;
}
