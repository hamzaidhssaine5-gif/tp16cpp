#include <iostream>
#include <vector>
#include <algorithm>

class Observateur {
public:
    virtual void mettreAJour(float temperature, float humidite, float pression) = 0;
    virtual ~Observateur() = default;
};

class StationMeteo {
private:
    std::vector<Observateur*> observateurs;
    float temperature = 0.0f;
    float humidite = 0.0f;
    float pression = 0.0f;

public:
    void ajouterObservateur(Observateur* obs) {
        observateurs.push_back(obs);
    }

    void retirerObservateur(Observateur* obs) {
        observateurs.erase(std::remove(observateurs.begin(), observateurs.end(), obs), observateurs.end());
    }

    void notifier() {
        for (auto obs : observateurs) {
            obs->mettreAJour(temperature, humidite, pression);
        }
    }

    void setMesures(float temp, float hum, float pres) {
        temperature = temp;
        humidite = hum;
        pression = pres;
        notifier();
    }
};

class AffichageTemperature : public Observateur {
public:
    void mettreAJour(float temperature, float, float) override {
        std::cout << "Température mise à jour : " << temperature << " °C" << std::endl;
    }
};

class AffichageHumidite : public Observateur {
public:
    void mettreAJour(float, float humidite, float) override {
        std::cout << "Humidité mise à jour : " << humidite << " %" << std::endl;
    }
};

class AffichagePression : public Observateur {
public:
    void mettreAJour(float, float, float pression) override {
        std::cout << "Pression mise à jour : " << pression << " hPa" << std::endl;
    }
};

int main() {
    StationMeteo station;
    AffichageTemperature affichTemp;
    AffichageHumidite affichHum;
    AffichagePression affichPres;

    station.ajouterObservateur(&affichTemp);
    station.ajouterObservateur(&affichHum);
    station.ajouterObservateur(&affichPres);

    station.setMesures(25.0f, 65.0f, 1013.25f);
    station.setMesures(26.5f, 60.0f, 1012.80f);

    return 0;
}
