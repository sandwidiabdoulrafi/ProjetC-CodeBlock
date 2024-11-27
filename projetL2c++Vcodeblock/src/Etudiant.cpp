#include "Etudiant.h"

#include "Matiere.h"
#include <iomanip>

using namespace std;


//constructeurs

Etudiant::Etudiant(string nom, string prenom, string genre, string dateNaissance, string matricule, string adress, string niveauScolaire, string email, int telephone){
    this->nom = nom;
    this->prenom = prenom;
    this->genre = genre;
    this->dateNaissance = dateNaissance;
    this->matricule = matricule;
    this->adress = adress;
    this->niveauScolaire = niveauScolaire;
    this->email = email;
    this->telephone = telephone;
    this->moyenneGene = 0.0;
}
Etudiant::Etudiant(string nom, string prenom, string genre,string dateNaissance, string matricule, string adress, string niveauScolaire, string email, int telephone, float moyenneGene){
    this->nom = nom;
    this->prenom = prenom;
    this->genre = genre;
    this->dateNaissance = dateNaissance;
    this->matricule = matricule;
    this->adress = adress;
    this->niveauScolaire = niveauScolaire;
    this->email = email;
    this->telephone = telephone;
    this->moyenneGene = moyenneGene;
    this->matricule = matricule;
};


// Méthodes



//methodes
        // Méthodes



    void Etudiant::calculeMoyenneGene() {
        float totalMoyenneGene = 0; // Somme pondérée des moyennes des matières
        int totalCoefficient = 0;  // Somme des coefficients

        for (int i = 0; i < matieres.size(); i++) {
            float totalNote = 0;   // Somme des notes pour la matière
            int nombreNote = 0;    // Nombre total de notes pour la matière

            for (int j = 0; j < matieres[i].notes.size(); j++) {
                totalNote += matieres[i].notes[j];
                nombreNote++;
            }

            // Calcul de la moyenne pour la matière
            if (nombreNote > 0) {
                matieres[i].moyenneMatiere = totalNote / nombreNote;
            } else {
                matieres[i].moyenneMatiere = 0; // Aucun note
            }

            // Ajout au calcul de la moyenne générale pondérée
            totalMoyenneGene += matieres[i].moyenneMatiere * matieres[i].coefficient;
            totalCoefficient += matieres[i].coefficient;
        };

        // Calcul final de la moyenne générale
        if (totalCoefficient > 0) {
            this->moyenneGene = totalMoyenneGene / totalCoefficient;
        } else {
            this->moyenneGene = 0; // Aucun coefficient
        }
    }



    // affichage des moyennes par matiere


void Etudiant::afficheMoyenneGene() {
    calculeMoyenneGene();

    cout << "\n\n-------------------------- CALCULE DE LA MOYENNE DE L'ETUDIANT -----------------------------" << endl;

    // En-tête
    cout << "\tMatiere\t\t\tMoyenne\t\tCoefficient" << endl;
    cout << "\t----------------------------------------------------" << endl;

    // Détails des matières
    for (int i = 0; i < matieres.size(); i++) {
        cout << "\t"
            << std::setw(15) << std::left << matieres[i].nom
            << "\t" << std::setw(10) << std::fixed << std::setprecision(2) << matieres[i].moyenneMatiere
            << "\t" << matieres[i].coefficient << endl;
    }

    // Affichage de la moyenne générale
    cout << "\t----------------------------------------------------" << endl;
    cout << "Moyenne annuelle : " << std::fixed << std::setprecision(2) << this->moyenneGene << endl;
}




// generation du bulletin

