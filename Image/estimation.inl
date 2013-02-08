//////////////////////////////////////////////////////////////
//                       estimation.inl                     //
//                 -------------------------                //
//						 diamond_Project                    //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

#define estimation_MAIN

#include <cstring>

using namespace std;

template <class T>
void estimation<T>::estimationDiamant(Image<T>& src, Image<T>& imagette,Vecteur& vecteur,  int abscisse,  int Ordonnee)
{
	int i;
	Image<T> Block(16,16);
	
	int tmp, SAD;
	CLASSSAD minsad;
	minsad.setSAD(100000);

	extract<T>::Extraction(src, Block, abscisse, Ordonnee);
	vecteur.setX(abscisse);
	vecteur.setY(Ordonnee);
	//Vecteur(abscisse,Ordonnee);
	SAD = calculsad<T>::Calcul_SAD(imagette, Block);
	minsad.setSAD(SAD);
	SAD = minsad.getSAD();

	int I[9] = {abscisse,abscisse+2, abscisse+1, abscisse, abscisse-1, abscisse-2, abscisse-1, abscisse, abscisse+1};
	int J[9] = {Ordonnee,Ordonnee, Ordonnee+1, Ordonnee+2, Ordonnee+1, Ordonnee, Ordonnee-1, Ordonnee-2, Ordonnee-1};

	for(i=0; i<9; i++){		
			if( (I[i] > src.NbRow())|| (I[i]+16 > src.NbRow()) || (I[i] < 0) || (J[i]> src.NbCol()) || (J[i]+16 > src.NbCol()) || (J[i] < 0)){}
			else{
				extract<T>::Extraction(src, Block, I[i], J[i]);
				tmp = calculsad<T>::Calcul_SAD(imagette, Block);
				
				if(tmp < SAD){
				
					minsad.setSAD(tmp);
					//vecteur=Vecteur(I[i],J[i]);
					vecteur.setX(I[i]);
					vecteur.setY(J[i]);
				}
				if(tmp==0)
				i=7;
			 }	
	   }
}


template <class T>
void estimation<T>::estimationVecteur(Image<T>& src, Image<T>& imagette,Vecteur& vecteur,int abscisse,  int ordonnee)
{
	vecteur.setX(abscisse);
	vecteur.setY(ordonnee);
	//Vecteur(abscisse,ordonnee);
	
	int tmp[2]={abscisse,ordonnee};

	for(int i=0; i<100; i++){
	 estimationDiamant(src, imagette,vecteur, tmp[0], tmp[1]);
	 if(tmp[0]==vecteur.getX() && tmp[1]==vecteur.getY())
		 i=100;
	 else{
		 tmp[0]=vecteur.getX();
		 tmp[1]=vecteur.getY();	
	 }
	 }
 
vecteur.setX(tmp[0] - abscisse);
vecteur.setY(tmp[1]- ordonnee);
			
}

	template <class T>
	Image<Vecteur> estimation<T>::estimationMatrice(Image<T> &ima, Image<T> &image2,  Vecteur &vect){
    Image<Vecteur> ImageVecteur(18,22);
	Image<T> imagette(16,16);
	for(unsigned int i=0; i<ima.NbRow();i+=16){
		for (unsigned int j=0; j<ima.NbCol();j+=16){
			extract<T>::Extraction(image2,imagette,i,j);
		estimation<T>::estimationVecteur(ima,imagette,vect,i,j);
		int tmp1[2]={vect.getX(),vect.getY()};

				ImageVecteur(i/16,j/16) = Vecteur(tmp1[0],tmp1[1]);
		       // ImageVecteur(i/16,j/16).setY(tmp1[1]);
		}
	}
	return ImageVecteur;
}