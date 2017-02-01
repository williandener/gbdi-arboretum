/**
* @file
*
* This file defines the classes stInputQuery and stInputQueryPair.
*
* @version 1.0
* @author Marcos Rodrigues Vieira (mrvieira@icmc.usp.br)
*/

//----------------------------------------------------------------------------
// Class template stResult
//----------------------------------------------------------------------------
template < class ObjectType, class EvaluatorType>
stInputQuery<ObjectType, EvaluatorType>::~stInputQuery(){
   unsigned int idx;

   for (idx = 0; idx < Pairs.size(); idx++){
      if (Pairs[idx] != NULL){
         delete Pairs[idx];
      }//end if
   }//end for
   
}//end stInputQuery<ObjectType>::~stInputQuery()

//------------------------------------------------------------------------------
template < class ObjectType, class EvaluatorType>
double stInputQuery<ObjectType, EvaluatorType>::GetMinimumRadius(){
   double distance;
   u_int32_t idx;
   u_int32_t numOfEntries = GetNumOfEntries();
   double maxDistance = 0;

   for (idx = 0; idx < numOfEntries; idx++){
      distance = Pairs[idx]->GetDistance() + Pairs[idx]->GetRadius();
      if (maxDistance < distance){
         maxDistance = distance;
      }//end if
   }//end for

   // return the minimum radius.
   return maxDistance;
}//end stInputQuery<ObjectType>::GetMinimumRadius

//------------------------------------------------------------------------------
template <class ObjectType, class EvaluatorType>
u_int32_t stInputQuery<ObjectType, EvaluatorType>::ChooseRepresentative(){

   u_int32_t idx, idxRep;
   double newRadius = MAXDOUBLE;
   ObjectType * repObj;
   u_int32_t numberOfEntries = GetNumOfEntries();

   //test what representative in the Pairs is the best to the query.
   for (idx=0; idx < numberOfEntries; idx++){
      // Get the representative object
      repObj = Pairs[idx]->GetObject();
      UpdateDistances(repObj, idx);
      // if the radius is small that the previus.
      if (GetMinimumRadius() < newRadius){
         newRadius = GetMinimumRadius();
         idxRep = idx;
      }//end if
   }//end if

   // Update all distances with the real representative
   repObj = Pairs[idxRep]->GetObject();
   UpdateDistances(repObj, idxRep);
   // set the new minimum radius of this query.
   SetQueryRadius(GetMinimumRadius());

   // return the index of the new representative object for this input query.
   return idxRep;
}//end stInputQuery<ObjectType>::ChooseRepresentative

//------------------------------------------------------------------------------
template <class ObjectType, class EvaluatorType>
void stInputQuery<ObjectType, EvaluatorType>::UpdateDistances(
                           ObjectType * repObj, u_int32_t repObjIdx){
   u_int32_t idx;
   ObjectType * tmpObj;
   u_int32_t numberOfEntries = GetNumOfEntries();

   // set the idx of representative.
   SetRepresentativeIndex(repObjIdx);

   for (idx=0; idx < numberOfEntries; idx++){
      if (idx != repObjIdx){
         // It is not the representative object. Get the current object
         tmpObj = Pairs[idx]->GetObject();
         Pairs[idx]->SetDistance(Evaluator->GetDistance(repObj, tmpObj));
      }else{
         //it is the representative object
         Pairs[idx]->SetDistance(0.0);
      }//end if
   }//end for

}//end stInputQuery<ObjectType>::UpdateDistances

//------------------------------------------------------------------------------
template < class ObjectType, class EvaluatorType>
u_int32_t stInputQuery<ObjectType, EvaluatorType>::ChooseRepresentativeSmallRadius(){
   double radius;
   u_int32_t idx;
   u_int32_t numOfEntries = GetNumOfEntries();
   u_int32_t idxRep = 0;
   double minRadius = MAXDOUBLE;

   for (idx = 0; idx < numOfEntries; idx++){
      radius = Pairs[idx]->GetRadius();
      if (radius < minRadius){
         minRadius = radius;
         idxRep = idx;
      }//end if
   }//end for
   // set the radius query.
   SetQueryRadius(minRadius);
   // return the index of the new representative object.
   return idxRep;
}//end stInputQuery::ChooseRepresentativeSmallRadius()

