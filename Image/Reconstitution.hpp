//////////////////////////////////////////////////////////////
//                       Reconstitution.hpp                 //
//                 -------------------------                //
//						 Diamond_Project                    //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

#ifndef _Reconstitution_HPP_
#define _Reconstitution_HPP_

#include <assert.h>
#include "Image.hpp"
#include "ImageYUV.hpp"
#include "Vecteur.hpp"
#include "Sadtools.hpp"
#include "extract.hpp"

using namespace std;

template <class T>
class Reconstitution
{
public:

 static void Reconstitution<T>::Reconstitue(Image<T>& src, Image<T>& imageReconstruite,Image<Vecteur> &Matrice);

}; 

#ifndef Reconstitution_MAIN
#include "Reconstitution.inl"
#endif

#endif // _extract_HPP_


