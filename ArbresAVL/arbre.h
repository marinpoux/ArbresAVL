#pragma once

#include "define.h"
#include "noeud.h"

using namespace std;

class ArbreBinaire {

private:
	Noeud* racine;

public:
	//CONSTRUCTEUR
	ArbreBinaire() {
		InitArbre(nullptr);		
	}

	//ACCESSEUR
	Noeud* GetRacine() {
		return racine;
	}

	Noeud** GetPRacine() {
		return &racine;
	}

	//FONCTIONS
	////initialisation
	ArbreBinaire* InitArbre(Noeud* racine) {
		ArbreBinaire* pArbre = nullptr;
		pArbre = (ArbreBinaire*)malloc(sizeof(ArbreBinaire));

		if (pArbre == nullptr) {
			return nullptr;
		}
		else {
			pArbre->racine = racine;

			return pArbre;
		}
	}

	////autres
	void InsertArbreVide(int n_data) {
		racine->InitNoeud(n_data);
	}

	int AddNoeud(int n_data) {
		Noeud* elem = new Noeud(n_data);
		Noeud* courant = new Noeud(racine);
		Noeud* precedent = NULL;

		//on avance jusqu'à trouver une place
		while (courant) {
			precedent = courant;
			if (elem->GetData() < courant->GetData())
				courant = courant->GetFgauche();
			else
				courant = courant->GetFdroite();
		}

		//place libre trouvée
		//precedent pointe vers le parent du noeud à remplacer
		if (elem->GetData() < precedent->GetData())
			precedent->SetFgauche(elem);
		else
			precedent->SetFdroite(elem);

		return 1;
	}

	Noeud* SupprNoeud(Noeud* courant, int n_data) {
		//si arbre vide
		if (courant == nullptr)
			return courant;

		//si val à supprimer < val --> fgauche
		else if (n_data < courant->GetData())
			courant->SetFgauche(SupprNoeud(courant->GetFgauche(), n_data));

		//si val à supprimer > val --> fdroite
		else if (n_data > courant->GetData())
			courant->SetFdroite(SupprNoeud(courant->GetFdroite(), n_data));

		//emplacement trouvé
		else {
			//si fgauche nullptr, return fdroite
			if (courant->GetFgauche() == nullptr)
				return courant->GetFdroite();

			//si fdroite nullptr, return fdroite
			else if (courant->GetFdroite() == nullptr)
				return courant->GetFgauche();

			//si fgauche et fdroite nullptr, recherche plus grand fgauche
			else {
				Noeud* successeur = courant->GetFgauche()->PlusGrand();

				if (courant != nullptr) {
					courant->SetData(successeur->GetData());	//remplace valeur à suppr par successeur
					SupprNoeud(courant->GetFgauche(), successeur->GetData());	//suppr par recursivité doublon successeur
				}
			}
		}

		return courant;
	}

	void SupprNoeudArbre(int n_data) {
		assert(this);

		if (racine)
			SupprNoeud(racine, n_data);
	}
};
