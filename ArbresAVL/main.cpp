#include "define.h"
#include "arbre.h"
#include "noeud.h"

using namespace std;

int main() {

	//Noeud* noeud;
	//Noeud* noeud_2 = new Noeud(2);

	ArbreBinaire* Arbre = new ArbreBinaire;

	Arbre->InsertArbreVide(10);
	Arbre->AddNoeud(20);
	Arbre->AddNoeud(8);
	Arbre->AddNoeud(5);
	Arbre->AddNoeud(6);
	Arbre->AddNoeud(4);
	Arbre->AddNoeud(3);

	Arbre->GetRacine()->ParcoursInfixe();

	Arbre->SupprNoeudArbre(6);

	if (Arbre != nullptr)
		Arbre->GetRacine()->Liberer(Arbre->GetPRacine());
	
	free(Arbre);

	return 0;
}