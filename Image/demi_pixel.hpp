//////////////////////////////////////////////////////////////
//                       demi_pixel.hpp                     //
//                 -------------------------                //
//						 Diamond_Project                    //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

#ifndef _Demi_pixel_HPP_
#define _Demi_pixel_HPP_

#include <assert.h>

#include "Image.hpp"
#include "Vecteur.hpp"
#include "extract.hpp"
#include "Vecteur.hpp"

using namespace std;

template <class T>
class Demi_pixel
{
	
public:

	static Image<T> demi_pixel(Image<T> &img);
	
	static Image<T> Reconstruction_demi_pixel(Image<T> &ima, Image<Vecteur> &Matrice);

	}; 




#ifndef Demi_pixel_MAIN
#include "demi_pixel.inl"
#endif

#endif // _Outil_HPP_
