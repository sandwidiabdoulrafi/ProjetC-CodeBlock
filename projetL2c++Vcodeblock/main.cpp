#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>


#include "Etudiant.h"
#include "Matiere.h"

using namespace std;


void chargerDonnees(vector<Etudiant>& etudiants, string fichier) {
    ifstream inFile(fichier);

    if (!inFile) {
        cerr << "Erreur d'ouverture du fichier pour le chargement.\n";
        return;
    }

    etudiants.clear(); // Vide la liste actuelle avant de charger les nouvelles données

    string ligne;
    while (getline(inFile, ligne)) {
        stringstream ss(ligne);

        // Variables temporaires pour l'étudiant
        string nom, prenom, dateNaissance, niveauScolaire, matricule, adress, email, genre;
        int telephone;
        float moyenneGene;

        // Lecture des données de l'étudiant
        getline(ss, nom, ';');
        getline(ss, prenom, ';');
        getline(ss, dateNaissance, ';');
        getline(ss, niveauScolaire, ';');
        getline(ss, matricule, ';');
        getline(ss, adress, ';');
        getline(ss, email, ';');
        ss >> telephone;
        ss.ignore();  // Ignorer le caractère ';' après le téléphone
        getline(ss, genre, ';');
        ss >> moyenneGene;
        ss.ignore();  // Ignorer le caractère ';' après la moyenne générale

        // Création de l'étudiant avec les variables récupérées
        Etudiant etudiant(nom, prenom, genre, dateNaissance, matricule, adress, niveauScolaire, email, telephone, moyenneGene);

        // Lecture des matières et notes
        while (getline(inFile, ligne) && !ligne.empty()) {
            stringstream ssMatiere(ligne);

            // Variables temporaires pour la matière
            string nomMatiere;
            int coefficient;
            vector<float> notes;

            // Lecture du nom de la matière et du coefficient
            getline(ssMatiere, nomMatiere, ':');
            ssMatiere >> coefficient;
            ssMatiere.ignore(); // Ignorer le caractère ':'

            if (!nomMatiere.empty() && coefficient > 0) {
                // Lecture des notes
                string noteStr;
                while (getline(ssMatiere, noteStr, ',')) {
                    if (!noteStr.empty()) {
                        notes.push_back(stof(noteStr)); // Convertir et ajouter la note
                    }
                }

                // Lire la ligne contenant la moyenne de la matière
                if (getline(inFile, ligne)) { // Lire la ligne suivante
                    size_t pos = ligne.find("MoyenneMatiere :");
                    if (pos != string::npos) {
                        float moyenneMatiere = stof(ligne.substr(pos + 16)); // Extraire la moyenne

                        // Création de la matière et ajout des notes
                        Matiere matiere(nomMatiere, coefficient);
                        matiere.moyenneMatiere = moyenneMatiere; // Définir la moyenne
                        for (float note : notes) {
                            matiere.ajouterNote(note); // Ajouter chaque note à la matière
                        }

                        // Ajout de la matière à l'étudiant
                        etudiant.ajouterMatiere(matiere);
                    }
                }
            }
        }

        // Ajout de l'étudiant à la liste des étudiants
        etudiants.push_back(etudiant);
    }

    inFile.close();
    cout << "\t----- Donnees chargees avec succes. ----\n";
}



// sauvegarder les données sur  un fichier

    void sauvegarderDonnees(vector<Etudiant> classe , string fichier) {
        ofstream outFile(fichier);
        if (!outFile) {
            cerr << "Erreur d'ouverture du fichier pour la sauvegarde.\n";
            return;
        }



        for (Etudiant& etudiant : classe) {
            outFile << etudiant.nom << ";" << etudiant.prenom << ";" << etudiant.dateNaissance << ";" << etudiant.niveauScolaire << ";" << etudiant.matricule << ";"
                    << etudiant.adress << ";" << etudiant.email << ";" << etudiant.telephone << ";"
                    << etudiant.genre << ";" << etudiant.niveauScolaire <<  ";"<< etudiant.moyenneGene <<"\n";

            for (Matiere& matiere : etudiant.matieres){

                outFile << matiere.nom << ":" << matiere.coefficient<< ":";
                for (float note : matiere.notes){
                    outFile << note << ",";
                }
                outFile << "\n";
                outFile << "MoyenneMatiere :";
                outFile << matiere.moyenneMatiere << "\n ";


            }


            outFile << "\n";
        }

        outFile.close();
        cout << "Donnees sauvegardees avec succes.\n";
}



