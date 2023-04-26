#ifndef __MATERIEL_H__
#define __MATERIEL_H__

#include <iostream>
#include <string>
#include <vector>

enum TypeBatiment {
    ADMINISTRATIVE,
    SCOLAIRE
};

class Batiment {
public:
    Batiment(int num, TypeBatiment type);

    virtual ~Batiment() = default;

    int getId() const;

    int getNum() const;

    TypeBatiment getType() const;

    int getNbMateriel() const;

    void setNum(int num);

    void addMateriel(const std::string &materiel);

    virtual void afficherInfos() const;

private:
    static int lastId;
    int id;
    int num;
    TypeBatiment type;
    std::vector<std::string> materiels;
};

class Materiel {
public:
    Materiel(const std::string &numSerie, const std::string &designation, const std::string &dateCreation,
             int idBatiment);

    virtual ~Materiel() = default;

    int getId() const;

    const std::string &getNumSerie() const;

    const std::string &getDesignation() const;

    const std::string &getDateCreation() const;

    int getIdBatiment() const;

    void setIdBatiment(int idBatiment);

    virtual void afficherInfos() const;

private:
    static int lastId;
    int id;
    std::string numSerie;
    std::string designation;
    std::string dateCreation;
    int idBatiment;
};

class Server : public Materiel {
public:
    Server(const std::string &numSerie, const std::string &designation, const std::string &dateCreation, int idBatiment,
           int espaceDisque);

    int getEspaceDisque() const;

    virtual void afficherInfos() const override;

private:
    int espaceDisque;
};

class Imprimante : public Materiel {
public:
    Imprimante(const std::string &numSerie, const std::string &designation, const std::string &dateCreation,
               int idBatiment, int resolution);

    int getResolution() const;

    virtual void afficherInfos() const override;

private:
    int resolution;
};

// juste un helper utilisé pour gerer les batiments
class GestionnaireBatiment {
public:
    GestionnaireBatiment();

    ~GestionnaireBatiment();

    void ajouterBatiment(int num, TypeBatiment type);

    void ajouterServer(const Server &server);

    void ajouterImprimante(const Imprimante &imprimante);

    void afficherMateriels(int idBatiment) const;

private:
    std::vector<Batiment> batiments;
    std::vector<Server> servers;
    std::vector<Imprimante> imprimantes;

    int findBatiment(int idBatiment) const;
};

#endif // __MATERIEL_H__
