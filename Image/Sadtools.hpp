//////////////////////////////////////////////////////////////
//                       Vecteur.hpp                        //
//                 -------------------------                //
//				       diamond_Project                      //
//                                                          //
//                                                          //
//////////////////////////////////////////////////////////////

#ifndef _SAD_HPP_
#define _SAD_HPP_

#include <assert.h>


class CLASSSAD
{
	unsigned int SAD;


public:

	 CLASSSAD();
	~CLASSSAD();

	unsigned int getSAD() const;

	void setSAD(int SAD);

};

#ifndef SAD_MAIN
#include "Sadtools.inl"
#endif
#endif // _SAD_HPP_
