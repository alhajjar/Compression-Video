////////////////////////////////////////////////////////////////////
//						  CLASSSAD.inl                             //
//                 -------------------------                       //
//                      diamond_Project                            //
//                                                                 //
//                                                                //
////////////////////////////////////////////////////////////////////
#define CLASSSAD_MAIN

#include <cstring>

using namespace std;

CLASSSAD::CLASSSAD()
{
	SAD = 0;
}

CLASSSAD::~CLASSSAD()
{
}

unsigned int CLASSSAD::getSAD() const
{
	return SAD;
}

void CLASSSAD::setSAD(int sad)
{
	SAD = sad;
}