////////////////////////////////////////////////////////////////////
//						   main.cpp                               //
//                 -------------------------                      //
//                     diamond_Project                            //
//                                                                //
//                                                                //
////////////////////////////////////////////////////////////////////

		#include <iostream>
		#include <math.h>

		#include "Image.hpp"
		#include "ImageIO.hpp"
		#include "ImageYUVIO.hpp"
		#include "ImageYUV.hpp"
		#include "extract.hpp"
		#include "calculsad.hpp"
		#include "Sadtools.hpp"
		#include "estimation.hpp"
		#include "Vecteur.hpp"	
		#include "Reconstitution.hpp"
		#include "demi_pixel.hpp"
	
		using namespace std;
		
	 int main(int argc, char *argv[])
		{
		/**************************Contrôle du nombre d'arguments***************************/	
		 if( argc < 5)
		 {
			 cerr<<endl<<argv[0]<<" <FilenameIn> <FilenameOut> <height> <width> "<<endl;
			 exit(-1);
		  }
		/************************************Fichier Entree*********************************/	
		 ifstream ifs(argv[1],ios::in|ios::binary);
			if(ifs.fail())
			{
				cerr<<"Problème d'ouverture du fichier d'entrée :"<<argv[1]<<" !"<< endl;
				exit(-1);
			 }
		/************************************Fichier Sortie*********************************/	
		 ofstream ofs(argv[2], ios::out|ios::binary);
			if (ofs.fail())
			{
				cerr << "ERREUR: impossible d'ouvrir le fichier de sortie :" <<argv[2]<<" !"<< endl;
				exit(-1);
			 }
		 unsigned int NbRow   = atoi(argv[3]);
		 unsigned int NbCol   = atoi(argv[4]);

		 /*******************************Corps du programme**********************************/
		 Image<unsigned char> Ima(NbRow,NbCol);
		 Image<unsigned char> Ima2(NbRow,NbCol);
		 Image<unsigned char> imageReconstruite(NbRow,NbCol);
		 Image<Vecteur> Matrice(18,22);
		 Image<unsigned char> image_demi_pel;
		 Vecteur vecteur;
		/***********************************************************************************/
		 ImageIO<unsigned char>::ReadRawUChar(ifs,Ima,NbRow,NbCol,0);
		 ImageIO<unsigned char>::ReadRawUChar(ifs,Ima2,NbRow,NbCol,1);
		/***********************************************************************************/
	    //extract<unsigned char>::Extraction(Ima.Y, Imagette,50,50);
	    //extract<unsigned char>::estimationVecteur(Ima, Imagette,vecteur, 200, 330);
		Matrice = estimation<unsigned char>::estimationMatrice(Ima, Ima2,vecteur);
		/*
		for(int i=0; i<18;i++){
			 for(int j=0;j<22;j++)
				 cout<<Matrice(i,j).getX()<<";"<<Matrice(i,j).getY()<<endl;
		 }*/
		  image_demi_pel=Demi_pixel<unsigned char>::Reconstruction_demi_pixel(Ima,Matrice);
		  Reconstitution<unsigned char>::Reconstitue(Ima, imageReconstruite,Matrice);
		 /***********************************************************************************/
		  ImageIO<unsigned char>::WriteRawUChar(ofs,image_demi_pel);
		  ImageIO<unsigned char>::WriteRawUChar(ofs,imageReconstruite);
		 /***********************************************************************************/

		  cout<<endl<<" !! Execution correcte !!"<<endl;
		
		return 0;
}