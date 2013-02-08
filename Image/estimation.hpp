//////////////////////////////////////////////////////////////
//                       estimation.hpp                     //
//                 -------------------------                //
//						 Diamond_Project                    //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

#ifndef _estimation_HPP_
#define _estimation_HPP_

#include <assert.h>
#include "Image.hpp"
#include "ImageYUV.hpp"
#include "Vecteur.hpp"
#include "extract.hpp"
#include "calculsad.hpp"
#include "Vecteur.hpp"


using namespace std;

template <class T>
class estimation
{
public:

	  static void estimationDiamant(Image<T>& src, Image<T>& imagette,Vecteur& vecteur,  int abscisse, int Ordonnee);
	  static void estimationVecteur(Image<T>& src, Image<T>& imagette,Vecteur& vecteur, int abscisse, int Ordonnee);
	  static Image<Vecteur> estimationMatrice(Image<T> &ima, Image<T> &image2,  Vecteur &vect);
}; 


#ifndef estimation_MAIN
#include "estimation.inl"
#endif

#endif // _estimation_HPP_


