#include "data_structure.hpp"

// файл с определениями

namespace itis {

  // здесь должны быть определения методов вашей структуры
  void AATree::Add(int value){
        auto node = new Node(value, nullptr, nullptr, nullptr, 1);

        if(size_ == 0){
            root_ = node;
        }
        else{
            Node* current = root_;
            bool isSet = false;
            while(!isSet) {
                if (value >= current->value){
                    if(current->right == nullptr){
                        current->right = node;
                        Split(current->parent);
                        isSet = true;
                    }
                    else{
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
            while(grandparent!=root_){
                grandparent->right = parent->left;
                parent->left = grandparent;
                parent->level++;
                Split(grandparent->parent);
            }
            if(root_ == grandparent){
                grandparent->right = parent->left;
                parent->left = grandparent;
                parent->level++;
                root_ = parent;
            }
        }
    }

    Node* AATree::Search(int value) {
      Node* current = root_;
      while(true) {
          if (value == current->value) {
              return current;
          } else if (value > current->value) {
              if (current->right == nullptr) {
                  return nullptr;
              } else {
                  current = current->right;
              }
          } else if (value < current->value) {
              if (current->left == nullptr) {
                  return nullptr;
              } else {
                  current = current->left;
              }
          }
      }
   }

}  // namespace itis