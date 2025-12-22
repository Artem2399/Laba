#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

// структура коэффициентов
struct LinearEquation {
    double a;
    double b;
    LinearEquation(double pa, double pb) : a(pa), b(pb) {}
};

// пустое исключение
class EmptyException {};

// собственное исключение с сообщением
class MyException {
public:
    string msg;
    MyException(const string& m) : msg(m) {}
};

// наследник стандартного исключения
class MyStdException : public invalid_argument {
public:
    MyStdException(const string& m) : invalid_argument(m) {}
};

//
// 1. Без спецификации исключений
//
double Solve1(LinearEquation e) {
    if (isnan(e.a)  isnan(e.b)  e.a == 0)
        throw 1.0;
    return -e.b / e.a;
}

//
// 2. (бывш.) со спецификацией throw() — убрано для C++17
//
double Solve2(LinearEquation e) {
    if (isnan(e.a)  isnan(e.b)  e.a == 0)
        throw 1.0;
    return -e.b / e.a;
}

//
// 3. Со стандартным исключением
//
double Solve3(LinearEquation e) {
    if (isnan(e.a)) throw invalid_argument("a is NaN");
    if (isnan(e.b)) throw invalid_argument("b is NaN");
    if (e.a == 0) throw invalid_argument("a = 0");
    return -e.b / e.a;
}

//
// 4. Собственные исключения
//

// 4.1 пустой класс
double Solve4_Empty(LinearEquation e) {
    if (isnan(e.a)  isnan(e.b)  e.a == 0)
        throw EmptyException();
    return -e.b / e.a;
}

// 4.2 класс с сообщением
double Solve4_My(LinearEquation e) {
    if (e.a == 0)
        throw MyException("division by zero");
    return -e.b / e.a;
}

// 4.3 наследник std::exception
double Solve4_Std(LinearEquation e) {
    if (e.a == 0)
        throw MyStdException("division by zero");
    return -e.b / e.a;
}

//
// main — обработка всех исключений
//
int main() {
    LinearEquation eq(0, 5); // ошибка: a = 0

    try { cout << Solve1(eq) << endl; }
    catch (double) { cout << "Solve1 error\n"; }

    try { cout << Solve2(eq) << endl; }
    catch (double) { cout << "Solve2 error\n"; }

    try { cout << Solve3(eq) << endl; }
    catch (invalid_argument& e) { cout << e.what() << endl; }

    try { cout << Solve4_Empty(eq) << endl; }
    catch (EmptyException) { cout << "EmptyException\n"; }

    try { cout << Solve4_My(eq) << endl; }
    catch (MyException& e) { cout << e.msg << endl; }

    try { cout << Solve4_Std(eq) << endl; }
    catch (MyStdException& e) { cout << e.what() << endl; }

    return 0;
}
