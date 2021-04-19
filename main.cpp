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
    //tree.Add(7);
    tree.Add(14);
    tree.Add(13);
    cout << "_________________________________" << endl;
    tree.Print(tree.root_);
    cout << "----------------------------------" << endl;
    /*tree.Print1(tree.root_);
    tree.Print1(tree.root_->left);
    tree.Print1(tree.root_->right);
  tree.Print1(tree.root_->right->right); */
    tree.Delete(3);
    //  tree.Remove(6);
    //  tree.Remove(8);
  tree.Print(tree.root_);
  cout << "----------------------------------" << endl;
  return 0;
}