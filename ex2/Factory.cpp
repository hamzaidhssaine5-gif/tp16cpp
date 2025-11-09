#include <iostream>
#include <string>

class Forme {
public:
    virtual void afficher() const = 0;
    virtual ~Forme() = default;
};

class Cercle : public Forme {
public:
    void afficher() const override {
        std::cout << "Cercle" << std::endl;
    }
};

class Carre : public Forme {
public:
    void afficher() const override {
        std::cout << "Carré" << std::endl;
    }
};

class Triangle : public Forme {
public:
    void afficher() const override {
        std::cout << "Triangle" << std::endl;
    }
};

class FabriqueForme {
public:
    static Forme* creerForme(const std::string& type) {
        if (type == "cercle") return new Cercle();
        if (type == "carre") return new Carre();
        if (type == "triangle") return new Triangle();
        return nullptr;
    }
};

int main() {
    Forme* f1 = FabriqueForme::creerForme("cercle");
    Forme* f2 = FabriqueForme::creerForme("carre");
    Forme* f3 = FabriqueForme::creerForme("triangle");

    if(f1) f1->afficher();
    if(f2) f2->afficher();
    if(f3) f3->afficher();

    delete f1;
    delete f2;
    delete f3;

    return 0;
}
