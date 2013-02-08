//////////////////////////////////////////////////////////////
//                        ImageIO.inl                       //
//                 -------------------------                //
//						 Diamond_Project                    //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////


//---------------------------------------------
//     IO_image::ReadRawType
//
// lecture d'une image au format raw sans entête,
// les données sont stockées au format du template
//---------------------------------------------
template <class T>
int ImageIO<T>::ReadRawType(istream &is, 
							Image<T> &image, 
							unsigned int nbRow, 
							unsigned int nbCol,
							unsigned int numeroFrame)
{
  image.Resize(NbRow,NbCol);
  
   if(numeroFrame)
	is.seekg(numeroFrame*image.BufferSize(),ios::cur);
   is.read((char *)(image.PixelPointer(0)), nbRow*nbCol*sizeof(T));

  if (is.fail())
  {
    cerr << "ERREUR: impossible de lire une image dans un flux!" << endl;
    abort();
    return 0;
  }
  return 1;
}

template <class T>
int ImageIO<T>::ReadRawType(const char *const filename, 
							Image<T> &image, 
							unsigned int nbRow, 
							unsigned int nbCol,
							unsigned int numeroFrame)
{
  ifstream ifs(filename, ios::in|ios::binary);

  if (ifs.fail())
  {
    cerr << "ERREUR: impossible d'ouvrir le fichier " << filename << "!" << endl;
    abort();
    return 0;
  }

  return ReadRawType(ifs, image, nbRow, nbCol, numeroFrame);
}

//---------------------------------------------
//     ImageIO::WriteRawType
//
// ecriture d'une image au format raw sans entête,
// les données sont stockées au format du template
//---------------------------------------------
template <class T>
int ImageIO<T>::WriteRawType(ostream &os, const Image<T> &image)
{
  os.write((const char *)(image.PixelPointer(0)), image.NbRow()*image.NbCol()*sizeof(T));

  if (os.fail())
  {
    cerr << "ERREUR: impossible d'ecrire une image dans un flux!" << endl;
    abort();
    return 0;
  }
  return 1;
}

template <class T>
int ImageIO<T>::WriteRawType(const char *const filename, const Image<T> &image)
{
#ifndef IRIX64
  ofstream ofs(filename, ios::out|ios::binary);
#else
  ofstream ofs(filename);
#endif
  if (ofs.fail())
  {
    cerr << "ERREUR: impossible de creer le fichier " << filename << "!" << endl;
    abort();
    return 0;
  }

  return WriteRawType(ofs, image);
}


//---------------------------------------------
//     ImageIO::ReadRawUChar
//
// lecture d'une image au format raw sans entête,
// les données sont stockées en unsigned char
//---------------------------------------------
template <class T>
int ImageIO<T>::ReadRawUChar(istream &is, 
							 Image<T> &image, 
							 unsigned int nbRow, 
							 unsigned int nbCol,
							 unsigned int numeroFrame)
{
  unsigned char *buffer;
  unsigned int  i;

  buffer = new unsigned char [nbRow*nbCol];
  
 if(numeroFrame)
  is.seekg(numeroFrame*image.BufferSize(),ios::cur);

 is.read((char *)buffer, nbRow*nbCol);

  if (is.fail())
  {
    cerr << "ERREUR: impossible de lire une image dans un flux!" << endl;
    abort();
    delete [] buffer;
    return 0;
  }

  image.Resize(nbRow,nbCol);
  T* bufferin= image.PixelPointer(0,0);
  for(i=0; i<nbRow*nbCol; i++)
    bufferin[i] = (T) (buffer[i]);

  delete [] buffer;
  return 1;
}

template <class T>
int ImageIO<T>::ReadRawUChar(const char *const filename, 
							 Image<T> &image, 
							 unsigned int nbRow, 
							 unsigned int nbCol,
							 unsigned int numeroFrame)
{
#ifndef IRIX64
  ifstream ifs(filename, ios::in|ios::binary);
#else
  ifstream ifs(filename);
#endif
  if (ifs.fail())
  {
    cerr << "ERREUR: impossible d'ouvrir le fichier " << filename << "!" << endl;
    abort();
    return 0;
  }

  return ReadRawUChar(ifs, image, nbRow, nbCol);
}

//---------------------------------------------
//     ImageIO::WriteRawUChar
//
// écriture d'une image au format raw sans entête,
// les données sont stockées en unsigned char
//---------------------------------------------
template <class T>
int ImageIO<T>::WriteRawUChar(ostream &os, const Image<T> &image)
{
  unsigned char *buffer;
  unsigned int i;
  unsigned int nbCol=image.NbCol();
  unsigned int nbRow=image.NbRow();
  buffer = new unsigned char [nbRow*nbCol];
  const T* bufferout= image.PixelPointer(0,0);
  for(i=0; i<nbRow*nbCol; i++)
     buffer[i] = (unsigned char) bufferout[i];

  os.write((char *)buffer, nbRow*nbCol);
  delete [] buffer;
  if (os.fail())
  {
    cerr << "ERREUR: impossible d'ecrire une image dans un flux!" << endl;
    abort();
    return 0;
  }
  return 1;
}

template <class T>
int ImageIO<T>::WriteRawUChar(const char *const filename, const Image<T> &image)
{
#ifndef IRIX64
  ofstream ofs(filename, ios::out|ios::binary);
#else
  ofstream ofs(filename);
#endif
  if (ofs.fail())
  {
    cerr << "ERREUR: impossible d'ouvrir le fichier " << filename << "!" << endl;
    abort();
    return 0;
  }

  return WriteRawUChar(ofs, image);
}

