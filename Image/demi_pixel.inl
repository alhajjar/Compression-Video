//////////////////////////////////////////////////////////////
//                       Demi_pixel.inl                     //
//                 -------------------------                //
//						 Diamond_Project                    //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

#define Demi_pixel_MAIN

#include <cstring>


using namespace std;

template <class T>
Image<T> Demi_pixel<T>::demi_pixel(Image<T> &ima){

	Image<T> Imadouble (2*ima.NbRow(),2*ima.NbCol());
		T* ptr1;
		T* ptr2;

		for(int i=0;i<(2*ima.NbRow());i++){
			for(int j=0;j<(2*ima.NbCol());j++){

	ptr1 = Imadouble.PixelPointer(i,j);
	ptr2 = ima.PixelPointer(i/2,j/2);
            *ptr1=*ptr2;

			}
		}

	return Imadouble;
}


template <class T>
Image<T> Demi_pixel<T>::Reconstruction_demi_pixel(Image<T> &ima, Image<Vecteur> &Matrice){

	Image<T> ima2 = demi_pixel(ima);
	Image<T> imageReconstruite(ima.NbRow(),ima.NbCol());

	Image<T> block(16,16);
    
	int i, j, k, l;

	for(i=0;i<ima.NbRow();i+=16){
		for(j=0;j<ima.NbCol();j+=16){	
		extract<T>::Extraction(ima2, block, 2*(i + Matrice(i/16,j/16).getX()),2*(j + Matrice(i/16,j/16).getY()));
		T* ptrImageReconstruite = imageReconstruite.PixelPointer(i,j);
		T* ptrBlock = block.PixelPointer(0,0);
		for(k=0;k<16;k++){
		for(l=0;l<16;l++){
			*ptrImageReconstruite=*ptrBlock;
			ptrBlock++;
			ptrImageReconstruite++;
				}
			ptrImageReconstruite+=ima.NbCol()-16;
		}
		
		}
	}
	return imageReconstruite;
}
