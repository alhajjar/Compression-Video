//////////////////////////////////////////////////////////////
//                       Vecteur.hpp                        //
//                 -------------------------                //
//				       diamond_Project                      //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

#ifndef _VECTEUR_HPP_
#define _VECTEUR_HPP_

#include <assert.h>

class Vecteur
{

	int X;
	int Y;

public:

	 Vecteur();
	 Vecteur(int X, int Y);
	~Vecteur();

	 int getX() const;
     int getY() const;
	
	void setX(int i) ;
    void setY(int j) ;	
};

#ifndef Vecteur_MAIN
#include "Vecteur.inl"
#endif
#endif // _Vecteur_HPP_