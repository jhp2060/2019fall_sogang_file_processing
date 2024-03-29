// fixlen.h
#ifndef FIXLEN_H
#define FIXLEN_H

#include <stdlib.h>
#include <iostream>
#include "iobuffer.h"
#define AVAIL_MAX 100

class FixedLengthBuffer: public IOBuffer
// Abstract class designed to support fixed length records
{
   public:
	FixedLengthBuffer (int recordSize = 1000);
	FixedLengthBuffer (const FixedLengthBuffer & buffer); // copy constructor

	void Clear (); // clear values from buffer
	int Read (istream &);
	int Write (ostream &) const;
	int ReadHeader (istream &); // read header from stream
	int WriteHeader (ostream &) const; // write a header to the stream
	void Print (ostream &) const;
	int SizeOfBuffer () const; // return size of buffer

	// project1 : 6-21, 6-23
	void Delete(ostream& os, int recaddr);

 protected:
 	int Init (int recordSize);
	int ChangeRecordSize (int recordSize);
};

inline FixedLengthBuffer :: FixedLengthBuffer (const FixedLengthBuffer & buffer)
: IOBuffer (buffer)
{
	Init (buffer . BufferSize);
}

#endif
