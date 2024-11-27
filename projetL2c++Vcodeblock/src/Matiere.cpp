#include "Matiere.h"

#include <iostream>
using namespace std;

// Constructeur
Matiere::Matiere(string nom, int coefficient){
    this->nom = nom;
    this->coefficient = coefficient;
    this->moyenneMatiere = 0.0;
};

// Getters
string Matiere::getNom(){
    return nom;
};

int Matiere::getCoefficient(){
    return coefficient;
};



// Setters
void Matiere::setNom(string nom){
    this->nom = nom;
};

void Matiere::setCoefficient(int coefficient){
    this->coefficient = coefficient;
};





// M�thode pour afficher les informations de la mati�re
void Matiere::afficherInfoMatiere() {
    cout << "Mati�re : " << this->nom << endl;
    cout << "Coefficient : " << this->coefficient << endl;

    for (int  i = 0; i < notes.size(); ++i) {

        cout << "Note " << (i + 1) << ": " << this->notes[i] << endl;
    }

    float moyenne = calculerMoyenne();

    cout<<"La moyenne est : "<< moyenne<< endl ;
};





// la methode pour calculer la moyenne

float Matiere::calculerMoyenne(){

    float noteTotal=0.0;
    int nombreNote = 0;

    for(int i=0; i < notes.size(); i++){

        noteTotal = noteTotal + notes[i] ;
        nombreNote += 1;
    }

    if(noteTotal == 0){

        this->moyenneMatiere = 0.0;

        // cout << "Aucune note disponible pour la mati�re " << this->nom << "." << endl;

        return this->moyenneMatiere;

    }else{


        this->moyenneMatiere = noteTotal / nombreNote;


        return this->moyenneMatiere;


    }


};


void Matiere::ajouterNote(float newNote){

    cout << "\n----------------------------------------------- AJOUTER UNE NOUVELLE NOTE  ------------------------------------------------------------\n"<< endl;
    notes.push_back(newNote);

    cout << "Note ajouter avec succes . \n"<< endl;

}

//modifier une note
// void Matiere::modifierNote(int numNote, float newNote){

//     notes[numNote-1] = newNote;

//     cout<< "la note a ete modifier avec succ� ."<< endl;
// };

void Matiere::modifierNote(int numNote, float newNote) {
    if (numNote >= 1 && numNote <= notes.size()) { // V�rifie que numNote est valide
        notes[numNote - 1] = newNote; // Modification de la note
        cout << "Note modifi�e avec succ�s." << endl;
    } else {
        cout << "Erreur : num�ro de note invalide !" << endl;
    }
}





//suppression d'une note

void Matiere::supprimerNote(int numNote) {
    if (numNote >= 0 && numNote < notes.size()) {

        notes.erase(notes.begin() + numNote);

    } else {

        cout << "Note  inexistant. "<< endl;
    }
};


