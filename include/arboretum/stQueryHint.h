/**
* @file
*
* This file defines the class stQueryHint.
*
* @version 1.0
* @author Fabio Jun Takada Chino (chino@icmc.usp.br)
* @author Marcos Rodrigues Vieira (mrvieira@icmc.usp.br)
*/
#ifndef __STQUERYHINT_H
#define __STQUERYHINT_H

/**
* This class is the base class for all implementations of the query hint
* classes. A query hint is a special class that is used by some metric tree
* operations to store information about previous executions. This information
* can be used to enhance the performance of sucessive executions of the same
* operation.
*
* <p>Since each combination of operation/metric tree requires a specific type
* of information, each metric tree must implement its own set of query hint
* classes.
*
* <p>Users should not create instances of this class. Each tree has a method
* called stMetricTree::CreateQueryHint() which must be used to create the
* proper hint for each combination of mteric tree/query hint type.
*
* <p>For further information about this concept, see the library architecture
* documentation.
*
* @ingroup struct
* @author Fabio Jun Takada Chino (chino@icmc.usp.br)
* @author Marcos Rodrigues Vieira (mrvieira@icmc.usp.br)
* @note The implementation details of subclasses of this class are not
* relevant to users.
*/
class stQueryHint{

   public:

      /**
      * This destructor disposes this hint and releases all allocated resources.
      */
      virtual ~stQueryHint(){};
   
      /**
      * Returns the hint type. The mean of this value must be specified by
      * each metric access method.
      */
      int GetHintType() const { return type; }     

   private:

      /**
      * Hint type.
      */
      int type;
      
};//end stQueryHint


#endif //__STQUERYHINT_H
