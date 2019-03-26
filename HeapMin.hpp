

#include "HeapMin.h"

//Constructor
HeapMin::HeapMin(int maxSize)
{
  MAX_SIZE = maxSize;
  heap = new int[MAX_SIZE];
  for (int i = 0; i < MAX_SIZE; i++) heap[i] = -1;  //Initialize values to -1
  insertPoint = 0;                                  //Initialize insertion point marker
}

//Destructor
HeapMin::~HeapMin()
{
  delete[] heap;
}

//Build the 5-Heap (Bottom-up approach)
//swapPoint marks the child index to check if swapping is necessary
void HeapMin::buildHeap(int swapPoint, bool sinking)
{

      //Perform swap - travel up or down the heap, and recurse
      if (heap[swapPoint] < heap[getParent(swapPoint)] && heap[getParent(swapPoint)] != -1 && !sinking) { //Float up the Heap
          int temp = heap[getParent(swapPoint)];          //Temporarily store parent
          heap[getParent(swapPoint)] = heap[swapPoint];   //Place child into parent
          heap[swapPoint] = temp;                         //Place parent where child was
          buildHeap(getParent(swapPoint));                //Recurse with parent as swap point
      } else if (heap[swapPoint] > heap[getParent(swapPoint)] && heap[getParent(swapPoint)] != -1 && sinking) {  //Sink down the Heap
          for (int i = 1; i <= 5; i++) {  //Swaps with the leftmost child not satisying the heap-ordered tree property
              if (heap[getChild(i, swapPoint)] < heap[swapPoint] && heap[getChild(i, swapPoint)] != -1) {
                  int temp = heap[swapPoint];                         //Temporarily store parent
                  heap[swapPoint] = heap[getChild(i, swapPoint)];     //Place child into parent
                  heap[getChild(i, swapPoint)] = temp;                //Place child where parent was
                  buildHeap(getChild(i, swapPoint), true);            //Recurse with child as swap point
                  break;
              }
          }
      }
}

//Insert a given value to the 5-Heap (and incremement insertionPoint)
void HeapMin::insert(int value)
{
    heap[insertPoint] = value;
    buildHeap(insertPoint);
    insertPoint++;
}

//Delete minimum/maximum values from 5-Heap
void HeapMin::deleteMin()
{
  //int minIndex = findMin();
  //heap[minIndex] = -1;
  //buildHeap(minIndex, true);
  //insertPoint--;
}

void HeapMin::deleteMax()
{
  //int maxIndex = findMax();
  //heap[maxIndex] = -1;
  //buildHeap(maxIndex, true);
  //insertPoint--;
}

//Find minimum/maximum values in 5-Heap
//Return - index of the located int. -1 if not found.
int HeapMin::findMin()
{ return (getSize()) ? 0 : -1; }

int HeapMin::findMax()
{
  return (!getSize()) ? -1 : heap[getSize()];
}

//Return value from the found index for convenient outputting
int HeapMin::getMin()
{ return heap[findMin()]; }

int HeapMin::getMax()
{ return heap[findMax()]; }

//Level-Order Traversal
void HeapMin::levelorder()
{
  for (int i = 0; i < getSize(); i++) std::cout << ((heap[i] != -1) ? (std::to_string(heap[i]) + " ") : "");

  //DEBUG
  // std::cout << ((heap[i] != -1) ? (!(i%5)?"\n":"") + std::to_string(heap[i]) + " " : "");
}


//Get the chosen child (given childID 1-5) for a given parent index.
//Returns -1 if not found.
int HeapMin::getChild(int childID, int parentIndex)
{ return ((5 * parentIndex) + childID); }

//Get the parent value of a child, given the child's index
//Returns -1 if not found.
int HeapMin::getParent(int childIndex)
{ return ((childIndex-1) / 5); }

int HeapMin::getSize()
{
  for (int i = 1; i < MAX_SIZE; i++) if (heap[i] == -1) return i;
  return MAX_SIZE;
}
