#include "menu.h"
#include "interface.h"
#include "interfaceGraphique.h"
#include "interfaceAlphanumérique.h"
#include "interfaceFichier.h"
#include <memory>
menu::menu()
{
    afficherTitre();
    accueil();
}

void menu::accueil()
{
    int choixGraphe, choixRetour, choix ,visuel;
    cout<<"----------------------------------------"<<endl;
    cout<<"Quel type de graphe voulez-vous saisir ?"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"1 - Un graphe non oriente non value     "<<endl;
    cout<<"2 - Un graphe non oriente value         "<<endl;
    cout<<"3 - Un graphe oriente non value         "<<endl;
    cout<<"4 - Un graphe oriente value             "<<endl;
    cout<<"5 - Un graphe d'ordonnancement          "<<endl;
    cout<<"6 - Saisir un code de Prufer           "<<endl;
    cout<<"----------------------------------------"<<endl;
    cin>>choixGraphe;

    if(choixGraphe == 1)
    {
        choix = choixSaisie();
        if(choix == 1)
        {
            grapheNOrienteNV g;
            visuel = choixInterface();
            std::unique_ptr<interface> d_inter = creationInterface(visuel);
            d_inter->drawGraphNONV(g.adjacence);
            algoGrapheNOrienteNV(g);
        } else
        {
            grapheNOrienteNV g("fichier.txt");
            visuel = choixInterface();
            std::unique_ptr<interface> d_inter = creationInterface(visuel);
            d_inter->drawGraphNONV(g.adjacence);
            algoGrapheNOrienteNV(g);
        }
    }
    else if(choixGraphe == 2)
    {
        choix = choixSaisie();
        if(choix==1)
        {
            grapheNOrienteV g;
            visuel = choixInterface();
            std::unique_ptr<interface> d_inter = creationInterface(visuel);
            d_inter->drawGraphNOV(g.matriceCout);
            algoGrapheNOrienteV(g);
        }
        else
        {
            grapheNOrienteV g("fichier.txt");
            visuel = choixInterface();
            std::unique_ptr<interface> d_inter = creationInterface(visuel);
            d_inter->drawGraphNOV(g.matriceCout);
            algoGrapheNOrienteV(g);
        }
    }
    else if(choixGraphe == 3)
    {
        choix = choixSaisie();
        if(choix==1)
        {
            grapheOrienteNV g;
            visuel = choixInterface();
            std::unique_ptr<interface> d_inter = creationInterface(visuel);
            d_inter->drawGraphONV(g.matriceAdjacence);
            algoGrapheOrienteNV(g);
        }
        else
        {
            grapheOrienteNV g("fichier.txt");
            visuel = choixInterface();
            std::unique_ptr<interface> d_inter = creationInterface(visuel);
            d_inter->drawGraphONV(g.matriceAdjacence);
            algoGrapheOrienteNV(g);
        }
    }
    else if(choixGraphe == 4)
    {
        choix = choixSaisie();
        if(choix==1)
        {
            grapheOrienteV g;
            visuel = choixInterface();
            std::unique_ptr<interface> d_inter = creationInterface(visuel);
            d_inter->drawGraphOV(g.matriceCout);
            algoGrapheOrienteV(g);
        }
        else
        {
            grapheOrienteV g("fichier.txt");
            visuel = choixInterface();
            std::unique_ptr<interface> d_inter = creationInterface(visuel);
            d_inter->drawGraphOV(g.matriceCout);
            algoGrapheOrienteV(g);
        }
    }
    else if(choixGraphe ==  5)
    {
        visuel = choixInterface();
        std::unique_ptr<interface> d_inter = creationInterface(visuel);
        ordonnancement o;
        cout<<"----------------------------------------------"<<endl;
        cout<<"1 - Saisir un autre graphe"<<endl;
        cout<<"2 - Quitter"<<endl;
        cout<<"----------------------------------------"<<endl;
        cin>>choixRetour;

        if(choixRetour==1)
        {
            menu();
        }
        else if(choixRetour==2)
        {
            return;
        }
    }
    else if(choixGraphe ==  6)
    {
        visuel = choixInterface();
        std::unique_ptr<interface> d_inter = creationInterface(visuel);
        pruferDecodage g;
        d_inter->drawGraphNONV(g.adjacence);
        cout<<"----------------------------------------------"<<endl;
        cout<<"1 - Saisir un autre graphe"<<endl;
        cout<<"2 - Quitter"<<endl;
        cout<<"----------------------------------------"<<endl;
        cin>>choixRetour;

        if(choixRetour==1)
        {
            menu();
        }
        else if(choixRetour==2)
        {
            accueil();
        }
        else if(choixRetour==3)
        {
            return;
        }
    }

}

