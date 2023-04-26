#include "classes.h"
#include <iostream>

// initialisation des attributs statiques, initialises a 0 par default
int Batiment::lastId = 0;
int Materiel::lastId = 0;

// ici l'implementation de la classe Batiment et de ses methodes

Batiment::Batiment(int num, TypeBatiment type) : num(num), type(type) {
    id = ++lastId;
}

int Batiment::getId() const {
    return id;
}

int Batiment::getNum() const {
    return num;
}

TypeBatiment Batiment::getType() const {
    return type;
}

int Batiment::getNbMateriel() const {
    return materiels.size();
}

void Batiment::setNum(int num) {
    this->num = num;
}

void Batiment::addMateriel(const std::string &materiel) {
    if (materiels.size() < 4) {
        materiels.push_back(materiel);
    } else {
        std::cerr << "Impossible d'ajouter de matériaux au batiment: le nombre maximum de materiaux à été atteint"
                  << std::endl;
    }
}

void Batiment::afficherInfos() const {
    std::cout << "Batiment #" << id << " - Num: " << num << " - Type: ";
    if (type == ADMINISTRATIVE) {
        std::cout << "Administrative";
    } else if (type == SCOLAIRE) {
        std::cout << "Scolaire";
    }
    std::cout << " - Materiels: ";
    for (const auto &materiel: materiels) {
        std::cout << materiel << ", ";
    }
    std::cout << std::endl;
}

// Implemetation de la classe Materiel et de ses methodes

Materiel::Materiel(const std::string &numSerie, const std::string &designation, const std::string &dateCreation,
                   int idBatiment)
        : numSerie(numSerie), designation(designation), dateCreation(dateCreation), idBatiment(idBatiment) {
    id = ++lastId;
}

int Materiel::getId() const {
    return id;
}

const std::string &Materiel::getNumSerie() const {
    return numSerie;
}

const std::string &Materiel::getDesignation() const {
    return designation;
}

const std::string &Materiel::getDateCreation() const {
    return dateCreation;
}

int Materiel::getIdBatiment() const {
    return idBatiment;
}

void Materiel::setIdBatiment(int idBatiment) {
    this->idBatiment = idBatiment;
}

void Materiel::afficherInfos() const {
    std::cout << "Materiel #" << id << " - Num serie: " << numSerie << " - Designation: " << designation
              << " - Date creation: " << dateCreation << " - Batiment: #" << idBatiment << std::endl;
}

// Implemetation de la classe Server et de ses methodes

Server::Server(const std::string &numSerie, const std::string &designation, const std::string &dateCreation,
               int idBatiment, int espaceDisque)
        : Materiel(numSerie, designation, dateCreation, idBatiment), espaceDisque(espaceDisque) {}

int Server::getEspaceDisque() const {
    return espaceDisque;
}

void Server::afficherInfos() const {
    std::cout << "Server #" << getId() << " - Num serie: " << getNumSerie() << " - Designation: " << getDesignation()
              << " - Date creation: " << getDateCreation() << " - Batiment: #" << getIdBatiment()
              << " - Espace disque: " << espaceDisque << " GB" << std::endl;
}

// Implemetation de la classe Imprimante et de ses methodes

Imprimante::Imprimante(const std::string &numSerie, const std::string &designation, const std::string &dateCreation,
                       int idBatiment, int resolution)
        : Materiel(numSerie, designation, dateCreation, idBatiment), resolution(resolution) {}

int Imprimante::getResolution() const {
    return resolution;
}

void Imprimante::afficherInfos() const {
    std::cout << "Imprimante #" << getId() << " - Num serie: " << getNumSerie() << " - Designation: "
              << getDesignation()
              << " - Date creation: " << getDateCreation() << " - Batiment: #" << getIdBatiment() << " - Resolution: "
              << resolution << " dpi" << std::endl;
}