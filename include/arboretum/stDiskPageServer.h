/**
* @file
*
* This file defines the abstract class stPageServer.
*
* @version 1.0
* @author Fabio Jun Takada Chino (chino@icmc.usp.br)
* @author Marcos Rodrigues Vieira (mrvieira@icmc.usp.br)
*/
#ifndef __STDISKPAGESERVER_H
#define __STDISKPAGESERVER_H

#include  <arboretum/stPage.h>
#include  <arboretum/stPageServer.h>
#include  <arboretum/stClientPageManager.h>

/**
* @version 1.0
* @author Fabio Jun Takada Chino (chino@icmc.usp.br)
* @author Marcos Rodrigues Vieira (mrvieira@icmc.usp.br)
* @ingroup storage
* @todo Implementation of this class.
*/
class stDiskPageServer: public stPageServer{
   public:


      stClientPageManager * OpenClient(int clientID);
      void CloseClient(stClientPageManager * client);
      stClientPageManager * CreateClient();

      void Open();
      void Close();
      void Create();

   private:
      struct stPageHeader{
         u_int32_t next;
         int clientID;
      };

      struct stClientEntry{
         int ID;
         u_int32_t HeaderPageID;
      };//end stClientEntry

      struct stHeader{
         char Magic[4];
         u_int32_t InUse;
         u_int32_t PageCount;
         u_int32_t firstFree;
         int ClientCount;
         int LatPage
         u_int32_t Next;
      };

      struct stExtHeader{
         int ClientCount;
         u_int32_t Next;
      };

};//end stDiskPageServer

#endif //__STDISKPAGESERVER_H
