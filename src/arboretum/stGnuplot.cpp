/**
* @file
*
* This file implements the blocks of ParitionGlobal.
*
* @version 1.0
* @author Enzo Seraphim(seraphim@icmc.usp.br)
*/

#include <arboretum/stGnuplot3D.h>
#include <cstring>
#include <fstream>

//------------------------------------------------------------------------------
// Class stGnuplot
//------------------------------------------------------------------------------
stGnuplot::~stGnuplot(){
   if (title){
      delete [] title;
   }
   if (xlabel){
      delete [] xlabel;
   }
}// ~stGnuplot

//------------------------------------------------------------------------------
void stGnuplot::SetTitle(const char * str) {
   if (title){
      delete [] title;
   }
   title = new char[strlen(str)+1];
   strcpy(title, str);
}// SetTitle

//------------------------------------------------------------------------------
void stGnuplot::SetXLabel(const char * label) {
   if (xlabel){
      delete [] xlabel;
   }
   xlabel = new char[strlen(label)+1];
   strcpy(xlabel, label);
}// SetXLabel
//------------------------------------------------------------------------------

