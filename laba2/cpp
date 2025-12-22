#include <iostream>
#include <cmath>
using namespace std;

// =================== СТРУКТУРА ===================
struct Vector3D {
    double x, y, z;
    
    void init(double xx, double yy, double zz) {
        x = xx; y = yy; z = zz;
    }
    
    void read() {
        cout << "Введите x y z: ";
        cin >> x >> y >> z;
    }
    
    void display() {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }
    
    void toString() {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }
};

// Внешние функции для структуры
Vector3D add(Vector3D a, Vector3D b) {
    Vector3D r;
    r.init(a.x + b.x, a.y + b.y, a.z + b.z);
    return r;
}

Vector3D sub(Vector3D a, Vector3D b) {
    Vector3D r;
    r.init(a.x - b.x, a.y - b.y, a.z - b.z);
    return r;
}

double dot(Vector3D a, Vector3D b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3D mul(Vector3D a, double k) {
    Vector3D r;
    r.init(a.x * k, a.y * k, a.z * k);
    return r;
}

bool equal(Vector3D a, Vector3D b) {
    return (a.x == b.x && a.y == b.y && a.z == b.z);
}

double len(Vector3D a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

bool longer(Vector3D a, Vector3D b) {
    return len(a) > len(b);
}

// =================== КЛАСС ===================
class Vector3DClass {
private:
    double x, y, z;
    
public:
    void init(double xx, double yy, double zz) {
        x = xx; y = yy; z = zz;
    }
    
    void read() {
        cout << "Введите x y z: ";
        cin >> x >> y >> z;
    }
    
    void display() {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }
    
    void toString() {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }
    
    Vector3DClass add(Vector3DClass b) {
        Vector3DClass r;
        r.init(x + b.x, y + b.y, z + b.z);
        return r;
    }
    
    Vector3DClass sub(Vector3DClass b) {
        Vector3DClass r;
        r.init(x - b.x, y - b.y, z - b.z);
        return r;
    }
    
    double dot(Vector3DClass b) {
        return x * b.x + y * b.y + z * b.z;
    }
    
    Vector3DClass mul(double k) {
        Vector3DClass r;
        r.init(x * k, y * k, z * k);
        return r;
    }
    
    bool equal(Vector3DClass b) {
        return (x == b.x && y == b.y && z == b.z);
    }
    
    double len() {
        return sqrt(x * x + y * y + z * z);
    }
    
    bool longer(Vector3DClass b) {
        return len() > b.len();
    }
};

// =================== ГЛАВНАЯ ===================
int main() {
    cout << "=== ЛАБОРАТОРНАЯ РАБОТА №2. VECTOR3D ===" << endl;
    
    // 1. Работа со структурой
    cout << "\n--- Структура ---" << endl;
    
    Vector3D a, b;
    a.init(1, 2, 3);
    b.init(4, 5, 6);
    
    cout << "Вектор A: "; a.display(); cout << endl;
    cout << "Вектор B: "; b.display(); cout << endl;
    
    cout << "A + B = "; add(a, b).display(); cout << endl;
    cout << "A - B = "; sub(a, b).display(); cout << endl;
    cout << "A * B (скаляр) = " << dot(a, b) << endl;
    cout << "A * 2 = "; mul(a, 2).display(); cout << endl;
    cout << "Длина A = " << len(a) << endl;
    cout << "Длина B = " << len(b) << endl;
    cout << "A == B? " << (equal(a, b) ? "да" : "нет") << endl;
    cout << "A длиннее B? " << (longer(a, b) ? "да" : "нет") << endl;
    
    // 2. Работа с классом
    cout << "\n--- Класс ---" << endl;
    
    Vector3DClass c, d;
    c.init(1, 2, 3);
    d.init(4, 5, 6);
    
    cout << "Вектор C: "; c.display(); cout << endl;
    cout << "Вектор D: "; d.display(); cout << endl;
    
    cout << "C + D = "; c.add(d).display(); cout << endl;
    cout << "C - D = "; c.sub(d).display(); cout << endl;
    cout << "C * D (скаляр) = " << c.dot(d) << endl;
    cout << "C * 2 = "; c.mul(2).display(); cout << endl;
    cout << "Длина C = " << c.len() << endl;
    cout << "Длина D = " << d.len() << endl;
    cout << "C == D? " << (c.equal(d) ? "да" : "нет") << endl;
    cout << "C длиннее D? " << (c.longer(d) ? "да" : "нет") << endl;
    
    // 3. Массив объектов
    cout << "\n--- Массив векторов ---" << endl;
    Vector3DClass arr[3];
    
    arr[0].init(1, 0, 0);
    arr[1].init(0, 1, 0);
    arr[2].init(0, 0, 1);
    
    for (int i = 0; i < 3; i++) {
        cout << "arr[" << i << "] = "; 
        arr[i].display();
        cout << " длина = " << arr[i].len() << endl;
    }
    
    // 4. Ввод с клавиатуры
    cout << "\n--- Ввод с клавиатуры ---" << endl;
    Vector3DClass v;
    cout << "Введите вектор: ";
    v.read();
    cout << "Вы ввели: "; v.display(); cout << endl;
    cout << "Его длина: " << v.len() << endl;
    
    cout << "\n=== КОНЕЦ ===" << endl;
    
    return 0;
}