// verification de l,existance del'etudiant avant de de l'incrire
bool etudiantExiste(vector<Etudiant> classe, Etudiant etudiant) {
    for (Etudiant& etud : classe) {
        if (etud.nom == etudiant.nom && etud.prenom == etudiant.prenom && etud.dateNaissance == etudiant.dateNaissance && etud.niveauScolaire == etudiant.niveauScolaire) {
            return true;
        }
    }
    return false;
}



























// generation du matricule

string genererMatricule() {

    string matricule;

    // Générer une lettre aléatoire (par exemple A-Z)

    char lettre = 'A' + rand() % 26;

    matricule += lettre;

    // Générer un nombre aléatoire à 4 chiffres (par exemple 1000-9999)
    int numero = rand() % 9000 + 1000;
    matricule += to_string(numero);

    return matricule;
}











//ajouter un etudiant

void AjouterEtudiant(vector<Etudiant>& classe){




        // declaration des variable pour enregistrer un etudiant
        string nom ;
        //vector <string> prenom ;
        string prenom ;
        string matricule = genererMatricule();
        string dateNaissance ;
        string genre ;
        string adress;
        string email;
        string niveauScolaire;

        int telephone;



        cout <<"=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-= INSCRIPTION D'UN ETUDIANT -=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=\n"<< endl;
        cout <<"Nom de l'Etudiant : "<< endl;
        cin >> nom;
        cout <<"Prenom de l'Etudiant : "<< endl;
        cin>> prenom;
        cout <<"Date de naissance de l'Etudiant : "<< endl;
        cin >> dateNaissance;
        cout <<"Genre de l'Etudiant : "<< endl;
        cin >> genre;
        cout <<"Lieux de residance  de l'Etudiant : "<< endl;
        cin >> adress;
        cout <<"Email de l'Etudiant : "<< endl;
        cin >> email;
        cout <<"Niveau scolaire  de l'Etudiant : "<< endl;
        cin >> niveauScolaire;
        cout <<"Le contact de l\'Etudiant : "<< endl;
        cin >> telephone;


        Etudiant newEtudiant(nom, prenom, genre, dateNaissance, matricule, adress, niveauScolaire, email, telephone );

        bool trouver = etudiantExiste(classe, newEtudiant );

        if(trouver){

            cout << "L'etudiant "<<nom << " "<<prenom <<" est deja inscrit \n\n" << endl;

        }else{

            classe.push_back(newEtudiant);

        cout << "Etudiant ajoute avec succes!\n" << endl;
        cout << "La matricule du nouveau etudiant "<<nom << " "<<prenom <<" est :  ( " << matricule <<" ).\n" << endl;

        }





    }





//calculer la moyenne de la classe


void CalculeMoyenneClass(vector<Etudiant>& classe) {
    cout << "\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= CALCULE DE LA MOYENNE DES ETUDIANTS =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n" << endl;

    if (classe.empty()) {
        cout << "La classe est vide. Aucun etudiant n'existe.\n" << endl;
    } else {
        // En-tête
        cout << setw(12) << left << "Matricule"
             << setw(15) << left << "Nom"
             << setw(15) << left << "Prenom"
             << setw(15) << left << "Moyenne Generale" << endl;

        cout << "---------------------------------------------------------------------------------------------------\n" << endl;

        // Parcourir les étudiants de la classe
        for (int i = 0; i < classe.size(); i++) {
            // Calculer la moyenne générale de chaque étudiant
            classe[i].calculeMoyenneGene();

            // Afficher les informations de l'étudiant
            cout << setw(12) << left << classe[i].matricule
                 << setw(15) << left << classe[i].nom
                 << setw(15) << left << classe[i].prenom
                 << setw(15) << left << fixed << setprecision(2) << classe[i].moyenneGene << endl;

            cout << "---------------------------------------------------------------------------------------------------\n" << endl;
        }
    }
}






//lister les Etudiants de la classe


    void AffichageClasse(vector<Etudiant>& classe){
        cout <<"\n\n=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-= AFFICHAGE DE LA CLASSE  -=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=\n"<< endl;

        if(classe.empty()){

            cout << "La classe est vide. Aucun etudiant a afficher. \n" << endl;
        }
        else{

            for(int i=0; i<classe.size() ; i++ ){
                cout <<"Matricule : "<< classe[i].matricule <<" \t\tNom : "<<classe[i].nom  <<" \t\t Prenom : "<< classe[i].prenom << endl;

                cout<<"----------------------------------------------------------------------------------------------------------\n"<< endl;
            }
        }
    }

















