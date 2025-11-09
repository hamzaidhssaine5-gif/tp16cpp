#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class StrategieTri {
public:
    virtual void trier(std::vector<std::string>& donnees) = 0;
    virtual ~StrategieTri() = default;
};

class TriCroissant : public StrategieTri {
public:
    void trier(std::vector<std::string>& donnees) override {
        std::sort(donnees.begin(), donnees.end());
    }
};

class TriDecroissant : public StrategieTri {
public:
    void trier(std::vector<std::string>& donnees) override {
        std::sort(donnees.begin(), donnees.end(), std::greater<>());
    }
};

class TriParLongueur : public StrategieTri {
public:
    void trier(std::vector<std::string>& donnees) override {
        std::sort(donnees.begin(), donnees.end(),
                  [](const std::string& a, const std::string& b) {
                      return a.size() < b.size();
                  });
    }
};

class GestionnaireTri {
private:
    StrategieTri* strategie = nullptr;

public:
    void setStrategie(StrategieTri* strat) {
        strategie = strat;
    }

    void trierDonnees(std::vector<std::string>& donnees) {
        if (strategie) {
            strategie->trier(donnees);
        }
    }
};

int main() {
    std::vector<std::string> mots = {"pomme", "banane", "cerise", "kiwi", "abricot"};

    TriCroissant triC;
    TriDecroissant triD;
    TriParLongueur triL;

    GestionnaireTri gestionnaire;

    gestionnaire.setStrategie(&triC);
    gestionnaire.trierDonnees(mots);
    for (const auto& mot : mots) std::cout << mot << ' ';
    std::cout << '\n';

    gestionnaire.setStrategie(&triD);
    gestionnaire.trierDonnees(mots);
    for (const auto& mot : mots) std::cout << mot << ' ';
    std::cout << '\n';

    gestionnaire.setStrategie(&triL);
    gestionnaire.trierDonnees(mots);
    for (const auto& mot : mots) std::cout << mot << ' ';
    std::cout << '\n';

    return 0;
}
