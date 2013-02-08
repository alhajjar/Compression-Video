//////////////////////////////////////////////////////////////
//                       extract.hpp                        //
//                 -------------------------                //
//						 Diamond_Project                    //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

#ifndef _extract_HPP_
#define _extract_HPP_

#include <assert.h>
#include "Image.hpp"
#include "ImageYUV.hpp"
#include "Vecteur.hpp"
#include "Sadtools.hpp"

using namespace std;

template <class T>
class extract
{
public:

//  d'extraction des macro-blocs
	static void   Extraction(Image<T>& image, Image<T>& imagette, int abscisse,  int Ordonnee);

}; 


#ifndef extract_MAIN
#include "extract.inl"
#endif

#endif // _extract_HPP_


