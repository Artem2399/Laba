#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Шаблонный класс CircularBuffer
template <typename T, size_t Size>
class CircularBuffer {
private:
    T buffer[Size];
    size_t head = 0;
    size_t tail = 0;
    size_t count = 0;
    bool full = false;

public:
    // Конструктор
    CircularBuffer() = default;

    // Очистка буфера
    void clear() {
        head = tail = count = 0;
        full = false;
    }

    // Добавление элемента с автоматической перезаписью
    void enqueue(const T& value) {
        buffer[head] = value;
        if (full) {
            tail = (tail + 1) % Size;
        }
        head = (head + 1) % Size;
        full = (head == tail);
        if (!full) {
            count++;
        }
    }

    // Извлечение элемента
    T dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Buffer is empty");
        }
        T value = buffer[tail];
        tail = (tail + 1) % Size;
        full = false;
        count--;
        return value;
    }

    // Получение размера (количество элементов)
    size_t size() const {
        return count;
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return (!full && (head == tail));
    }

    // Проверка на заполненность
    bool isFull() const {
        return full;
    }

    // Возврат содержимого в виде строки
    string toString() const {
        if (isEmpty()) {
            return "[]";
        }
        ostringstream oss;
        oss << "[";
        size_t index = tail;
        for (size_t i = 0; i < count; i++) {
            oss << buffer[index];
            if (i < count - 1) {
                oss << ", ";
            }
            index = (index + 1) % Size;
        }
        oss << "]";
        return oss.str();
    }

    // Перегрузка оператора вывода в поток
    friend ostream& operator<<(ostream& os, const CircularBuffer& buf) {
        os << buf.toString();
        return os;
    }

    // Чтение содержимого из потока
    friend istream& operator>>(istream& is, CircularBuffer& buf) {
        T value;
        while (is >> value) {
            buf.enqueue(value);
        }
        return is;
    }
};

// Пример использования
int main() {
    // Создаем циклический буфер на 5 элементов типа int
    CircularBuffer<int, 5> buffer;

    // Добавляем элементы
    buffer.enqueue(1);
    buffer.enqueue(2);
    buffer.enqueue(3);
    buffer.enqueue(4);
    buffer.enqueue(5);

    cout << "Буфер после заполнения: " << buffer << endl;
    cout << "Размер: " << buffer.size() << endl;
    cout << "Полный? " << (buffer.isFull() ? "Да" : "Нет") << endl;

    // Добавляем еще один элемент (автоперезапись)
    buffer.enqueue(6);
    cout << "Буфер после добавления 6: " << buffer << endl;

    // Извлекаем элементы
    cout << "Извлечен: " << buffer.dequeue() << endl;
    cout << "Буфер после извлечения: " << buffer << endl;

    // Очистка
    buffer.clear();
    cout << "Буфер после очистки: " << buffer << endl;
    cout << "Пустой? " << (buffer.isEmpty() ? "Да" : "Нет") << endl;

    // Тестирование с другими типами
    CircularBuffer<string, 3> strBuffer;
    strBuffer.enqueue("Hello");
    strBuffer.enqueue("World");
    strBuffer.enqueue("C++");

    cout << "\nСтроковый буфер: " << strBuffer << endl;
    strBuffer.enqueue("New");
    cout << "После добавления 'New': " << strBuffer << endl;

    return 0;
}
