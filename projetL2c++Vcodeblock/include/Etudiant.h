#ifndef ETUDIANT_H
#define ETUDIANT_H


#include "Matiere.h"


#include <iostream>

using namespace std;
#include <vector>

class Etudiant{



        public :

                // creation des attribus de l'etudiant
                string nom ;
                string prenom ;
                string matricule ;
                string dateNaissance ;
                string genre ;
                string adress;
                string email;
                string niveauScolaire;
                vector<Matiere> matieres;


                float moyenneGene ;
                int telephone;

        // la section des constructeurs pour la creation


                Etudiant(string nom, string prenom, string genre,string dateNaissance, string matricule, string adress, string niveauScolaire, string email, int telephone );
                Etudiant(string nom, string prenom, string genre,string dateNaissance, string matricule, string adress, string niveauScolaire, string email, int telephone, float moyenneGene);


        // la section des methodes


                void calculeMoyenneGene();
                void ajouterMatiere(Matiere matiere);
                void afficherInfo();
                void modifierNotes(string matiere, int numNote , float newNote);
                void supprimerNote(string matiere, int numNote );
                void supprimerMatiere(string matiere);
                void afficherNoteEtudiant();
                void affichertMatieresEtudiant();
                void afficheMoyenneGene();
                void afficheBulletin();
                void ajouteNote(string matiere,float newNote );








        // setters pour la modification des informations de l'etudiant

                //modification du nom

                void setNom(string nom);
                //modification du prenom

                void setPrenom(string prenom);

                //modification du matricule

                void setMatricule(string matricule);

                //modification de la date de nassance

                void setDateNaissance(string dateNaissance);

                //modification du genre

                void setGenre(string genre);

                //modification du adresse

                void setAdresse(string adress);

                //modification du email

                void setEmail(string email);

                //modification du nuveau scolaire

                void setNiveauScolaire(string niveauScolaire);

                //modification da la moyenne annuelle

                void setMoyenneAnnuelle(float moyenneGene);

                //modification da la moyenne annuelle

                void setTelephone(int telephone);





}
;

#endif // ETUDIANT_H
