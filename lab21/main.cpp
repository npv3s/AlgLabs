#include <iostream>
#include <cstring>

class Unit {
protected:
    int health;
public:
    Unit() {
        health = 100;
    }

    ~Unit() = default;

    Unit &operator=(const Unit &t) {
        if (this == &t) return *this;
        health = t.health;
        return *this;
    }

    virtual int get_health() = 0;
};

class Car : public Unit {
protected:
    int engine;
    int wheel;
    char *id;
public:
    Car() {
        engine = 1;
        wheel = 4;
        id = new char[5];
        strcpy(id, "GD-6");
    }

    ~Car() {
        delete id;
    }

    Car &operator=(const Car &t) {
        if (this == &t) return *this;
        health = t.health;
        engine = t.engine;
        wheel = t.wheel;
        id = new char[strlen(t.id) + 1];
        strcpy(id, t.id);
        return *this;
    }

    int get_health() {
        return this->health;
    }

    int get_engine() {
        return this->engine;
    }

    int get_wheel() {
        return this->wheel;
    }

    char *get_id() {
        return this->id;
    }

};

class Plane : public Unit {
protected:
    int engine;
    int prop;
    char *code;
public:
    Plane() {
        engine = 2;
        prop = 2;
        code = new char[5];
        strcpy(code, "AB-3");
    }

    ~Plane() {
        delete code;
    }

    Plane &operator=(const Plane &t) {
        if (this == &t) return *this;
        health = t.health;
        engine = t.engine;
        prop = t.prop;
        code = new char[strlen(t.code) + 1];
        strcpy(code, t.code);
        return *this;
    }

    int get_health() {
        return this->health;
    }

    int get_engine() {
        return this->engine;
    }

    int get_prop() {
        return this->prop;
    }

    char *get_code() {
        return this->code;
    }

};

class CarPlane : public Car, public Plane {
    char *wtfisthis;
public:
    explicit CarPlane(char *str = "I don't know") {
        this->wtfisthis = new char[strlen(str) + 1];
        strcpy(this->wtfisthis, str);
    }

    ~CarPlane() {
        delete this->id;
        delete this->code;
        delete this->wtfisthis;
    }

    CarPlane &operator=(const CarPlane &t) {
        if (this == &t) return *this;
        Car::health = t.Car::health;
        Car::engine = t.Car::engine;
        wheel = t.wheel;
        wtfisthis = new char[strlen(t.wtfisthis) + 1];
        strcpy(wtfisthis, t.wtfisthis);
        id = new char[strlen(t.id) + 1];
        strcpy(id, t.id);
        code = new char[strlen(t.code) + 1];
        strcpy(code, t.code);
        return *this;
    }
};

int main() {
    CarPlane item = CarPlane();
    std::cout << item.Car::get_health() << std::endl;
    std::cout << item.get_id() << std::endl;
    std::cout << item.get_code() << std::endl;
    return 0;
}
