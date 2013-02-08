//////////////////////////////////////////////////////////////
//                        ImageYUVIO.inl                       //
//                 -------------------------                //
//						 Diamond_Project                    //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

//---------------------------------------------
//     ImageIO::ReadRawUChar
//
// lecture d'une image au format raw sans entête,
// les données sont stockées en unsigned char
//---------------------------------------------
template <class T>
int ImageYUVIO<T>::ReadRawUChar(istream &is, 
							 ImageYUV<T> &image, 
							 unsigned int nbRow, 
							 unsigned int nbCol,
							 unsigned int numeroFrame)
{
    ImageIO<unsigned char>::ReadRawUChar(is,image.Y,nbRow,nbCol);
	ImageIO<unsigned char>::ReadRawUChar(is,image.U,nbRow/2,nbCol/2);
	ImageIO<unsigned char>::ReadRawUChar(is,image.V,nbRow/2,nbCol/2);
  return 1;
}

template <class T>
int ImageYUVIO<T>::ReadRawUChar(const char *const filename, 
							 ImageYUV<T> &image, 
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
int ImageYUVIO<T>::WriteRawUChar(ostream &os, const ImageYUV<T> &image)
{
 ImageIO<unsigned char>::WriteRawUChar(os,image.Y);
 ImageIO<unsigned char>::WriteRawUChar(os,image.U);
 ImageIO<unsigned char>::WriteRawUChar(os,image.V);
  return 1;
}

template <class T>
int ImageYUVIO<T>::WriteRawUChar(const char *const filename, const ImageYUV<T> &image)
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

