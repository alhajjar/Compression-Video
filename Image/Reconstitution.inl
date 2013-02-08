//////////////////////////////////////////////////////////////
//                       Reconstitution.inl                 //
//                 -------------------------                //
//						 diamond_Project                    //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

#define Reconstitution_MAIN

#include <cstring>

using namespace std;


template <class T>
void Reconstitution<T>::Reconstitue(Image<T>& src, Image<T>& imageReconstruite,Image<Vecteur> &Matrice)
{ 
	Image<T> block(16,16);
    
	
	int i, j, k, l;

	for(i=0;i<src.NbRow();i+=16){
		for(j=0;j<src.NbCol();j+=16){	
		extract<T>::Extraction(src, block, i + Matrice(i/16,j/16).getX(), j + Matrice(i/16,j/16).getY());
		T* ptrImageReconstruite = imageReconstruite.PixelPointer(i,j);
		T* ptrBlock = block.PixelPointer(0,0);
		for(k=0;k<16;k++){
		for(l=0;l<16;l++){
			*ptrImageReconstruite=*ptrBlock;
			ptrBlock++;
			ptrImageReconstruite++;
				}
			ptrImageReconstruite+=src.NbCol()-16;
		}
		
		}
	}
	
}