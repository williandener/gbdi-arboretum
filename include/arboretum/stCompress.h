/**
* @file
*
* This file defines the class...
*
* @version 1.0
* @author Fabio Jun Takada Chino (chino@icmc.sc.usp.br)
* @author Enzo Seraphim (seraphim@icmc.sc.usp.br)
* @todo Documentation!!!
*/
#ifndef __STCOMPRESS_H
#define __STCOMPRESS_H

#include <arboretum/stCommon.h>


/**
*
* @ingroup userlayerutil
*/
class stCompressor{
   public:
      /**
      * Returns a pointer to the data array.
      */
      const unsigned char * GetData() const{
         return buff;
      }//end GetData
      
      /**
      * Returns the number of bytes of the data array.
      */
      const u_int32_t GetDataSize() const{
         // return ceil(bitOffset / 8)
         return (bitOffset >> 3) + ((bitOffset & 0x7) ? 1 : 0);
      }//end GetDataSize
      
      /**
      * Writes the contents of buff to this compressor.
      *
      * @param buff The buffer.
      * @param size Size of the buffer in bytes.
      */
      virtual void Write(unsigned char * buff, u_int32_t size) = 0;      
      
      /**
      * Resets this compressor. All compressed data will be lost.
      */
      void Reset(){
         bitOffset = 0;
      }//end Reset
      
      /**
      * Reserves a given number of bytes in the internal buffer.
      *
      * @param size The number of byte to be reserved.
      */
      void Reserve(u_int32_t size){
         Resize(size * 8);
      }//end Reserve
   protected:
      /**
      * Bit buffer.
      */
      unsigned char * buff;
      
      /**
      * Size of bit buffer in bytes.
      */
      u_int32_t buffSize;
      
      /**
      * Current bit offset.
      */
      u_int32_t bitOffset;
      
      /**
      * Increment of the internal buffer in bytes.
      */
      u_int32_t increment;
      
      /**
      * Returns true if the given number of bits will fit in the internal buffer.
      *
      * @param size Number of bits.
      */
      bool WillFit(u_int32_t size);
      
      /**
      * Writes the contents of buff to this compressor.
      *
      * @param buff The buffer.
      * @param size Number of bits to write.
      */
      void WriteBits(unsigned char * buff, u_int32_t size);
      
      /**
      * Resizes the internal buffer.
      *
      * @param newSize New number of bits.
      */
      void Resize(u_int32_t newSize);
};//end stCompressor

/**
*
* @ingroup userlayerutil
*/
class stDecompressor{
   public:
      /**
      * Sets the compressed data. This method copies the contents of
      * buff to an internal buffer.
      *
      * @param buff Compressed data.
      * @param size Size of the compressed data in bytes.
      */
      void SetData(const unsigned char * buff, u_int32_t size);
      
      /**
      * Reads some bytes to a buffer.
      *
      * @param buff The buffer.
      * @param size Size of the buffer in bytes.
      */
      virtual void Read(unsigned char * buff, u_int32_t size) = 0;    
      
      /**
      * Resets the data offset.
      */
      void Reset(){
         bitOffset = 0;
      }//end Reset
   protected:
      /**
      * Bit buffer.
      */
      unsigned char * buff;
      
      /**
      * Size of bit buffer in bytes.
      */
      u_int32_t buffSize;
      
      /**
      * Current bit offset.
      */
      u_int32_t bitOffset;
      
      /**
      * Reads some bits from data.
      *
      * @param buff The buffer.
      * @param size Number of bits.
      */
      void ReadBits(unsigned char * buff, u_int32_t size);
};//end stDecompressor


#endif //__STCOMPRESS_H