void Etudiant::afficheBulletin() {

    calculeMoyenneGene();

    // Titre du bulletin
    cout << "-----------------------------------------" << endl;
    cout << "           Bulletin de l'etudiant         " << endl;
    cout << "-----------------------------------------" << endl;

    // Affiche les détails de l'étudiant (nom, classe, etc.)
    cout << "Nom  : " << this->nom << endl;
    cout << "Prenom  : " << this->prenom << endl;
    cout << "Date de naissance  : " << this->dateNaissance << endl;
    cout << "Genre  : " << this->genre << endl;
    cout << "Numero  : " << this->telephone << endl;
    cout << "Email  : " << this->email << endl;
    cout << "Classe : " << this->niveauScolaire << endl;
    cout << "-----------------------------------------" << endl;

    // En-tête du tableau des matières
    cout << setw(20) << left << "Matiere"
        << setw(20) << left << "Notes"
        << setw(10) << left << "Moyenne"
        << setw(10) << left << "Coef"
        << endl;

    cout << "-----------------------------------------" << endl;

    // Parcourir chaque matière pour afficher les détails
    for (int i = 0; i < matieres.size(); i++) {
        // Concaténer toutes les notes d'une matière dans une chaîne
        string notes = "";
        for (float note : matieres[i].notes) {
            notes += to_string(note) + " ";
        }

        // Afficher les informations de chaque matière
        cout << setw(20) << left << matieres[i].nom
             << setw(20) << left << notes
             << setw(10) << left << fixed << setprecision(2) << matieres[i].moyenneMatiere
             << setw(10) << left << matieres[i].coefficient
             << endl;
    }

    // Ligne de résumé pour la moyenne générale
    cout << "-----------------------------------------" << endl;
    cout << "Moyenne annuelle : " << fixed << setprecision(2) << this->moyenneGene << endl;
    cout << "-----------------------------------------" << endl;
}























    // Méthode pour afficher les informations

    void Etudiant::afficherInfo() {
        cout << "=============================== Informations de l'etudiant =================================================================================\n\n" << endl;
        cout << "Nom : " << this->nom << endl;
        cout << "Prenom : " << this->prenom << endl;
        cout << "Matricule : " << this->matricule << endl;
        cout << "Date de naissance : " << this->dateNaissance << endl;
        cout << "Genre : " << this->genre << endl;
        cout << "Adresse : " << this->adress << endl;
        cout << "Email : " << this->email << endl;
        cout << "Niveau scolaire : " << this->niveauScolaire << endl;
        cout << "Moyenne generale : " << this->moyenneGene << endl;
        cout << "Telephone : " << this->telephone << endl;
        cout << "========================================================================================================================================================\n" << endl;
    }



    // Méthode pour ajouter une matière

    void Etudiant::ajouterMatiere(Matiere matiere) {
        this->matieres.push_back(matiere);
        cout << "-----------------------------------------------------------------------------------------------------------\n\n"<< endl;
        cout << "\t\t La matiere "<< matiere.nom <<" ajouter avec succe.\n"<< endl;
        cout << "-----------------------------------------------------------------------------------------------------------\n\n"<< endl;

    }



     // Méthode pour afficher les informations de l'étudiant
    void Etudiant::affichertMatieresEtudiant() {
        // cout << "Nom: " << this->nom << endl;
        // cout << "Prenom: " << this->prenom << endl;
        // cout << "Matricule: " << this->matricule << endl;
        // cout << "Date de naissance: " << this->dateNaissance << endl;
        // cout << "Genre: " << this->genre << endl;
        // cout << "Adresse: " << this->adress << endl;
        // cout << "Email: " << this->email << endl;
        // cout << "Niveau scolaire: " << this->niveauScolaire << endl;


        cout << "---------------------------------------------------- LISTE DES MATIERES -------------------------------------------------------\n\n"<< endl;

        // Affichage des matières
        cout << "\t=============================================== MatiEres de l'etudiant ===============================================\n" << endl;
        for (int i = 0; i < matieres.size(); ++i) {
            cout << "\tMatiere " << i + 1 << ": " << matieres[i].nom << " (Coefficient: " << matieres[i].coefficient << ")\n" << endl;
        }
        cout << "-----------------------------------------------------------------------------------------------------------\n\n"<< endl;
    }

    void Etudiant::afficherNoteEtudiant() {
        // cout << "Nom: " << nom << endl;
        // cout << "Prénom: " << prenom << endl;
        // cout << "Matricule: " << matricule << endl;
        // cout << "Date de naissance: " << dateNaissance << endl;
        // cout << "Genre: " << genre << endl;
        // cout << "Adresse: " << adress << endl;
        // cout << "Email: " << email << endl;
        // cout << "Niveau scolaire: " << niveauScolaire << endl;

        // Affichage des matières

        cout << "\n----------------------------------------------- Matieres de l'etudiant ---------------------------------------------------\n" << endl;

        cout << "--------------------------------------------------------------------------------------------------\n" << endl;
        if(matieres.empty()){
            cout <<"aucune  matiere encore inscrite.\n "<< endl;

            cout << "\n--------------------------------------------------------------------------------------------------\n" << endl;
        }

        for (int i = 0; i < matieres.size(); ++i) {
            cout << "++++++++++++++++++++++++++++++++++++++++Matiere " << i + 1 << ": " << matieres[i].nom << " (Coefficient: " << matieres[i].coefficient << ")+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n" << endl;

            for(int j = 0; j < matieres[i].notes.size(); j++ ){

                    cout <<"\t"<<j+1<< " Note "<<" est: " <<matieres[i].notes[j]<<"\n"<< endl;

            }

            float moyenne =  matieres[i].calculerMoyenne();

            cout << "La moyenne est : "<< moyenne << endl;
            cout << "\n--------------------------------------------------------------------------------------------------\n" << endl;
        }
    }



