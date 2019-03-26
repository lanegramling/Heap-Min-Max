
#include "math.h"
#include "HeapMax.h"

//Constructor
HeapMax::HeapMax(int maxSize)
{
  MAX_SIZE = maxSize;
  heap = new int[MAX_SIZE];
  for (int i = 0; i < MAX_SIZE; i++) heap[i] = -1;
  // for (int i = 0; i < MAX_SIZE; i++) printf("%d ", heap[i]); //DEBUG
  insertPoint = 0;
}

//Destructor
HeapMax::~HeapMax()
{
  delete[] heap;
}

//Build the 5-Heap (Bottom-up approach)
//swapPoint marks the child index to check if swapping is necessary
void HeapMax::buildHeap(int swapPoint, bool sinking)
{

    //Perform swap - travel up or down the heap, and recurse
    if (heap[swapPoint] > heap[getParent(swapPoint)] && heap[getParent(swapPoint)] != -1 && !sinking) { //Float up the Heap
        int temp = heap[getParent(swapPoint)];          //Temporarily store parent
        heap[getParent(swapPoint)] = heap[swapPoint];   //Place child into parent
        heap[swapPoint] = temp;                         //Place parent where child was
        buildHeap(getParent(swapPoint));                //Recurse with parent as swap point
    } else if (heap[swapPoint] < heap[getParent(swapPoint)] && heap[getParent(swapPoint)] != -1 && sinking) {  //Sink down the Heap
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

//Insert a given value to the 5-Heap (Bottom-up approach)
void HeapMax::insert(int value)
{
    heap[insertPoint] = value;
    buildHeap(insertPoint);
    insertPoint++;
}

//Delete minimum/maximum values from 5-Heap
void HeapMax::deleteMin()
{
  //int minIndex = findMin();
  //heap[minIndex] = -1;
  // buildHeap(minIndex, true);
  //insertPoint--;
}

void HeapMax::deleteMax()
{
  //int maxIndex = findMax();
  //heap[maxIndex] = -1;
  // buildHeap(maxIndex, true);
  //insertPoint--;
}

//Find minimum/maximum values in 5-Heap
//Return - index of the located int, or -1 if not found.
int HeapMax::findMin()
{
  return (!getSize()) ? -1 : heap[getSize()];
}
int HeapMax::findMax()
{ return (getSize()) ? 0 : -1; }

//Return value from the found index for convenient outputting
int HeapMax::getMin()
{ return (heap[findMin()] != -1) ? heap[findMin()] : -1; }

int HeapMax::getMax()
{ return (heap[findMax()] != -1) ? heap[findMax()] : -1; }

//Level-Order Traversal
void HeapMax::levelorder()
{
    for (int i = 0; i < getSize(); i++) std::cout << ((heap[i] != -1) ? (std::to_string(heap[i]) + " ") : "");
}


//Get the chosen child (given childID 1-5) for a given parent index.
//Returns -1 if not found.
int HeapMax::getChild(int childID, int parentIndex)
{ return ((5 * parentIndex) + childID); }

//Get the parent index of a child, given the child's index
//Returns -1 if not found.
int HeapMax::getParent(int childIndex)
{ return ((childIndex-1) / 5); }

int HeapMax::getSize()
{
  for (int i = 1; i < MAX_SIZE; i++) if (heap[i] == -1) return i;
  return MAX_SIZE;
}
