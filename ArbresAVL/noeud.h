#pragma once

#include "define.h"

class Noeud {

private:
	int n_data;
	struct Noeud* fgauche;
	struct Noeud* fdroite;

public:
	Noeud() {
		n_data = NULL;
		fgauche = NULL;
		fdroite = NULL;
	}

};
