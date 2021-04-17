#include "data_structure.hpp"

// файл с определениями

namespace itis {

  // здесь должны быть определения методов вашей структуры
  void AATree::Add(int value){
        auto node = new Node(value, nullptr, nullptr, nullptr, 1);

        if(root_ == nullptr){
            root_ = node;
        }
        else{
            Node* current = root_;
            bool isSet = false;
            while(!isSet) {
                if (value >= current->value){
                    if(current->right == nullptr){
                        current->right = node;
                        node->parent=current;
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
                        node->parent=current;
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
        if(grandparent != nullptr) {
            Node *parent = grandparent->right;
            Node *child = parent->right;
            if (child->level == grandparent->level) {
                while (grandparent != root_) {
                    grandparent->right = parent->left;
                    parent->left = grandparent;
                    parent->level++;
                    Split(grandparent->parent);
                }
                if (root_ == grandparent) {
                    grandparent->right = parent->left;
                    parent->left = grandparent;
                    parent->level++;
                    root_ = parent;
                }
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

    Node* AATree::Delete(int value){
      Node* current = Search(value);
      if(current->left == nullptr && current->right == nullptr){
          Node* parent = current->parent;
          if(parent->left == current){
              parent->left = nullptr;
          }
          else{
              parent->right = nullptr;
          }
          delete current;
      }
      else if(current->left == nullptr && current->right != nullptr){
          Node* parent = current->parent;
          if(parent->left == current){
              parent->left = current->right;
          }
          else{
              parent->right = current->right;
          }
          DecreaseLevel(current->parent);
          delete current;
      }
      else if(current->left != nullptr && current->right == nullptr){
          Node* parent = current->parent;
          if(parent->left == current){
              parent->left = current->left;
          }
          else{
              parent->right = current->left;
          }
          DecreaseLevel(current->parent);
          delete current;
      }
      else{
          Node* node = current->right;
          while(node->left != nullptr){
              node = node->left;
          }
          Node* nodeCopy = node;

          Node* parent = current->parent;
          if(parent->left == current){
              parent->left = node;
          }
          else{
              parent->right = node;
          }
          node->left = current->left;
          node->right = current->right;

          nodeCopy->parent->left = current;
          current->parent =  nodeCopy->parent;
          current->left = nullptr;
          current->right = nodeCopy->right;
          Delete(current->value);
      }
  }

    void AATree::DecreaseLevel(Node *current) {
        if(current!=root_){
            DecreaseLevel(current->parent);
        }
        current->level--;
        Skew(current);
        Split(current);
    }

    void AATree::Print(Node* current) {
      cout << "Level ";
      cout << current->level;
        cout << " | Value = ";
        cout << current->value;
        cout << " | Left ";
        Node* left = current->left;
        cout << left->value;
        cout << " | Right ";
        Node* right = current->left;
        cout << right->value;
        cout << endl;
        if(current->left != nullptr)Print(current->left);
        if(current->right != nullptr)Print(current->right);
  }
}  // namespace itis