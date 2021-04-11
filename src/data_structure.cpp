#include "data_structure.hpp"

// файл с определениями

namespace itis {

  // здесь должны быть определения методов вашей структуры
  void AATree::Add(int value){
        auto node = new Node(value, nullptr, nullptr, 1);

        if(size_ == 0){
            root_ = node;
        }
        else{
            Node* current = root_;
            Node* parentOfCurrent = root_;
            bool isSet = false;
            while(!isSet) {
                if (value >= current->value){
                    if(current->right == nullptr){
                        current->right = node;
                        Split(parentOfCurrent);
                        isSet = true;
                    }
                    else{
                        parentOfCurrent = current;
                        current = current->right;
                    }
                }
                if (value < current->value){
                    if(current->left == nullptr){
                        current->left = node;
                        Skew(current);
                        isSet = true;
                    }
                    else{
                        parentOfCurrent = current;
                        current = current->left;
                    }
                }
            }
        }
  }

  void AATree::Skew(Node* parent){
      Node *child = parent->left;
      if(child->level == parent->level) {
          parent->left = child->right;
          child->right = parent;
          parent = child;
      }
  }

    void AATree::Split(Node* grandparent){
        Node *parent = grandparent->right;
        Node *child = parent->right;
        if(child->level == grandparent->level) {
            grandparent->right = parent->left;
            parent->left = grandparent;
            grandparent = parent;
            grandparent->level++;
        }
    }


}  // namespace itis