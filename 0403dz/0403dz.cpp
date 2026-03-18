#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;


class Equation {
public:
    virtual void solve() = 0;
    virtual ~Equation() {}
};

class LinearEquation : public Equation {
    double a, b;
public:
    LinearEquation(double a, double b) : a(a), b(b) {}

    void solve() override {
        if (a != 0)
            cout << "Linear: x = " << -b / a << endl;
        else
            cout << "Linear: No solution\n";
    }
};

class QuadraticEquation : public Equation {
    double a, b, c;
public:
    QuadraticEquation(double a, double b, double c)
        : a(a), b(b), c(c) {
    }

    void solve() override {
        double D = b * b - 4 * a * c;

        if (D > 0) {
            cout << "Quadratic: x1 = " << (-b + sqrt(D)) / (2 * a)
                << ", x2 = " << (-b - sqrt(D)) / (2 * a) << endl;
        }
        else if (D == 0) {
            cout << "Quadratic: x = " << -b / (2 * a) << endl;
        }
        else {
            cout << "Quadratic: No real roots\n";
        }
    }
};

class Shape {
public:
    virtual void Show() = 0;
    virtual void Save(ofstream& out) = 0;
    virtual void Load(ifstream& in) = 0;
    virtual ~Shape() {}
};


class Square : public Shape {
    int x, y, s;
public:
    Square(int x = 0, int y = 0, int s = 0) :x(x), y(y), s(s) {}

    void Show() override {
        cout << "Square: (" << x << "," << y << "), side=" << s << endl;
    }

    void Save(ofstream& out) override {
        out << "Square " << x << " " << y << " " << s << endl;
    }

    void Load(ifstream& in) override {
        in >> x >> y >> s;
    }
};

class Rectangle : public Shape {
    int x, y, w, h;
public:
    Rectangle(int x = 0, int y = 0, int w = 0, int h = 0) :x(x), y(y), w(w), h(h) {}

    void Show() override {
        cout << "Rectangle: (" << x << "," << y << "), w=" << w << ", h=" << h << endl;
    }

    void Save(ofstream& out) override {
        out << "Rectangle " << x << " " << y << " " << w << " " << h << endl;
    }

    void Load(ifstream& in) override {
        in >> x >> y >> w >> h;
    }
};


class Circle : public Shape {
    int x, y, r;
public:
    Circle(int x = 0, int y = 0, int r = 0) :x(x), y(y), r(r) {}

    void Show() override {
        cout << "Circle: center(" << x << "," << y << "), r=" << r << endl;
    }

    void Save(ofstream& out) override {
        out << "Circle " << x << " " << y << " " << r << endl;
    }

    void Load(ifstream& in) override {
        in >> x >> y >> r;
    }
};

class Ellipse : public Shape {
    int x, y, w, h;
public:
    Ellipse(int x = 0, int y = 0, int w = 0, int h = 0) :x(x), y(y), w(w), h(h) {}

    void Show() override {
        cout << "Ellipse: (" << x << "," << y << "), w=" << w << ", h=" << h << endl;
    }

    void Save(ofstream& out) override {
        out << "Ellipse " << x << " " << y << " " << w << " " << h << endl;
    }

    void Load(ifstream& in) override {
        in >> x >> y >> w >> h;
    }
};


Shape* createShape(const string& type) {
    if (type == "Square") return new Square();
    if (type == "Rectangle") return new Rectangle();
    if (type == "Circle") return new Circle();
    if (type == "Ellipse") return new Ellipse();
    return nullptr;
}

int main() {


    cout << "=== TASK 1 ===\n";

    Equation* eq[2];
    eq[0] = new LinearEquation(2, -4);
    eq[1] = new QuadraticEquation(1, -3, 2);

    for (int i = 0; i < 2; i++) {
        eq[i]->solve();
        delete eq[i];
    }

 
    cout << "\n=== TASK 2 ===\n";

    Shape* shapes[4];
    shapes[0] = new Square(1, 2, 5);
    shapes[1] = new Rectangle(0, 0, 4, 6);
    shapes[2] = new Circle(3, 3, 7);
    shapes[3] = new Ellipse(2, 2, 8, 4);

    ofstream out("shapes.txt");
    for (int i = 0; i < 4; i++) {
        shapes[i]->Save(out);
    }
    out.close();

    ifstream in("shapes.txt");
    Shape* loaded[4];

    for (int i = 0; i < 4; i++) {
        string type;
        in >> type;
        loaded[i] = createShape(type);
        loaded[i]->Load(in);
    }
    in.close();

    cout << "\nLoaded shapes:\n";
    for (int i = 0; i < 4; i++) {
        loaded[i]->Show();
    }

    for (int i = 0; i < 4; i++) {
        delete shapes[i];
        delete loaded[i];
    }

    return 0;
}