void menu::algoGrapheNOrienteNV(grapheNOrienteNV g){
    int choix, c;
    cout<<"----------------------------------------"<<endl;
    cout<<"Quel algorithme voulez vous appliquer ?"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"1 - Codage de Prufer                    "<<endl;
    cin>>choix;

    if(choix == 1)
    {
        pruferCodage p{g};
    }

    cout<<"----------------------------------------------"<<endl;
    cout<<"1 - Revenir au menu des algorithme à appliquer"<<endl;
    cout<<"2 - Saisir un autre graphe"<<endl;
    cout<<"3 - Quitter"<<endl;
    cin>>c;

    if(c==1)
    {
        algoGrapheNOrienteNV(g);
    }
    else if(c==2)
    {
        accueil();
    }
    else if(c==3)
    {
       return;
    }

}
void menu::algoGrapheOrienteNV(grapheOrienteNV g){
    int choix, c;
    cout<<"----------------------------------------"<<endl;
    cout<<"Quel algorithme voulez vous appliquer ?"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"1 - Distance                            "<<endl;
    cout<<"2 - Rang                                "<<endl;
    cout<<"3 - Tarjan                              "<<endl;
    cout<<"4 - Modifier le graphe                  "<<endl;
    cout<<"----------------------------------------"<<endl;
    cin>>choix;

    if(choix == 1)
    {
        distances s{g};
    }
    else if(choix == 2)
    {
        rang r{g};
    }
    else if(choix == 3)
    {
        tarjan t{g};
    }
    else if(choix == 4)
    {
       modifierGrapheOrienteNV(g);
    }

    cout<<"----------------------------------------------"<<endl;
    cout<<"1 - Revenir au menu des algorithme à appliquer"<<endl;
    cout<<"2 - Saisir un autre graphe"<<endl;
    cout<<"3 - Quitter"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cin>>c;

    if(c==1)
    {
        algoGrapheOrienteNV(g);
    }
    else if(c==2)
    {
        accueil();
    }
    else if(c==3)
    {
       return;
    }
}
void menu::algoGrapheOrienteV(grapheOrienteV g){
    int choix, c;
    cout<<"----------------------------------------"<<endl;
    cout<<"Quel algorithme voulez vous appliquer ?"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"1 - Dantzig                             "<<endl;
    cout<<"2 - Dijkstra                            "<<endl;
    cin>>choix;

    if(choix == 1)
    {
        dantzig t{g};
    }
    else if(choix == 2)
    {
        dijkstra d{g};
    }

    cout<<"----------------------------------------------"<<endl;
    cout<<"1 - Revenir au menu des algorithme à appliquer"<<endl;
    cout<<"2 - Saisir un autre graphe"<<endl;
    cout<<"3 - Quitter"<<endl;
    cin>>c;

    if(c==1)
    {
        algoGrapheOrienteV(g);
    }
    else if(c==2)
    {
        accueil();
    }
    else if(c==3)
    {
       return;
    }
}
void menu::algoGrapheNOrienteV(grapheNOrienteV g){
    int choix, c;
    cout<<"----------------------------------------"<<endl;
    cout<<"Quel algorithme voulez vous appliquer ?"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"1 - Kruskal                             "<<endl;
    cin>>choix;

    if(choix == 1)
    {
        kruskal l{g};
    }

    cout<<"----------------------------------------------"<<endl;
    cout<<"1 - Revenir au menu des algorithme à appliquer"<<endl;
    cout<<"2 - Saisir un autre graphe"<<endl;
    cout<<"3 - Quitter"<<endl;
    cin>>c;

    if(c==1)
    {
        algoGrapheNOrienteV(g);
    }
    else if(c==2)
    {
        accueil();
    }
    else if(c==3)
    {
        return;
    }
}
void menu::afficherTitre() {
cout << "  _____                 _                   _     _        " << endl;
cout << " / ____|               | |                 / \\   | |             " << endl;
cout << "| |  __ _ __ __ _ _ __ | |__   ___ ___    /   \\  | | ____ ____   " << endl;
cout << "| | |_ | '__/ _` | '_ \\| '_ \\ / _ / __| \ / /\\  \\ | |/ _  |/ _ \\  " << endl;
cout << "| |__| | | | (_| | |_) | | | |  __/ \__ \\/  ____ \\| | (_| | (_) | " << endl;
cout << " \\_____|_|  \\__,_| .__/|_| |_|\\___/|___/ __/   \\_\\_|\\__, |\\___/  " << endl;
cout << "                  | |                                __/ |       " << endl;
cout << "                  |_|                               |___/        " << endl;

}
std::unique_ptr<interface> menu::creationInterface(int a) const{
        if(a==1)
        {
            return std::make_unique<interfaceGraphique>();
        }
        else if(a==2)
        {
            return std::make_unique<interfaceAlphanumerique>();
        }
        else
        {
            return std::make_unique<interfaceFichier>();
        }
}
int menu::choixInterface(){
    int choixInterface;
    cout<<"============== INTERFACE ================"<<endl;
    cout<<"Comment voulez vous afficher votre graphe ?"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"1 - AffichageGraphique                    "<<endl;
    cout<<"2 - AffichageAlphanumerique                "<<endl;
    cout<<"3 - AffichageFichier                      "<<endl;
    cout<<"----------------------------------------"<<endl;
    cin>>choixInterface;

    while (choixInterface>3 || choixInterface<1)
    {
        cout<<"Erreur : Donnez 1 pour AffichageGraphique, 2 pour AffichageAlphanumérique et 3 pour AffichageFichier"<<endl;
        cin>>choixInterface;
    }
    if(choixInterface==1)
    {
        return 1;
    }
    else if(choixInterface==2)
    {
        return 2;
    }
    else if(choixInterface==3)
    {
        return 3;
    }
}
int menu::choixSaisie(){
    int saisie;
    cout<<"----------------------------------------"<<endl;
    cout<<"============== SAISIE ================"<<endl;
    cout<<"Comment voulez vous saisir votre graphe ?"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"1 - Saisie manuelle                    "<<endl;
    cout<<"2 - Saisie document.txt                      "<<endl;
    cout<<"----------------------------------------"<<endl;
    cin>>saisie;
    while (saisie>2 || saisie<1)
    {
        cout<<"Erreur : Donnez 1 pour Saisie manuelle et 2 pour Saisie document.txt"<<endl;
        cin>>saisie;
    }
    if(saisie==1)
    {
        return 1;
    }
    else if(saisie==2)
    {
        return 2;
    }
}

void menu::modifierGrapheOrienteNV(grapheOrienteNV g)
{
    int choix;
    cout<<"----------------------------------------"<<endl;
    cout<<"Quel modification appliquer ?"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"1 - Ajouter un sommet                   "<<endl;
    cout<<"2 - Ajouter une arete                   "<<endl;
    cout<<"3 - Supprimer une arete                 "<<endl;
    cout<<"----------------------------------------"<<endl;
    cin>>choix;

    if(choix == 1)
    {
        g.ajouterSommet();
    }
    else if(choix == 2)
    {
        g.ajouterArete();
    }
    else if(choix == 3)
    {
        g.supprimerArete();
    }
}
