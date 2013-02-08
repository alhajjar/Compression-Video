////////////////////////////////////////////////////////////////////
//						  Vecteur.inl                             //
//                 -------------------------                      //
//                      diamond_Project                            //
//                                                                //
//                                                                //
////////////////////////////////////////////////////////////////////

#define Vecteur_MAIN

#include <cstring>

using namespace std;


Vecteur::Vecteur()
{
	X = 0;
	Y = 0;

}
Vecteur::Vecteur(int dX, int dY)
{
	X = dX;
	Y = dY;
}

Vecteur::~Vecteur()
{
}

 int Vecteur::getX() const
{
	return X;
}


int Vecteur::getY() const
{
	return Y;
}


void Vecteur::setX(int i) 
{
	 X=i;
}


void Vecteur::setY(int j) 
{
	 Y=j;
}