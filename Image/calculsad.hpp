//////////////////////////////////////////////////////////////
//                       calculsad.hpp                        //
//                 -------------------------                //
//						 Diamond_Project                    //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

#ifndef _calculsad_HPP_
#define _calculsad_HPP_

#include <iostream>

#include "Image.hpp"
#include "ImageYUV.hpp"
#include "Vecteur.hpp"
#include "extract.hpp"
#include "Sadtools.hpp"

using namespace std;

template <class T>
class calculsad
{
public:

	 static int Calcul_SAD(Image<T> &extract1, Image<T> &extract2);

	 }; 


#ifndef calculsad_MAIN
#include "calculsad.inl"
#endif

#endif // _calculsad_HPP_
