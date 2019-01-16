#include <iostream>   // for I/O facilities
#include "btree_set.h" //
#include <algorithm> // Includes sort()
#include <ctime> // access to the system clock
#include <time.h> // access to "wall clock"
using namespace std;

double elapsed_time( clock_t start, clock_t finish){
   // returns elapsed time in milliseconds
   return (finish - start)/(double)(CLOCKS_PER_SEC/1000);
}



int main (int argc, char * const argv[]) {
    cout << "\n\nbtree_set Class Test Program 1 - START\n\n";

	// Make a btree_set, and verify that empty() says it is empty.

	btree::btree_set<int,std::less<int>,std::allocator<int>,5000> S1 ;
	cout << "S1.empty() = " << S1.empty() << "\n";

	// Put something in it, and verify that it is no longer empty.


  srand( time(NULL) ); // seed the random number generator.

  clock_t start, finish ;// used to time function calls.
  double insert_time = 0;
  int size;
  cin >> size;
	start = clock();
	for(int i = 0 ; i < size ; i++ ){
		int x = rand() % (size*10);
		S1.insert(x);
	}
	finish = clock();
	insert_time += elapsed_time(start,finish);
	


  cout << "B-tree Insert time: " << (insert_time) << endl ;

  cout << "Height of B-tree: " << S1.height() << endl;
  cout << "Number of nodes: " << S1.nodes() << endl;
  cout << "Average number of bytes used per data value: " << S1.average_bytes_per_value() << endl;

	cout << "\n\nbtree_set Class Test Program 1 - DONE\n\n";

    return 0;
}
