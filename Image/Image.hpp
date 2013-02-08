//////////////////////////////////////////////////////////////
//                       Image.hpp                          //
//                 -------------------------                //
//						 Diamond_Project                    //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

#ifndef _IMAGE_HPP_
#define _IMAGE_HPP_

#include <assert.h>

//! La classe Image est une classe container qui permet la gestion d'images à une seule composante.
template <class T>
class Image
{
public:

	// Constructeur par defaut
	Image ();
	
	// constructeur
	Image (const unsigned int nbRow, const unsigned int nbCol);

	// constructeur par recopie
	Image (const Image &ima);
	
	// destructeur 
	virtual ~Image ();
	
	//Methodes d'acces aux parametres 
	unsigned int      NbRow () const ;
	unsigned int      NbCol () const ;
	
	//taille de l'image
	unsigned int      BufferSize () const ;

    //operateurs d'acces en lecture aux donnees
	const T& operator () (const unsigned int row, const unsigned int col) const ;
	
	//Operateurs d'acces en ecriture aux donnees
	T&       operator () (const unsigned int row, const unsigned int col);

	// acces aleatoire direct aux donnees
	T*             PixelPointer (const unsigned int row, const unsigned int col);

	// acces aleatoire direct aux donnees
	const T*       PixelPointer (const unsigned int row, const unsigned int col)const ;

	//Opérateur =
	Image&   operator = (const Image &ima);
	
	//methode de retaillage
	void     Resize (const unsigned int nbRow, const unsigned int nbCol);
	
	// Methode +=
	// suppose l'existence de l'operateur += pour T
	Image<T>& operator +=(const Image<T>& ima);
	
	// Methode -=
	// suppose l'existence de l'operateur -= pour T
	Image<T>& operator -=(const Image<T>& ima);
	
		
protected:
	// Buffer de Données
	T*  buffer;
	
	//signal si le buffer est alloué ou non
	bool deleteBuffer;
	
	//hauteur de l'image 
	unsigned int height;
	
	//largeur de l'image 
	unsigned int width;
	
	unsigned int bufferSize;

private:
	//Allocateur d'image
	void Allocate(const unsigned int nbRow, const unsigned int nbCol); 
	
	//Desallocateur d'image 
	void DeAllocate();
	
	
}; 

// end class Image


#ifndef IMAGE_MAIN
#include "Image.inl"
#endif

#endif // _IMAGE_HPP_


