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
                        Skew(current);
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
                        Split(current->parent);
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
    if(parent->left != nullptr) {
      Node* child = parent->left;
      if (child->level == parent->level) {
        parent->left = child->right;
        if(parent->left != nullptr){
          parent->left->parent = parent;
        }
        child->right = parent;
        if(parent->parent != nullptr) {
          if(parent->parent->left = parent) {
            child->parent = parent->parent;
            child->parent->left = child;
          }
          else{
            child->parent = parent->parent;
            child->parent->right = child;
          }
        }
        else{
          root_ = child;
        }
        parent->parent = child;
      }
    }

      /* if(parent->left != nullptr) {
      Node* child = parent->left;
      if (child->level == parent->level) {
        parent->left = child->right;
        if(child->right != nullptr) {
          child->right->parent = parent;
        }
        child->right = parent;
        if (parent->parent != nullptr) {
          Node* grand = parent->parent;
          child->parent = grand;
          if (grand->left == parent) {
            grand->left = child;
          } else {
            grand->right = child;
          }
        }
        else{
          child->parent = nullptr;
        }
        parent->parent = child;
        if (root_ == parent) {
          root_ = child;
        }
      }
    }
       */
  }

    void AATree::Split(Node* grandparent){

      if(temp->right!=NULL && temp->right->right!=NULL)
        if(temp->level == temp->right->right->level)
        {
          Node *ptr = temp->right;
          temp->right = ptr->left;
          if(ptr->left != NULL)
            ptr->left->parent = temp;
          ptr->left = temp;
          ptr->parent = temp->parent;
          temp->parent = ptr;
          if(ptr->parent != NULL)
            ptr->parent->right = ptr;
          ptr->level = ptr->level + 1;
          return ptr;
        }
      return temp;
      /*
        if(grandparent != nullptr) {
        Node* parent = grandparent->right;
        if (parent->right != nullptr) {
          Node* child = parent->right;
          if (child->level == grandparent->level) {
            while (grandparent != root_) {
              Node* grandgrand = grandparent->parent;
              grandparent->right = parent->left;
              parent->left = grandparent;
              if (grandgrand->left == grandparent) {
                grandgrand->left = parent;
              } else {
                grandgrand->right = parent;
              }
              grandparent->parent = parent;
              parent->parent = grandgrand;
              parent->level++;
              Skew(grandgrand);
              Split(parent->parent);
            }
            if (root_ == grandparent) {
              grandparent->right = parent->left;
              parent->left = grandparent;
              parent->level++;
              grandparent->parent = parent;
              parent->parent = nullptr;
              root_ = parent;
            }
          }
        }
      }
       */
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
        if (current->left != NULL) {
          int left = current->left->value;
          cout << left;
        }
        cout << " | Right ";
        if (current->right !=NULL){
          int right = current->right->value;
          cout << right;
        }
        cout << " | Parent ";
        if (current->parent != NULL){
          int parent = current->parent->value;
          cout << parent;
        }
        cout << endl;
        if(current->left != nullptr)Print(current->left);
        if(current->right != nullptr)Print(current->right);
  }

  void AATree::Print1(Node* current) {
    if (current != nullptr) {
      cout << "Level ";
      cout << current->level;
      cout << " | Value = ";
      cout << current->value;
      cout << " | Left ";
      if (current->left != NULL) {
        int left = current->left->value;
        cout << left;
      }
      cout << " | Right ";
      if (current->right != NULL) {
        int right = current->right->value;
        cout << right;
      }
      cout << endl;
    }
  }
}  // namespace itis