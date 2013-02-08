//////////////////////////////////////////////////////////////
//                       extract.inl                        //
//                 -------------------------                //
//						 diamond_Project                    //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

#define extract_MAIN

#include <cstring>

using namespace std;


template <class T>
void extract<T>::Extraction(Image<T>& image, Image<T>& imagette,  int abscisse, int Ordonnee)
{
	int i, j;	
	T* ptrImage = image.PixelPointer(abscisse,Ordonnee);
	T* ptrImagette = imagette.PixelPointer(0,0);
	for(i=0; i<16; i++){
		for(j=0; j<16; j++){
			*ptrImagette=*ptrImage;
			ptrImage++;
			ptrImagette++;			
		}

		ptrImage += image.NbCol() - 16;
	}
		
} 
