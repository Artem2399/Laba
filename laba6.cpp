#include <iostream>
#include <iomanip> // управления форматированием данных в потоках вывода (setw)

using namespace std;

class Array {
protected:
    static const int MAX = 100;
    unsigned char arr[MAX];
    int len;

public:
    Array(int n = 0, unsigned char value = 0) {
        if (n < 0) n = 0;
        if (n > MAX) n = MAX;
        len = n;
        for (int i = 0; i < len; i++)
            arr[i] = value;
    }

    virtual ~Array() {}

    int length() const {
        return len;
    }

    unsigned char& operator[](int index) {
        static unsigned char dummy = 0;
        if (index < 0 || index >= len)
            return dummy;
        return arr[index];
    }

    // Виртуальное поэлементное сложение
    virtual Array operator+(Array& other) {
        int maxLen = (len > other.len) ? len : other.len;
        Array result(maxLen);

        for (int i = 0; i < maxLen; i++) {
            unsigned char a = (i < len) ? arr[i] : 0;
            unsigned char b = (i < other.len) ? other.arr[i] : 0;
            result.arr[i] = a + b;
        }
        return result;
    }

    virtual void print() const {
        for (int i = 0; i < len; i++)
            cout << (int)arr[i] << " ";
        cout << endl;
    }
};

class BitString : public Array {
public:
    BitString(int n = 0) : Array(n, 0) {}

    // Переопределение виртуального метода
    virtual Array operator+(Array& other) override {
        int maxLen = (len > other.length()) ? len : other.length();
        BitString result(maxLen);

        for (int i = 0; i < maxLen; i++) {
            unsigned char a = (i < len) ? arr[i] : 0;
            unsigned char b = (i < other.length()) ? other[i] : 0;
            result[i] = (a + b) % 2;   // сложение по модулю 2
        }
        return result;
    }

    virtual void print() const override {
        for (int i = 0; i < len; i++)
            cout << (int)arr[i];
        cout << endl;
    }
};

class Hex : public Array {
public:
    Hex(int n = 0) : Array(n, 0) {}

    // Переопределение виртуального метода
    virtual Array operator+(Array& other) override {
        int maxLen = (len > other.length()) ? len : other.length();
        Hex result(maxLen);

        unsigned char carry = 0;
        for (int i = 0; i < maxLen; i++) {
            unsigned char a = (i < len) ? arr[i] : 0;
            unsigned char b = (i < other.length()) ? other[i] : 0;

            unsigned char sum = a + b + carry;
            result[i] = sum % 16;
            carry = sum / 16;
        }
        return result;
    }

    virtual void print() const override {
        for (int i = len - 1; i >= 0; i--) {
            cout << hex << uppercase << (int)arr[i] << " ";
            if (i == 0) break;
        }
        cout << dec << endl;
    }
};

int main() {
    cout << "=== BIT STRING ===" << endl;

    BitString b1(8), b2(8);

    b1[0] = 1; b1[2] = 1; b1[5] = 1;
    b2[1] = 1; b2[2] = 1; b2[6] = 1;

    Array* p;

    p = &b1;
    cout << "b1 = "; p->print();

    p = &b2;
    cout << "b2 = "; p->print();

    Array bsum = b1 + b2;
    cout << "b1 + b2 = ";
    bsum.print();

    cout << "=== HEX ===" << endl;

    Hex h1(4), h2(4);

    h1[0] = 10; h1[1] = 5;   // 5A
    h2[0] = 6;  h2[1] = 9;   // 96

    p = &h1;
    cout << "h1 = "; p->print();

    p = &h2;
    cout << "h2 = "; p->print();

    Array hsum = h1 + h2;
    cout << "h1 + h2 = ";
    hsum.print();

    return 0;
}
