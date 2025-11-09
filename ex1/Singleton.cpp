#include <iostream>
#include <string>

class Configuration {
private:
    std::string cheminFichier = "config.txt";
    std::string utilisateur = "admin";
    std::string motDePasse = "1234";

    Configuration() {}
    Configuration(const Configuration&) = delete;
    Configuration& operator=(const Configuration&) = delete;

public:
    static Configuration& getInstance() {
        static Configuration instance;
        return instance;
    }

    void afficherParametres() const {
        std::cout << "Chemin fichier : " << cheminFichier << std::endl;
        std::cout << "Utilisateur : " << utilisateur << std::endl;
        std::cout << "Mot de passe : " << motDePasse << std::endl;
    }
};

int main() {
    Configuration& config = Configuration::getInstance();
    config.afficherParametres();
    return 0;
}
