
//----------------------------------------------------------------------------
// class stListPriorityQueue
//----------------------------------------------------------------------------
/**
* This class defines node type of stListPriorityQueue.
*
*
* @author Marcos Rodrigues Vieira (mrvieira@icmc.usp.br)
* @version 1.0
* @ingroup util
* @todo Documentation update.
*/
#include <arboretum/stListPriorityQueue.h>

//------------------------------------------------------------------------------
stListPriorityQueue::~stListPriorityQueue(){
   stEntry * temp = head;
   while(head){
      head = head->GetNext();
      delete temp;
      temp = head;
   }//end while
}//end ~stListPriorityQueue

//------------------------------------------------------------------------------
void stListPriorityQueue::Add(u_int32_t pageID, double distance, double radius){
    stEntry * newEntry;
    stEntry * priorEntry = NULL;
    stEntry * currEntry = head;

    while ((currEntry!=NULL) && (distance > currEntry->GetDistance())){
       priorEntry = currEntry;
       currEntry = currEntry->GetNext();
    }//end while

    newEntry = new stEntry();
    newEntry->SetPageID(pageID);
    newEntry->SetDistance(distance);
    newEntry->SetRadius(radius);
    newEntry->SetNext(currEntry);
    capacity++;

    if (priorEntry==NULL){
       head = newEntry;
    }else{
       priorEntry->SetNext(newEntry);
    }//end if

}//end stListPriorityQueue::Add

//------------------------------------------------------------------------------
stEntry * stListPriorityQueue::Get(){
   stEntry * returnEntry = head;
   if(head){
      head = head->GetNext();
      capacity--;
   }//end if
   return returnEntry;
}//end stListPriorityQueue::Get
