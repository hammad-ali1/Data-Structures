/**
 * Simple C++ main using a linked-memory list class.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "List.h"
#include <iostream>

int main() {
  List<int> list;
  const int arr[] = {1, 2, 3, 4, 5, 6};
  for(auto &i: arr)
    list.insertAtFront(i);
  list.print();

  return 0;
}