//affichage des notes de la classe
    void AfficherlesNotes(vector<Etudiant> classe){
        cout <<"\n\n=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-= AFFICHAGE DES NOTES DES NOTES ETUDIANT -=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=\n"<< endl;



        if(classe.empty()){

            cout << "La classe est vide. Aucun etudiant à afficher. \n" << endl;
        }
        else{
            cout <<"Nom \t\t Prenom "<< endl;
            for(int i=0; i<classe.size() ; i++ ){
                cout <<"Nom : "<<classe[i].nom  <<" \t\t Prenom : "<< classe[i].prenom << endl;

                if(classe[i].matieres.empty()){

                    cout << "  Aucun cours enregistre pour cet etudiant." << endl;

                }else{

                    for (int i = 0; i < classe.size(); i++) {

                        for (int j = 0; j < classe[i].matieres.size(); j++) {

                            cout << "Matière : " << classe[i].matieres[j].nom << endl;

                            // Vérifier si le vecteur notes est vide
                            if (classe[i].matieres[j].notes.empty()) {

                                cout << "Aucune note." << endl;
                            } else {
                                // Parcourir les notes pour la matière j
                                for (int k = 0; k < classe[i].matieres[j].notes.size(); k++) {
                                    cout << k + 1 << ". Note : " << classe[i].matieres[j].notes[k] << endl;
                                }
                            }
                        }
                    }


                }
                }


                cout<<"----------------------------------------------------------------------------------------------------------\n"<< endl;
            }
    }


// permetre les actions sur les  etudiant etudiant

