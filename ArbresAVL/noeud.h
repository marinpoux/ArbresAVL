#pragma once

#include "define.h"

using namespace std;

class Noeud {

private:
	int n_data;
	Noeud* fgauche;
	Noeud* fdroite;

public:
	//CONSTRUCTEURS
	Noeud() {
		InitNoeud(NULL);
	}

	Noeud(int n_data) {
		InitNoeud(n_data);
	}

	////copies
	Noeud(Noeud* n) {
		InitNoeud(n->n_data, n->fgauche, n->fdroite);
		//InitNoeud(n->GetData(), n->GetFgauche(), n->GetFdroite());
	}


	//ACCESSEURS
	int GetData() {
		return n_data;
	}

	Noeud* GetFgauche() {
		return fgauche;
	}

	Noeud* GetFdroite() {
		return fdroite;
	}

	//MUTATEURS
	void SetData(int n_data) {
		this->n_data = n_data;
	}

	void SetFgauche(Noeud* fgauche) {
		this->fgauche = fgauche;
	}

	void SetFdroite(Noeud* fdroite) {
		this->fdroite = fdroite;
	}

	//FONCTIONS
	////initialisation
	Noeud* InitNoeud(int n_data, Noeud* fg = nullptr, Noeud* fd = nullptr) {
		Noeud* pNoeud = nullptr;
		pNoeud = (Noeud*)malloc(sizeof(Noeud));

		if (pNoeud == nullptr) {
			return nullptr;
		}
		else {
			pNoeud->n_data = n_data;

			pNoeud->fgauche = fg;
			pNoeud->fdroite = fd;

			return pNoeud;
		}
	}

	////operateurs
	Noeud operator=(const Noeud& noeud) {
		this->n_data = noeud.n_data;

		this->fgauche = noeud.fgauche;
		this->fdroite = noeud.fdroite;

		return *this;
	}

	Noeud* operator=(const Noeud noeud) {
		this->n_data = noeud.n_data;

		this->fgauche = noeud.fgauche;
		this->fdroite = noeud.fdroite;

		return this;
	}

	////parcourir
	void ParcoursPrefixe() {
		if (this != NULL) {
			Traitement();
			fgauche->ParcoursPrefixe();
			fdroite->ParcoursPrefixe();
		}
	}
	void ParcoursPostfixe() {
		if (this != NULL) {
			fgauche->ParcoursPostfixe();
			fdroite->ParcoursPostfixe();
			Traitement();
		}
	}
	void ParcoursInfixe() {
		if (this != NULL) {
			fgauche->ParcoursInfixe();
			Traitement();
			fdroite->ParcoursInfixe();
		}
	}

	void Traitement() {
		this->AfficheData();
	}

	void AfficheData() {
		cout << this->GetData() << "; " << endl;
	}

	////actions
	void Liberer(Noeud** pNoeud) {
		Noeud* noeud = *pNoeud;

		if (noeud != nullptr) {
			Liberer(&noeud->fgauche);
			Liberer(&noeud->fdroite);
			free(noeud);
		}

		*pNoeud = nullptr;
	}

	////autres
	Noeud* PlusGrand() {
		Noeud* courant = this;

		if (this->fdroite == nullptr)
			return courant;

		return courant->fdroite->PlusGrand();
	}
};
