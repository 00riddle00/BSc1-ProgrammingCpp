#include<iostream>
#include <iomanip>
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

#include "object.h"
#include "mystack.h"
#include "automobilis.h"

// FIXME rm this temp solution
//#include "mystack.cpp"
//#include "object.cpp"
using namespace std;
// Pure abstract class
class GeomFigura : public Object {

    public:
        GeomFigura() {
            cout << "GeomFigura is created" << endl;
        }

        virtual ~GeomFigura() = 0;

        virtual void printInfo() = 0;

        virtual float plotas() const = 0;

        virtual float turis() const = 0;
};

GeomFigura::~GeomFigura() {
    cout << "GeomFigura is destroyed" << endl;
}

// Abstract class
class Figura2D : public GeomFigura {
    float x_coordinate;
    float y_coordinate;

    public:
        Figura2D(float x, float y) : x_coordinate(x), y_coordinate(y) {
            cout << "Figura2D is created" << endl;
        }

        virtual ~Figura2D() = 0;

        void printCoordinates() {
            cout << "Coordinates: x = " << fixed << setprecision(1) << x_coordinate
                 << ", y = " << y_coordinate << endl;
        }

        virtual float turis() const override {
            return 0.0;
        }
};

Figura2D::~Figura2D() {
    cout << "Figura2D is destroyed" << endl;
}

// Abstract class
class Figura3D : public GeomFigura {
    float x_coordinate;
    float y_coordinate;
    float z_coordinate;

    public:
        Figura3D(float x, float y, float z) : x_coordinate(x), y_coordinate(y), z_coordinate(z) {
            cout << "Figura3D is created" << endl;
        }

        virtual ~Figura3D() = 0;

        void printCoordinates() {
            cout << "Coordinates: x = " << fixed << setprecision(1) << x_coordinate
                 << ", y = " << y_coordinate << ", z = " << z_coordinate << endl;
        }
};

Figura3D::~Figura3D() {
    cout << "Figura3D is destroyed" << endl;
}


class Kvadratas : public Figura2D {
    float krastine;

    public:
        Kvadratas(float x, float y, float k) : Figura2D(x, y), krastine(k) {
            cout << "Kvadratas is created" << endl;
        }

        ~Kvadratas() {
            cout << "Kvadratas is destroyed" << endl;
        }

        virtual void printInfo() override {
            cout << "Kvadratas, krastine = " << fixed << setprecision(1) << krastine << endl;
            printCoordinates();
        }

        virtual float plotas() const override {
            return pow(krastine, 2);
        }
};


class Skritulys : public Figura2D {
    float spindulys;

    public:
        Skritulys(float x, float y, float s) : Figura2D(x, y), spindulys(s) {
            cout << "Skritulys is created" << endl;
        }

        ~Skritulys() {
            cout << "Skritulys is destroyed" << endl;
        }

        virtual void printInfo() override {
            cout << "Skritulys, spindulys = " << fixed << setprecision(1) << spindulys << endl;
            printCoordinates();
        }

        virtual float plotas() const override {
            return pow(M_PI * spindulys, 2);
        }
};


class Kubas : public Figura3D {
    float krastine;

    public:
        Kubas(float x, float y, float z, float k) : Figura3D(x, y, z), krastine(k) {
            cout << "Kubas is created" << endl;
        }

        ~Kubas() {
            cout << "Kubas is destroyed" << endl;
        }

        virtual void printInfo() override {
            cout << "Kubas, krastine = " << fixed << setprecision(1) << krastine << endl;
            printCoordinates();
        }

        virtual float plotas() const override {
            return pow(krastine, 2) * 6;
        }

        virtual float turis() const override {
            return pow(krastine, 3);
        }
};


class Sfera : public Figura3D {
    float spindulys;

    public:
        Sfera(float x, float y, float z, float s) : Figura3D(x, y, z), spindulys(s) {
            cout << "Sfera is created" << endl;
        }

        ~Sfera() {
            cout << "Sfera is destroyed" << endl;
        }

        virtual void printInfo() override {
            cout << "Sfera, spindulys = " << fixed << setprecision(1) << spindulys << endl;
            printCoordinates();
        }

        virtual float plotas() const override {
            return 4 * M_PI * pow(spindulys, 2);
        }

        virtual float turis() const override {
            return  4/3 * M_PI * pow(spindulys, 3);
        }
};


int main()
{
    AutoStack S;

    S.MyStackPrint();

    Object* auto1 = new Automobilis("Skoda", "Octavia", 2.0, 2010, 4000);
    Object* auto2 = new Automobilis("Volkswagen", "Golf", 2.0, 2006, 3000);

    Object* kvadr1 = new Kvadratas(2.0, 3.0, 4.0);
    Object* kvadr2 = new Kvadratas(3.0, 5.0, 8.0);

    if (!S.push(auto1)) {
        delete auto1;
    }

    if (!S.push(auto2)) {
        delete auto2;
    }

    S.push(kvadr1);
    S.push(kvadr2);
   
    cout << "----------------" << endl;
    S.MyStackPrint();
    cout << "----------------" << endl;

    try {
        auto2 = S.pop();
    } catch(const char* s) {
        cout << s << endl;
    }

    cout << "Popped value is: " << endl;

    //auto2->print();

    cout << "----------------" << endl;
    S.MyStackPrint();
    cout << "----------------" << endl;


/*    Automobilis* auto3 = new Automobilis("BMW", "520", 2.0, 2010, 4000);*/
    //Automobilis* auto4 = new Automobilis("Audi", "100", 2.0, 2006, 3000);

    //Automobilis* autos[] = {auto3, auto4};
    //AutoStack S2(autos, sizeof(autos)/sizeof(autos[0]));

    //cout << "----------------" << endl;
    //S2.MyStackPrint();
    //cout << "----------------" << endl;

    /*delete auto2;*/
}