void ActionsSurEtudiant(vector<Etudiant>& classe) {
    cout << "\n\n=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-= GESTION D'ETUDIANT -=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=\n" << endl;

    if (classe.empty()) {
        cout << "La classe est vide. Aucun etudiant a gerer.\n" << endl;
        return;
    }

    // Entrer la matricule
    string matriculeRecherche;
    cout << "Entrez la matricule de l'etudiant : ";
    cin >> matriculeRecherche;

    // Rechercher l'étudiant
    for (Etudiant& etudiant : classe) {
        if (etudiant.matricule == matriculeRecherche){
            cout << "\nEtudiant trouve : " << etudiant.nom << " " << etudiant.prenom << " (Matricule : " << etudiant.matricule << ")\n";







            float newNote;
            int numNote;

            int choix = 0;



            while (choix != 11) { // Continuer tant que l'utilisateur ne choisit pas "7"
                // Affichage du menu
                cout << "\n__________________________________Actions disponibles pour la gestion________________________________________________________________\n\n";
                cout << "\t1. Afficher le bulletin de l'etudiant\n";
                cout << "\t2. Calculer la moyenne generale\n";
                cout << "\t3. Ajouter une matiere\n";
                cout << "\t4. Afficher les informations de l'etudiant\n";
                cout << "\t5. Modifier une note  \n";
                cout << "\t6. Supprimer une note \n";
                cout << "\t7. Supprimer une matiere \n";
                cout << "\t8. Afficher tout les notes \n";
                cout << "\t9. Afficchage des matieres \n";
                cout << "\t10. Ajouter une note \n";
                cout << "\t11. Retourner au menu principal\n";
                cout << "\tVotre choix : ";
                cin >> choix;

                if (choix == 1) {
                    etudiant.afficheBulletin();
                    cout<<"----------------------------------------------------------------------------------------------------------\n"<< endl;

                }
                else if (choix == 2) {

                    etudiant.afficheMoyenneGene();
                    cout<<"----------------------------------------------------------------------------------------------------------\n"<< endl;

                }
                else if (choix == 3) {
                    cout<<"\n------------------------------------------------ Ajouter un matiere ----------------------------------------------------------\n"<< endl;
                    int coef = 1 ;
                    string nomMatier;
                    cout << "Veuillez entrer le nom de la Matiere : " << endl;
                    cin >> nomMatier;

                    cout << "Veuillez entrer le coefficient de la Matiere : " << endl;
                    cin >> coef;

                    Matiere newMatiere(nomMatier, coef);
                    etudiant.ajouterMatiere(newMatiere);
                    cout<<"\n----------------------------------------------------------------------------------------------------------\n"<< endl;

                }
                else if (choix == 4) {
                    etudiant.afficherInfo();
                    cout<<"\n----------------------------------------------------------------------------------------------------------\n"<< endl;

                }
                else if (choix == 5) {
                    string matiere;
                    cout << "Entrer le nom de la matiere : " << endl;
                    cin >> matiere;
                    cout << "Entrer le numero  de la note : " << endl;
                    cin >> numNote;
                    cout << "Entrer la nouvelle note elle doit etre  comprise entre 0 et 20 : ";
                    cin >> newNote;
                    etudiant.modifierNotes(matiere, numNote, newNote);



                }
                else if (choix == 6) {
                    string matiere;
                    cout << "Entrer le nom de la matiere : " << endl;
                    cin >> matiere;
                    cout << "Entrer le numero de la ligne de la note : " << endl;
                    cin >> numNote;
                    etudiant.supprimerNote(matiere, numNote);

                    cout<<"\n----------------------------------------------------------------------------------------------------------\n"<< endl;

                }
                else if (choix==7){
                    string matiere;

                    cout << "Entrer le nom de la matiere : " << endl;
                    cin >> matiere;

                    etudiant.supprimerMatiere(matiere);
                    cout<<"----------------------------------------------------------------------------------------------------------\n"<< endl;

                }
                else if (choix==8){

                    etudiant.afficherNoteEtudiant();

                    cout<<"----------------------------------------------------------------------------------------------------------\n"<< endl;

                }
                else if (choix==9){
                    etudiant.affichertMatieresEtudiant();
                    cout<<"----------------------------------------------------------------------------------------------------------\n"<< endl;

                }
                else if (choix == 10) {

                    string matiere;

                    float note ;

                    cout << "Entrer le nom de la matiere : " << endl;

                    cin >> matiere;

                    cout << "Entrer  la note : " << endl;

                    cin >> note;

                    etudiant.ajouteNote(matiere, note);


                }
                else if (choix == 11) {

                    cout << "Retour au menu principal.\n";
                    cout<<"----------------------------------------------------------------------------------------------------------\n"<< endl;

                }
                else {
                    cout << "Choix invalide. Veuillez reessayer.\n";
                    cout<<"----------------------------------------------------------------------------------------------------------\n"<< endl;

                }
            }

            return; // Fin de la fonctionn
        }else{
                // Si aucun étudiant n'est trouvé
            cout << "Aucun etudiant trouve avec la matricule : " << matriculeRecherche << endl;
        }


    }
}




    void interfacePrincipal(vector<Etudiant> classe){

        cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n" << endl;
        cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- PROJET GENIE LOGICIEL C++: 20223-2024 _-_-_-_-_-_-_-_-_-_-_- PROJET : 4 _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n" << endl;
        cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n" << endl;
        cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- SYSTEME DE GESTION DES NOTES POUR UNE ECOLE  -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n" << endl;



        int choix;

        do {
            cout << "\n-------------------------_____________Menu Principal de l'application_____________________--------------------- \n" << endl;
            cout << "1. Ajouter un etudiant\n" << endl;
            cout << "2. Afficher la classe\n" << endl;
            cout << "3. Gerer un  etudiant\n" << endl;
            cout << "4. Calculer la moyenne de tout les etudiants  \n" << endl;
            cout << "5. Sauvegarder les donnees \n" << endl;
            cout << "6. charger les donnees \n" << endl;
            cout << "7. Quitter\n\t" << endl;

            cout << "Votre choix : " << endl;
            cin >> choix;

            switch (choix) {
                case 1:
                    AjouterEtudiant(classe);
                    break;
                case 2:
                    AffichageClasse(classe);
                    break;
                case 3:
                    ActionsSurEtudiant(classe);
                    break;
                case 4:
                    CalculeMoyenneClass(classe);
                    break;
                case 5:{
                    string nomFichier;

                    cout << "Veuillez entrer le nom du fichier pour le chargement de donnes ( NB: il doit etre dans meme repertoire que le fichier main.cpp ) :  \n\t" << endl;

                    cin>> nomFichier;


                    sauvegarderDonnees(classe, nomFichier);

                    cout << "---------------------------------------------------------------------------------------------------- \n" << endl;



                    break;
                }
                case 6:{
                    string nomFichier;

                    cout << "Veuillez entrer le nom du fichier pour le chargement de donnes :  \n\t" << endl;

                    cin>> nomFichier;


                    chargerDonnees(classe, nomFichier);

                    cout << "---------------------------------------------------------------------------------------------------- \n" << endl;

                    break;
                }
                case 7:

                    cout << "Vous avez quitter l'application au revoir !\n" << endl;
                    choix = 7;
                    break;
                default:
                    cout << "Choix invalide. Veuillez reessayer.\n" << endl;
            }
        } while (choix != 7);



    }






int main()
{
    vector <Etudiant> classe ;



    interfacePrincipal(classe);





    return 0;
}















// 1) cd projet_cplusplus

// 2) g++ -o projet_executable   main.cpp source/src/class/Etudiant.cpp source/src/class/Matiere.cpp -I source/src/include
// 3).\projet_executable
