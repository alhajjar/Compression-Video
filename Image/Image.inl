//////////////////////////////////////////////////////////////
//                       Image.inl                          //
//                 -------------------------                //
//						 Diamond_Project                    //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

#define IMAGE_MAIN

#include <cstring>

using namespace std;

template <class T>
void Image<T>::Allocate (const unsigned int nbRow, const unsigned int nbCol)
{
    height       = nbRow;
    width        = nbCol;
    bufferSize   = height * width;
    deleteBuffer = true;
    buffer       = new T[bufferSize];

}


template <class T>
void Image<T>::DeAllocate ()
{
    if (deleteBuffer)
    {
        if (buffer) delete [] buffer;
        height       = 0;
        width        = 0;
        bufferSize   = 0;
        deleteBuffer = false;
        buffer       = 0;
    }
}


// Constructeurs ///////////////////////////////////////////
template <class T>
Image<T>::Image ()
{
    height       = 0;
    width        = 0;
    bufferSize   = 0;
    deleteBuffer = false;
    buffer       = 0;
}


template <class T>
Image<T>::Image (const unsigned int nbRow, const unsigned int nbCol)
{
    assert((nbRow > 0) && (nbCol > 0));
    Allocate (nbRow, nbCol);
}


template <class T>
Image<T>::Image (const Image &ima)
{
    if (ima.BufferSize() > 0)
    {
        Allocate (ima.NbRow(), ima.NbCol());
        unsigned int i;
        for (i = 0; i < bufferSize; i++)
         buffer[i] = ima.buffer[i]; 
    }
    else
    {
        height       = 0;
        width        = 0;
        bufferSize   = 0;
        deleteBuffer = false;
        buffer       = 0;
    }
}

// Destructeur ////////////////////////////////////////////////////////
template <class T>
Image<T>::~Image ()
{
    DeAllocate ();
}



// Methodes d'acces ///////////////////////////////////////////////////
template <class T>
unsigned int Image<T>::NbRow () const
{
    return height;
}


template <class T>
unsigned int Image<T>::NbCol () const
{
    return width;
}


template <class T>
unsigned int Image<T>::BufferSize () const
{
    return bufferSize;
}


// operateurs d'acces /////////////////////////////////////////////////
template <class T>
const T& Image<T>::operator () (const unsigned int row, const unsigned int col) const
{
    assert(row<height);
    assert(col<width);
    
    return buffer[row * width + col];
}

// operateurs de modification /////////////////////////////////////////
template <class T>
T& Image<T>::operator () (const unsigned int row, const unsigned int col)
{
    assert((row >= 0) && (row < height));
    assert((col >= 0) && (col < width));

    return buffer[row * width + col];
}

template <class T>
Image<T>& Image<T>::operator = (const Image &ima)
{
    DeAllocate ();
    if (ima.BufferSize() > 0) 
	{ 
        Allocate (ima.NbRow(), ima.NbCol());
        unsigned int i;
        for (i = 0; i < bufferSize; i++)
           buffer[i] = ima.buffer[i];
    } 
	else 
	{
        height       = 0;
        width        = 0;
        bufferSize   = 0;
        deleteBuffer = false;
        buffer       = 0;
    }

    return *this;
}


template <class T>
const T* Image<T>::PixelPointer (const unsigned int row, const unsigned int col)const 
{
    assert((row >= 0) && (row < height));
    assert((col >= 0) && (col < width));

    return buffer + row * width + col;
}

// Methodes de modification ///////////////////////////////////////////
template <class T>
T* Image<T>::PixelPointer (const unsigned int row, const unsigned int col)
{
    assert((row >= 0) && (row < height));
    assert((col >= 0) && (col < width));

    return buffer + row * width + col;
}

template <class T>
void Image<T>::Resize (const unsigned int nbRow, const unsigned int nbCol)
{
    if ((nbRow*nbCol)!=(width*height)||(!deleteBuffer)) {
        DeAllocate ();
        Allocate (nbRow, nbCol);
    } else {
        height     = nbRow;
        width      = nbCol;
    }
}

//-- opérateur +=
//----------------
template <class T>
Image<T>& Image<T>::operator +=(const Image& ima)
{
    assert(ima.NbRow()==NbRow());
    assert(ima.NbCol()==NbCol());

    unsigned int size=ima.BufferSize();
    unsigned int i;

    for(i=0; i< size; i++)
        buffer[i] += ima.buffer[i];	

    return *this;
}

//-- opérateur -=
//----------------
template <class T>
Image<T>& Image<T>::operator -=(const Image& ima)
{
    assert(ima.NbRow()==NbRow());
    assert(ima.NbCol()==NbCol());

    unsigned int size=ima.BufferSize();

    unsigned int i;
    for(i=0; i< size; i++)
        buffer[i] -= ima.buffer[i];

    return *this;
}

