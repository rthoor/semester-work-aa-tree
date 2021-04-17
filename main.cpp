#include <iostream>

#include "data_structure.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /*
   *                8
   *        3               10
   *    1     6         x      14
   * x   x  4   7     x   x  13   x
   *
   * x - это nullptr
   */

    itis::AATree tree;

    tree.Add(8);
    tree.Add(3);
    tree.Add(10);
    tree.Add(1);
    tree.Add(6);
    tree.Add(4);
    tree.Add(7);
    tree.Add(14);
    tree.Add(13);

    tree.Print(tree.root_);
    //  tree.Remove(4);
    //  tree.Remove(6);
    //  tree.Remove(8);
  return 0;
}