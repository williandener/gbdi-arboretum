#ifndef __STLIST_H
#define __STLIST_H


#include <arboretum/stCommon.h>

//----------------------------------------------------------------------------
// class stEntry
//----------------------------------------------------------------------------
/**
* This class defines node type of stListPriorityQueue.
*
*
* @author Adriano Siqueira Arantes (arantes@icmc.usp.br)
* @version 1.0
* @ingroup util
* @todo Tests.
* @todo Documentation update.
*/
class stEntry {
   public:

      /**
      * Set the PageID of this entry.
      *
      * @param pageID the pageID.
      */
      void SetPageID(u_int32_t pageID){
         PageID = pageID;
      }//end SetPageID

      /**
      * Returns the PageID.
      */
      u_int32_t GetPageID(){
         return PageID;
      }//end GetPageID

      /**
      * Set the Distance of this entry.
      *
      * @param distance distance of this entry.
      */
      void SetDistance(double distance){
         Distance = distance;
      }//end SetDistance

      /**
      * Returns the Distance.
      */
      double GetDistance(){
         return Distance;
      }//end GetDistance

      /**
      * Set the Radius of this entry.
      *
      * @param radius subtree radius of this entry.
      */
      void SetRadius(double radius){
         Radius = radius;
      }//end SetRadius

      /**
      * Returns the Radius.
      */
      double GetRadius(){
         return Radius;
      }//end GetRadius

      /**
      * Set the Next entry.
      *
      * @param next next entry.
      */
      void SetNext(stEntry * next){
         Next = next;
      }//end SetNext

      /**
      * Returns the next Entry.
      */
      stEntry * GetNext(){
         return Next;
      }//end GetNext

   private:

      /**
      * The ID of a Page.
      */
      u_int32_t PageID;

      /**
      * The Distance between this object and the query object.
      */
      double Distance;

      /**
      * The subtree radius of this representative.
      */
      double Radius;

      /**
      * Link for the other Entry in the List.
      */
      stEntry * Next;
};//end stEntry


//----------------------------------------------------------------------------
// class stListPriorityQueue
//----------------------------------------------------------------------------
/**
* This class implements a priority queue based on chained list.
*
* <p>This priority queue is implemented using a simple chained list which.
*
* @author Marcos Rodrigues Vieira
* @version 1.0
* @ingroup util
* @todo Documentation update.
*/
class stListPriorityQueue{
   public:

      /**
      * Creates a new priority queue.
      *
      */
      stListPriorityQueue(){
         capacity = 0;
         head = NULL;
      }//end stListPriorityQueue

      /**
      * Disposes this queue.
      */
      ~stListPriorityQueue();

      /**
      * Adds a new entry to the queue.
      *
      * @param pageID The pageID to be inserted.
      * @param w  The node value in pageID to be inserted.
      * @param dist The distance value to be inserted.
      */
      void Add(u_int32_t pageID, double distance, double radius);

      /**
      * Gets the next node. This node is removed from the queue.
      *
      * @return The head node for success or NULL if the queue is empty.
      */
      stEntry * Get();

      /**
      * Returns the size of this queue.
      */
      u_int32_t GetSize(){
         return capacity;
      }//end GetSize
      
   private:

      /**
      * Pointer to beginning of this queue.
      */
      stEntry * head;

      /**
      * Current size of this queue.
      */
      u_int32_t capacity;

};//end stListPriorityQueue

#endif //__STLIST_H
