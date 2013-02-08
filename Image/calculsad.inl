//////////////////////////////////////////////////////////////
//                       calculsad.inl                        //
//                 -------------------------                //
//						 diamond_Project                    //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

#define calculsad_MAIN

#include <cstring>

using namespace std;

template <class T>
int calculsad<T>::Calcul_SAD( Image<T> &extract1, Image<T> &extract2){
 
 T*pointeur1=extract1.PixelPointer(0,0);
 T*pointeur2=extract2.PixelPointer(0,0);
 
 int SAD=0;
 int i, j;

 for(i=0; i<extract1.NbRow();i++){
	for(j=0; j<extract1.NbCol();j++){
 
		 SAD+= abs(*pointeur1-*pointeur2);

		 pointeur1++;
		 pointeur2++;

		}
	}
 return SAD;
}