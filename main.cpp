#include <iostream>   //I/O
#include <fstream>    //File Input handling
#include <string>     //String convenience

#include "HeapMin.h"	              //Min 5-Heap
#include "HeapMax.h"	              //Max 5-Heap

//Load a HeapMin from a (.txt) file
HeapMin* loadMinHeap(std::string fName) {
  std::ifstream file(fName);
  int num;
  std::cout << "\n\nAttempting to create a 5-heap from table from file " << fName << "...";
  if (file.is_open()) {
    HeapMin* heap = new HeapMin();
    while(file >> num) heap->insert(num); //Load numbers to table.
    file.close();
    return heap;
  } else return new HeapMin();
}

//Load a HeapMax from a (.txt) file
HeapMax* loadMaxHeap(std::string fName) {
  std::ifstream file(fName);
  int num;
  std::cout << "\n\nAttempting to create a 5-heap from table from file " << fName << "...";
  if (file.is_open()) {
    HeapMax* heap = new HeapMax();
    while(file >> num) heap->insert(num); //Load numbers to table.
    file.close();
    return heap;
  } else return new HeapMax();
}

//Main function
int main(int argc, char* argv[])
{
  if (!argv[1]) std::cout << "\nNo file arguments provided. Defaulting to 'data.txt'.";
	std::string fileName = (argv[1]) ? argv[1] : "data.txt"; //File name assignment

	HeapMin* minHeap = loadMinHeap(fileName);
	HeapMax* maxHeap = loadMaxHeap(fileName);

  //Main IO loop - controls interaction Binary Search Tree.
	int choice = 0;
	do {
    std::cout << "\n\n................................................................"
									<< "\nPlease choose one of the following commands:"
									<< "\n1-	Insert"
                  << "\n2-	DeleteMin"
                  << "\n3-	FindMin"
                  << "\n4-	FindMax"
                  << "\n5-	DeleteMax"
                  << "\n6-	Level-Order"
                  << "\n7-	Exit"
									<< "\n> ";
    std::cin >> choice;
		int num = 0; //Contains I/O responses
    switch(choice) {
      case 1: //Handle Insert
        std::cout << "\nEnter a number to be inserted: \n> ";
				std::cin >> num;
        minHeap->insert(num);
        maxHeap->insert(num);
        break;
      case 2: //Handle DeleteMin
        std::cout << "\nDeleting the minimum value...";
        minHeap->deleteMin();
        maxHeap->deleteMin();
        break;
      case 3: //Handle FindMin
        std::cout << "\nFinding the minimum value...";
        std::cout << "\nMinimum: " << ((minHeap->getSize()) ? std::to_string(minHeap->getMin()) : "(Empty)");
        break;
      case 4: //Handle FindMax
        std::cout << "\nFinding the maximum value...";
        std::cout << "\nMaximum: " << ((maxHeap->getSize()) ? std::to_string(maxHeap->getMax()) : "(Empty)");
        break;
      case 5: //Handle DeleteMax
        std::cout << "\nDeleting the maximum value...";
        minHeap->deleteMax();
        maxHeap->deleteMax();
        break;
      case 6: //Handle Level-order
        std::cout << "\nLevel-Order traversal:";
        std::cout << "\nMin: "; minHeap->levelorder();
        std::cout << "\nMax: "; maxHeap->levelorder();
        break;
      case 7: break; //Handle Exit
      default:
        std::cout << "\nThat option was not found. Please try again.";
        break;
    }

} while (choice != 7);
  std::cout << "\n\nExiting - dumping heap...\n";
  delete minHeap;
  delete maxHeap;
}
