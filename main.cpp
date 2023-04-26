#include "lib/classes.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Batiment> batiments;
    std::vector<Server> servers;
    std::vector<Imprimante> imprimantes;

    int choix;
    do {
        // note: toutes les méthodes ne sont pas utilisées dans le programme
        // j'ai essayé de suivre exactement la consigne en n'ajoutant que ces entrées *dans le menu*
        // comme affiché dans le sujet
        // les ajouter serait simple, puisqu'elles sont déjà implémentées, d'ou j'imagine le fait que
        // vous ne le demandez pas?
        std::cout << "\n\n###################### Menu ######################" << std::endl;
        std::cout << "1- Ajout d'un batiment" << std::endl;
        std::cout << "2- Affecter un server a un batiment" << std::endl;
        std::cout << "3- Affecter une imprimante a un batiment" << std::endl;
        std::cout << "4- Afficher les materiels en fonction du numero de batiment" << std::endl;
        std::cout << "5- Quitter" << std::endl;
        std::cout << "\n Votre choix : ";
        std::cin >> choix;

        switch (choix) {
            case 1: {
                int num;
                std::cout << "Numero de batiment : ";
                std::cin >> num;

                if (num < 0) {
                    std::cerr << "Numero de batiment invalide." << std::endl;
                    break;
                }

                // n'accepter que des nombre, ceci va fail si cette contrainte n'est pas respectée
                if (std::cin.fail()) {
                    std::cerr << "Numero de batiment invalide." << std::endl;
                    break;
                }

                int typeInt;
                std::cout << "Type de batiment (0=Administrative, 1=Scolaire) : ";
                std::cin >> typeInt;

                if (typeInt != 0 && typeInt != 1) {
                    std::cerr << "Type de batiment invalide." << std::endl;
                    break;
                }

                TypeBatiment type = static_cast<TypeBatiment>(typeInt);

                batiments.emplace_back(num, type);
                std::cout << "Batiment ajoute avec succes." << std::endl;
                break;
            }
            case 2: {
                int idServer;
                std::cout << "ID du server : ";
                std::cin >> idServer;

                int idBatiment;
                std::cout << "ID du batiment : ";
                std::cin >> idBatiment;

                bool serverFound = false;
                bool batimentFound = false;

                for (auto &server: servers) {
                    if (server.getId() == idServer) {
                        serverFound = true;
                        for (auto &batiment: batiments) {
                            if (batiment.getId() == idBatiment) {
                                batimentFound = true;
                                server.setIdBatiment(idBatiment);
                                std::cout << "Serveur affecté au batiment avec succès." << std::endl;
                                break;
                            }
                        }
                        if (!batimentFound) {
                            std::cerr << "Batiment non trouve." << std::endl;
                        }
                        break;
                    }
                }
                if (!serverFound) {
                    std::cerr << "Serveur non trouve." << std::endl;
                }
                break;
            }
            case 3: {
                int idImprimante;
                std::cout << "ID de l'imprimante : ";
                std::cin >> idImprimante;

                int idBatiment;
                std::cout << "ID du batiment : ";
                std::cin >> idBatiment;

                bool imprimanteFound = false;
                bool batimentFound = false;

                for (auto &imprimante: imprimantes) {
                    if (imprimante.getId() == idImprimante) {
                        imprimanteFound = true;
                        for (auto &batiment: batiments) {
                            if (batiment.getId() == idBatiment) {
                                batimentFound = true;
                                imprimante.setIdBatiment(idBatiment);
                                std::cout << "Imprimante affectee au batiment avec succes." << std::endl;
                                break;
                            }
                        }
                        if (!batimentFound) {
                            std::cerr << "Batiment non trouve." << std::endl;
                        }
                        break;
                    }
                }
                if (!imprimanteFound) {
                    std::cerr << "Imprimante non trouvee." << std::endl;
                }
                break;
            }
            case 4: {
                int idBatiment;
                std::cout << "ID du batiment : ";
                std::cin >> idBatiment;

                bool batimentFound = false;

                for (auto &batiment: batiments) {
                    if (batiment.getId() == idBatiment) {
                        batimentFound = true;
                        std::cout << "Materiels du batiment " << idBatiment << ":" << std::endl;

                        for (auto &server: servers) {
                            if (server.getIdBatiment() == idBatiment) {
                                std::cout << "Server #" << server.getId() << std::endl;
                            }
                        }

                        for (auto &imprimante: imprimantes) {
                            if (imprimante.getIdBatiment() == idBatiment) {
                                std::cout << "Imprimante #" << imprimante.getId() << std::endl;
                            }
                        }

                        if (!servers.empty() && !imprimantes.empty()) {
                            std::cout << "Aucun materiel n'est affecte a ce batiment." << std::endl;
                        }
                        break;
                    }
                }
                if (!batimentFound) {
                    std::cerr << "Batiment non trouve." << std::endl;
                }
                break;
            }
            case 5:
                std::cout << "Au revoir !" << std::endl;
                break;
            default:
                std::cerr << "Choix invalide." << std::endl;
                break;
        }

    } while (choix != 5);

    return 0;
}