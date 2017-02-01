/**
* @file
*
* This file defines some useful struct layer utilities.
*
* @version 1.0
* @author Fabio Jun Takada Chino (chino@icmc.usp.br)
* @author Marcos Rodrigues Vieira (mrvieira@icmc.usp.br)
*/
#include  <arboretum/stStructUtils.h>

//-----------------------------------------------------------------------------
// class doubleCache
//-----------------------------------------------------------------------------
doubleCache::doubleCache(int n){
   int size;
   double * p;

   // Remember the AP step 1...   
   size = (((1 + n) * n) >> 1) - 1;
   distances = new double[size];
   
   // Set all to -1
   for (p = distances; p != distances + size; p++){
      *p = -1;
   }//end for
}//end doubleCache::doubleCache
