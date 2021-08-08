#ifndef QUEUE_H
#define QUEUE_H

#include "mission.h"
#include "target.h"
#include "defines.h"

template <class T, int size>
class QueueClass
{
public:
	const int Count;
	QueueClass(void);
	T &operator[](int);
	T &First(void);
	void Init(void);
	int Next(void);
	int Add(T const &);
	int Get_Head(void);
	int Get_Tail(void);
	T *Get_Array(void);

private:
	int Head; // Index of element in list the longest.
	int Tail; // Index where next new addition will go.
	T Array[size]; // Raw array of objects.
};


template <class T, int size>
inline QueueClass<T, size>::QueueClass(void) : Count(0)
{
	Init();
}

/***********************************************************************************************
 * QueueClass<T,size>::Init -- Initializes queue to empty state.                               *
 *                                                                                             *
 *    This function resets the queue to an empty state.                                        *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   12/09/1994 JLB : Created.                                                                 *
 *=============================================================================================*/
template <class T, int size>
inline void QueueClass<T, size>::Init(void)
{
	((int &)Count) = 0;
	Head = 0;
	Tail = 0;
}

/***********************************************************************************************
 * QueueClass<T,size>::Add -- Add object to queue.                                             *
 *                                                                                             *
 *    This function is used to add an object to the tail of the line. If the queue cannot      *
 *    accept any more entries, then the object won't be added and false will be returned.      *
 *                                                                                             *
 * INPUT:   object   -- The object that is to be added to the queue.                           *
 *                                                                                             *
 * OUTPUT:  bool; Was the object added successfully?                                           *
 *                                                                                             *
 * WARNINGS:   If the queue is full, then the object won't be added. Be sure to check for this.*
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   12/09/1994 JLB : Created.                                                                 *
 *=============================================================================================*/
template <class T, int size>
inline int QueueClass<T, size>::Add(T const &q)
{
	if (Count < size)
	{
		Array[Tail] = q;
		Tail = (Tail + 1) & (size - 1);
		((int &)Count) = Count + 1;
		return (true);
	}
	return (false);
}

/***********************************************************************************************
 * QueueClass<T,size>::Next -- Throws out the head of the line.                                *
 *                                                                                             *
 *    This routine is used to discard the object at the head of the line. All remaining        *
 *    objects "move up" one. No actual movement occurs, merely the index is adjusted, but      *
 *    the affect is that the next oldest object in the queue will now be returned with the     *
 *    next call to the First() function.                                                       *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns the number of object remaining in the queue.                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   12/09/1994 JLB : Created.                                                                 *
 *=============================================================================================*/
template <class T, int size>
inline int QueueClass<T, size>::Next(void)
{
	if (Count)
	{
		Head = (Head + 1) & (size - 1);
		((int &)Count) = Count - 1;
	}
	return (Count);
}

/***********************************************************************************************
 * QueueClass<T,size>::operator[] -- Fetches reference to sub object in queue.                 *
 *                                                                                             *
 *    Use this routine to examine individual objects within the queue. The oldest object in    *
 *    the queue is referenced by an index value of zero. The newest object in the queue is     *
 *    referenced by a value of Count-1. If there are no objects in the queue, then this        *
 *    operator is undefined. Although this operator allows examination of the queue, there is  *
 *    no corresponding ability to insert or delete objects from the middle of the queue.       *
 *                                                                                             *
 * INPUT:   index -- The index into the queue of objects. Valid values range from zero to      *
 *                   Count-1. All other values return an undefined reference!                  *
 *                                                                                             *
 * OUTPUT:  Returns with a reference to the object indicated by the index.                     *
 *                                                                                             *
 * WARNINGS:   Check to make sure that Count is not zero before using this operator. Failure   *
 *             to do so will return a reference to an undefined object.                        *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   12/09/1994 JLB : Created.                                                                 *
 *=============================================================================================*/
template <class T, int size>
inline T &QueueClass<T, size>::operator[](int index)
{
	return Array[(Head + index) & (size - 1)];
}

/***********************************************************************************************
 * QueueClass<T,size>::First -- Fetches reference to first object in list.                     *
 *                                                                                             *
 *    This routine is used to fetch the first object in the list (head of the line). This      *
 *    object is the oldest in the list. Typical use of this function is to get and process     *
 *    the first object so that it may be discarded with the Next() function in order to bring  *
 *    subsequent objects to the first position.                                                *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with a reference to the oldest object in the queue.                        *
 *                                                                                             *
 * WARNINGS:   If there are no objects in the queue, then this function returns an undefined   *
 *             reference. Be sure to check Count against zero before calling this function.    *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   12/09/1994 JLB : Created.                                                                 *
 *=============================================================================================*/
template <class T, int size>
inline T &QueueClass<T, size>::First(void)
{
	return Array[Head];
}

template <class T, int size>
inline int QueueClass<T, size>::Get_Head(void)
{
	return Head;
}

template <class T, int size>
inline int QueueClass<T, size>::Get_Tail(void)
{
	return Tail;
}

template <class T, int size>
inline T *QueueClass<T, size>::Get_Array(void)
{
	return Array;
}

#endif
