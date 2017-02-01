/**
* @file
*
* This file has the implementation of the functions defined in the file stUtil.
*
* @version 1.0
* @author Fabio Jun Takada Chino (chino@icmc.usp.br)
* @author Marcos Rodrigues Vieira (mrvieira@icmc.usp.br)
*/
#include <arboretum/stUtil.h>

//------------------------------------------------------------------------------
// Class stMessageString
//------------------------------------------------------------------------------
void stMessageString::Append(const char * str){
   this->str.append(str);
}//end Append

//------------------------------------------------------------------------------
void stMessageString::Append(double d){
   char tmp[32];

#ifdef _MSC_VER
   _snprintf_s(tmp, sizeof(tmp), sizeof(tmp), "%f", d);
#else
   printf(tmp, "%f", d);
#endif
 Append(tmp);
}//end Append

//------------------------------------------------------------------------------
void stMessageString::Append(int i){
   char tmp[32];

#ifdef _MSC_VER
   _snprintf_s(tmp,  sizeof(tmp), sizeof(tmp), "%d", i);
#else
   sprintf(tmp, "%d", i);
#endif
   Append(tmp);
}//end Append

//------------------------------------------------------------------------------
// struct doubleIndex
//------------------------------------------------------------------------------
/*
struct doubleIndex & doubleIndex::operator = (const struct doubleIndex & x){
   this->Distance = x.Distance;
   this->Index = x.Index;
   return (*this);
}//end doubleIndex::operator =
*/
//------------------------------------------------------------------------------
bool operator < (const doubleIndex & x, const doubleIndex & y){
   return x.Distance < y.Distance;
}//end operator <
