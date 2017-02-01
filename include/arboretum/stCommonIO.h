/**
* @file
*
* This file includes all common I/O headers used by this library. It will help the portability
* of this code.
*
* @version 1.0
* @author Fabio Jun Takada Chino (chino@icmc.usp.br)
* @author Marcos Rodrigues Vieira (mrvieira@icmc.usp.br)
*/
#ifndef __STCOMMONIO_H
#define __STCOMMONIO_H

// GNU GCC
#ifdef __GNUG__
   #include <sys/types.h>
   #include <sys/stat.h>
   #include <fcntl.h>
   #include <unistd.h>
   
   #ifndef O_BINARY
   	#define O_BINARY 0
   #endif // O_BINARY
#endif //__GNUG__

// Microsoft Visual C++
#ifdef _MSC_VER
   
#endif //_MSC_VER


// Borland C++
#ifdef __BORLANDC__
   #include <sys/types.h>
   #include <sys/stat.h>
   #include <fcntl.h>
   #include <io.h>
#endif //__BORLANDC__


#endif //__STCOMMONIO_H
