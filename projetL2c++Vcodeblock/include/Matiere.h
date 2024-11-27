#ifndef Matiere_H
#define Matiere_H

using namespace std;

#include <iostream>
#include <vector>





class Matiere {



    // insertion des attribus du la matiere
    public:

        string nom;
        int coefficient;
        vector<float> notes;
        float moyenneMatiere ;

        //constructeur
        Matiere(string nom,  int coefficient);




        // des getters

        string getNom();


        int getCoefficient();


        // Setters

        // Setters
        void setNom(string nom);
        void setCoefficient(int coefficient);




        // M�thode pour calculer la note pond�r�e
        float calculerMoyenne();

        // M�thode pour afficher les informations de la mati�re
        void afficherInfoMatiere();


        void ajouterNote(float newNote);
        void modifierNote(int numNote, float newNote);
        void supprimerNote(int NumNote);




}
;



#endif // MATIERE_H
