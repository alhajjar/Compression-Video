//////////////////////////////////////////////////////////////
//                       Imageyuv.inl                       //
//                 -------------------------                //
//						 Diamond_Project                    //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

#define IMAGEYUV_MAIN

#include <cstring>

using namespace std;


// Constructeurs //
template <class T>
ImageYUV<T>::ImageYUV ()
{
	
}


template <class T>
ImageYUV<T>::ImageYUV (const unsigned int nbRow, const unsigned int nbCol)
{
	Resize(nbRow,nbCol);
}


template <class T>
ImageYUV<T>::ImageYUV (const ImageYUV &ima)
{
    Y=ima.Y;
	U=ima.U;
	V=ima.V;
}

// Destructeur //
template <class T>
ImageYUV<T>::~ImageYUV ()
{
   
}


template <class T>
ImageYUV<T>& ImageYUV<T>::operator = (const ImageYUV &ima)
{
    Y=ima.Y;
	U=ima.U;
	V=ima.V;

	return *this;
}

template <class T>
void ImageYUV<T>::Resize (const unsigned int nbRow, const unsigned int nbCol)
{
	Y.Resize(nbRow,nbCol);
	U.Resize(nbRow/2,nbCol/2);
	V.Resize(nbRow/2,nbCol/2);

}

