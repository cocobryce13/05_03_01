#include <iostream>
#include <string>

class Figure  // Фигура
{
public:
    virtual void print_info() const 
    {
        std::cout << "Figure:" << std::endl; // Фигура
        std::cout << (check() ? "Correct" : "Incorrect") << std::endl; // Правильная или Неправильная
        std::cout << "Number of sides: " << sides_count << std::endl; // Количество сторон
        std::cout << std::endl;
    }
    virtual bool check() const 
    {
        return true; 
    }
    virtual ~Figure() = default; 
protected:
    int sides_count = 0;
};

class Triangle : public Figure   // Треугольник
{
public:
    Triangle(int a, int b, int c, int A, int B, int C) : a(a), b(b), c(c), A(A), B(B), C(C) 
    {
        sides_count = 3;
    }

    void print_info() const override 
    {
        std::cout << "Triangle:" << std::endl; 
        Figure::print_info();
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << std::endl; // Стороны
        std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << std::endl; // Углы
        std::cout << std::endl;
    }

    bool check() const override 
    {
        return A + B + C == 180; // Проверка
    }

protected:
    int a, b, c;
    int A, B, C;
};

class RightTriangle : public Triangle 
{
public:
    RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)  // Прямоугольный треугольник
    {
    }

    void print_info() const override 
    {
        std::cout << "Right Triangle:" << std::endl;
        Triangle::print_info();
    }

    bool check() const override {
        return Triangle::check() && C == 90;   // Проверка
    }
};

class IsoscelesTriangle : public Triangle  // Равнобедренный треугольник
{
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A) {
    }

    void print_info() const override
    {
        std::cout << "Isosceles Triangle:" << std::endl;
        Triangle::print_info();
    }

    bool check() const override 
    {
        return Triangle::check() && (a == c) && (A == C);
    }
};

class EquilateralTriangle : public Triangle   //Равносторонний треугольник)
{
public:
    EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {}

    void print_info() const override 
    {
        std::cout << "Equilateral Triangle:" << std::endl;
        Triangle::print_info();
    }

    bool check() const override 
    {
        return Triangle::check() && (a == b && b == c) && (A == 60 && B == 60 && C == 60);
    }
};

class Quadrangle : public Figure  // Четырёхугольник
{
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) 
    {
        sides_count = 4;
    }

    void print_info() const override 
    {
        std::cout << "Quadrangle:" << std::endl;
        Figure::print_info();
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl; // Стороны
        std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl; // Углы
        std::cout << std::endl;
    }

    bool check() const override 
    {
        return A + B + C + D == 360; // Проверка
    }

protected:
    int a, b, c, d;
    int A, B, C, D;
};

class Rectangle : public Quadrangle  // Прямоугольник
{
public:
    Rectangle(int a, int b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {}

    void print_info() const override 
    {
        std::cout << "Rectangle:" << std::endl;
        Quadrangle::print_info();
    }

    bool check() const override 
    {
        return Quadrangle::check(); // Проверка
    }
};

class Square : public Rectangle  // Квадрат
{
public:
    Square(int a) : Rectangle(a, a) {}

    void print_info() const override 
    {
        std::cout << "Square:" << std::endl;
        Rectangle::print_info();
    }
};

class Parallelogram : public Quadrangle      // Параллелограмм
{   
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) 
    {
    }

    void print_info() const override 
    {
        std::cout << "Parallelogram:" << std::endl;
        Quadrangle::print_info();
    }

    bool check() const override 
    {
        return Quadrangle::check() && (a == c && b == d) && (A == C && B == D); // Проверка 
    }
};

class Rhombus : public Parallelogram   // Ромб
{
public:
    Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B) {}

    void print_info() const override 
    {
        std::cout << "Rhombus:" << std::endl;
        Parallelogram::print_info();
    }
};

int main() {
    setlocale(LC_ALL, "ru");

        Figure* figures[] = 
    {
        new Triangle(10, 20, 30, 50, 60, 70),          // Треугольник
        new RightTriangle(10, 20, 30, 50, 40),        // Прямоугольный треугольник
        new IsoscelesTriangle(10, 20, 50, 80),        // Равнобедренный треугольник
        new EquilateralTriangle(30),                 // Равносторонний треугольник
        new Quadrangle(10, 20, 30, 40, 40, 60, 40, 60), // Четырёхугольник
        new Rectangle(10, 20),                       // Прямоугольник
        new Square(20),                              // Квадрат
        new Parallelogram(20, 30, 50, 130),          // Параллелограмм
        new Rhombus(30, 50, 130)                     // Ромб
    };

    for (Figure* figure : figures) 
    {
        figure->print_info();
        delete figure; // Удаление фигуры 
    }

    return 0;
}