// setters

    // setters pour la modification des informations de l'etudiant

    //modification du nom

    void Etudiant::setNom(string nom){


        cout<<"Le nom de l'etudiant "<< this->nom << " est maintenant : "<< nom <<endl;

        this->nom = nom;
        cout<<"Modification de nom avec succè"<< endl;
    }

    //modification du prenom

    void Etudiant::setPrenom(string prenom){


        cout<<"Le prenom de l'etudiant "<< this->nom << " est maintenant : "<< prenom <<endl;

        this->prenom = prenom;
        cout<<"Modification du prenom avec succè"<< endl;
    }

    //modification du matricule

    void Etudiant::setMatricule(string matricule){


        cout<<"La matricule de l'etudiant "<< this->nom << " "<< this->prenom  << " est maintenant : "<< matricule <<endl;

        this->matricule = matricule;
        cout<<"Modification du matricule avec succè"<< endl;
    }

    //modification de la date de nassance

    void Etudiant::setDateNaissance(string dateNaissance){


        cout<<"La date de nassance  de l'etudiant "<< this->nom << " "<< this->prenom << " est maintenant : "<< dateNaissance <<endl;

        this->dateNaissance = dateNaissance;
        cout<<"Modification de la date de nassance avec succè"<< endl;
    }

    //modification du genre

    void Etudiant::setGenre(string genre){


        cout <<"Le genre  de l'etudiant "<< this->nom << " "<< this->prenom << " est maintenant : "<< genre <<endl;

        this->genre = genre;
        cout<<"Modification du genre avec succè"<< endl;
    };

    //modification du adresse

    void Etudiant::setAdresse(string adress){


        cout<<"L'adresse de l'etudiant "<< this->nom << " "<< this->prenom << " est maintenant : "<< adress <<endl;

        this->adress = adress;
        cout<<"Modification de l'adresse avec succè"<< endl;
    };


    //modification du email



    void Etudiant::setEmail(string email){


            cout << "L'adresse email de l'etudiant " << this->nom << " " << this->prenom << " est maintenant : " << email << endl;
            this->email = email;
            cout << "Modification de l'email avec succès" << endl;

    };

    //modification du nuveau scolaire

    void Etudiant::setNiveauScolaire(string niveauScolaire){


        cout<<"Le niveau scolaire  de l'etudiant "<< this->nom << " "<< this->prenom << " est maintenant : "<< niveauScolaire <<endl;

        this->niveauScolaire = niveauScolaire;
        cout<<"Modification du niveau scolaire avec succè"<< endl;
    };


    //modification da la moyenne annuelle

    void Etudiant::setMoyenneAnnuelle(float moyenneGene){


        cout<<"La moyenne generale de l'etudiant "<< this->nom << " "<< this->prenom << " a ete modifier a : "<< moyenneGene <<endl;

        this->moyenneGene = moyenneGene;
        cout<<"Modification de la moyenne generale avec succè"<< endl;
    }

    //modification da la moyenne annuelle

    void Etudiant::setTelephone(int telephone){


        if (telephone <= 0) {
            cout << "Numero de telephone invalide !" << endl;

        } else if (to_string(telephone).length() != 8) {
            cout << "Numero de telephone doit etre compose de 8 chiffres !" << endl;

        } else {
            cout<<"Le numero de telephone de l'etudiant "<< this->nom << " "<< this->prenom << " est maintenant : "<< telephone <<endl;

            this->telephone = telephone;

            cout<<"Modification du numero de telephone avec succè"<< endl;
        }

    };










void Etudiant::modifierNotes(string matiere ,int numNote , float newNote){
    bool trouver = false;

    for(int i=0; i< matieres.size(); i++){

        if(matieres[i].nom == matiere){
            matieres[i].modifierNote(numNote , newNote);
            cout << "\n--------------------------------------------------------------------------------------------------\n" << endl;
            trouver= true;
        }
    }
    if(!trouver){

        cout << "la note non trouver ."<< endl ;
    }



}



void Etudiant::supprimerNote(string matiere, int numNote ){
    bool trouver = false;

    for(int i=0; i< matieres.size(); i++){

        if(matieres[i].nom == matiere){
            matieres[i].supprimerNote(numNote);
            cout << "la note a ete supprimer avec succe ."<< endl;
            trouver= true;
        }
    }
    if(!trouver){
        cout << "la note non trouver ."<< endl;
    }
};








    void Etudiant::ajouteNote(string matiere,float newNote ){

        for(int i=0; i< matieres.size(); i++){

            if(matieres[i].nom == matiere){

                matieres[i].ajouterNote(newNote);
            }
        }
    };














void Etudiant::supprimerMatiere(string matiere) {
    for (size_t i = 0; i < matieres.size(); ++i) {
        if (matieres[i].nom == matiere) {
            cout << "La matiere " << matieres[i].nom << " a ete supprimee avec succes." << endl;
            matieres.erase(matieres.begin() + i);
            return;
        }
    }
    cout << "La matiere " << matiere << " n'existe pas dans la liste." << endl;
}


















































//   void Etudiant::modifierNotes(string matiere, int numNote, float newNote) {

//         for (int i = 0; i < matieres.size(); i++) {

//             if (matieres[i].nom == matiere) {

//                 if (numNote >= 0 && numNote < matieres[i].notes.size()) {

//                     matieres[i].notes[numNote] = newNote;

//                     cout << "La note a été modifiée avec succès." << endl;

//                 } else {

//                     cout << "Erreur : note no trouvers." << endl;

//                 }
//                 return;
//             }
//         }

//         cout << "Erreur : Matière non trouvée." << endl;
//     }
