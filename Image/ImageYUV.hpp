//////////////////////////////////////////////////////////////
//                       Image.hpp                          //
//                 -------------------------                //
//						 Diamond_Project                    //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

#ifndef _IMAGEYUV_HPP_
#define _IMAGEYUV_HPP_

#include <assert.h>

//! La classe Image est une classe container qui permet la gestion d'images à une seule composante.
template <class T>
class ImageYUV
{
public:
	Image<T> Y;
	Image<T> U;
	Image<T> V;
	
	// Constructeur par defaut
	ImageYUV ();
	
	// constructeur
	ImageYUV (const unsigned int nbRow, const unsigned int nbCol);

	// constructeur par recopie
	ImageYUV (const ImageYUV &ima);
	
	// destructeur 
	virtual ~ImageYUV ();
	

	//Opérateur =
	ImageYUV&   operator = (const ImageYUV &ima);
	
	//methode de retaillage
	void     Resize (const unsigned int nbRow, const unsigned int nbCol);
	
}; 

// end class Image


#ifndef IMAGEYUV_MAIN
#include "ImageYUV.inl"
#endif

#endif // _IMAGE_HPP_


