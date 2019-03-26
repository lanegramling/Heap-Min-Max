#ifndef HEAPMIN_H
#define HEAPMIN_H

#include <iostream>

//This Class is an implementation of an Integer 5-MinHeap using an array.

class HeapMin
{
private:
  int MAX_SIZE = 500;
  int* heap; //5-Heap contents
  int insertPoint;

  //Get the chosen child (given childID 1-5) for a given parent index.
  //Returns -1 if not found.
  int getChild(int childID, int parentIndex);

  //Get the parent value of a child, given the child's index
  //Returns -1 if not found.
  int getParent(int childIndex);

public:
  //Constructor
  HeapMin(int maxSize=500);

  //Destructor
  ~HeapMin();

  //Build the 5-Heap
  void buildHeap(int swapPoint, bool sinking=false);

  //Insert a given value to the 5-Heap
  void insert(int value);

  //Delete minimum/maximum values from 5-Heap
  void deleteMin();
  void deleteMax();

  //Find minimum/maximum values in 5-Heap
  int findMin();
  int findMax();

  //Return value from the found index for convenient outputting
  int getMin();
  int getMax();

  //Get the current size of the heap
  int getSize();

  //Level-Order Traversal
  void levelorder();

};

#include "HeapMin.hpp"

#endif
