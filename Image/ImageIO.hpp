//////////////////////////////////////////////////////////////
//                        ImageIO.hpp                       //
//                 -------------------------                //
//						 Diamond_Project                    //
//                                                          //
//                                                          //
////////////////////////////////////////////////////////////// 
#ifndef _IMAGEIO_HPP_
#define _IMAGEIO_HPP_

#include <cstdlib>
#include <cstdio>

#include <iostream>
#include <fstream>
using namespace std;

#include "Image.hpp"

// Classe entree/sortie Image
// Les m�thodes d'E/S d�velopp�es ici peuvent �tre utilis�e soit avec des flux (ifstream,istream,ostream,ofstream,...)
// soit avec des noms de fichiers (const char *) pass�s en param�tre.
// Classe regroupant toutes les fonctions necessaires a la lecture et ecriture d'images au format raw.
// Les fonctions etant  statiques, il est inutile de declarer un objet de type ImageIO.
// Toute fonction renvoie return 0 en cas d'echec, 1 en cas de succes. 



// Classe ImageIO 
template <class T>
class ImageIO 
{
public:
    // Dans la suite les param�tres ont le sens suivant:
    // param is repr�sente un flux d'entr�e  "pointant" vers la zone � lire
    // param os repr�sente un flux de sortie "pointant" vers la zone o� �crire
    // param filename repr�sente le nom du fichier dans lequel (ou a partir duquel) ecrire (lire) l'image 
    // param ima image � remplir ou � �crire
    // param nbRow nombre de lignes de l'image 
    // param nbCol nombre de colonnes de l'image
	// param numeroFrame numero d'image � lire dans la sequence
    
  // Lecture d'une image sans entete avec donnees templatees
  static int ReadRawType(istream &is, Image<T> &ima, const unsigned int nbRow, const unsigned int nbCol, unsigned int numeroFrame=0);
  static int ReadRawType(const char *const filename, Image<T> &ima, const unsigned int nbRow, const unsigned int nbCol, unsigned int numeroFrame=0);

  // Ecriture d'une image en raw (sans entete)
  static int WriteRawType(ostream &os, const Image<T> &ima);
  static int WriteRawType(const char *const filename, const Image<T> &ima);
   
  // Lecture d'une image sans entete  dont les donnees sont de type unsigned char
  static int ReadRawUChar(istream &is, Image<T> &ima, const unsigned int nbRow, const unsigned int nbCol, unsigned int numeroFrame=0);
  static int ReadRawUChar(const char *const filename, Image<T> &ima, const unsigned int nbRow, const unsigned int nbCol, unsigned int numeroFrame=0);

  // Ecriture d'une image sans entete  dont les donnees sont de type unsigned char
  static int WriteRawUChar(ostream &os, const Image<T> &ima);
  static int WriteRawUChar(const char *const filename, const Image<T> &ima);

};

#include "ImageIO.inl"


#endif // _IMAGEIO_HPP_


