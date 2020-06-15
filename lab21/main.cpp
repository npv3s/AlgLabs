#include <iostream>
#include <cstring>

class Unit {
    int health;
public:
    Unit() {
        health = 100;
    }
    ~Unit() = default;
    int get_health() const {
        return this->health;
    }
};

class Car: public Unit {
    int engine;
    int wheel;
public:
    Car() {
        engine = 1;
        wheel = 4;
    }
    ~Car() = default;
    int get_engine() {
        return this->engine;
    }
    int get_wheel() {
        return this->wheel;
    }
};

class Plane: public Unit {
    int engine;
    int prop;
public:
    Plane() {
        engine = 2;
        prop = 2;
    }
    ~Plane() = default;
    int get_engine() {
        return this->engine;
    }
    int get_prop() {
        return this->prop;
    }
};

class CarPlane: public Car, public Plane {
    char *wtfisthis;
public:
    explicit CarPlane(char *str = "I don't know") {
        this->wtfisthis = new char[strlen(str) + 1];
        strcpy(this->wtfisthis, str);
    }
    ~CarPlane() {
        delete this->wtfisthis;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    CarPlane item = CarPlane();
    item.Car::get_health();
    return 0;
}
