#include "BinarySearchTree.h"
#include "Stack.h"

namespace BINARY_SEARCH_TREE {

	namespace AVL_TREE {
        Node::Node() {
            this->key = -1;
            this->info = 0;
            this->balanceFactor = 0;
            this->left = this->right = nullptr;
        }

        Node::Node(int key, int info, int balanceFactor, Node* left, Node* right) {
            this->key = key;
            this->info = info;
            this->balanceFactor = balanceFactor;
            this->left = left;
            this->right = right;
        }

        void Initialize(Pointer& root) {
            root = nullptr;
        }

        bool IsEmpty(const Pointer& root) {
            return root == nullptr;
        }

        void InsertNode(Pointer& node, int key, int info) {
            if (node == nullptr) {
                node = new Node(key, info, 0, nullptr, nullptr);
            }
            else {
                if (key < node->key) {
                    InsertNode(node->left, key, info);
                }
                else if (key > node->key) {
                    InsertNode(node->right, key, info);
                }
                else {
                    std::cerr << "[ERROR] DUPLICATED KEY!\n";
                }
            }
        }

        void CreateTree(Pointer& root) {
            int key, info;
            do {
                std::cerr << "Enter node's key: ";
                std::cin >> key;

                if (key != 0) {
                    std::cerr << "Enter node's info: ";
                    std::cin >> info;
                    InsertNode(root, key, info);
                }
            } while (key != 0);
        }

        void InterchangeLeftMostNode(Pointer& root, Pointer& removeNode) {
            if (root->left != nullptr) {
                InterchangeLeftMostNode(root->left, removeNode);
            }
            else {
                removeNode->key = root->key;
                removeNode->info = root->key;
                removeNode = root;
                root = removeNode->right;
            }
        }

        void RemoveNode(Pointer& node, int key) {
            if (node == nullptr) {
                std::cerr << "[ERROR] CANNOT FIND KEY " << key << std::endl;
            }
            else {
                if (key < node->key) {
                    RemoveNode(node->left, key);
                }
                else if (key > node->key) {
                    RemoveNode(node->right, key);
                }
                else {
                    Pointer removeNode = node;
                    if (removeNode->left == nullptr) {
                        node = removeNode->right;
                    }
                    else if (removeNode->right == nullptr) {
                        node = removeNode->left;
                    }
                    else {
                        InterchangeLeftMostNode(node->right, removeNode);
                    }
                    delete removeNode;
                }
            }
        }

        Pointer Search(Pointer const& root, int key) {
            Pointer p = root;
            while (p != nullptr && p->key != key) {
                if (p->key < key) {
                    p = p->right;
                }
                else {
                    p = p->left;
                }
            }
            return p;
        }

        void PreOrderTraversal(Pointer const& root) {
            if (root != nullptr) {
                std::clog << root->key << " ";
                PreOrderTraversal(root->left);
                PreOrderTraversal(root->right);
            }
        }

        void InOrderTraversal(Pointer const& root) {
            if (root != nullptr) {
                InOrderTraversal(root->left);
                std::clog << root->key << " ";
                InOrderTraversal(root->right);
            }
        }

        void PostOrderTraversal(Pointer const& root) {
            if (root != nullptr) {
                InOrderTraversal(root->left);
                InOrderTraversal(root->right);
                std::clog << root->key << " ";
            }
        }

        Pointer RotateLeft(Pointer root) {
            if (root == nullptr) {
                std::cerr << "[ERROR] TREE IS EMPTY!\n";
                return nullptr;
            }

            if (root->right == nullptr) {
                std::cerr << "[ERROR] CANNOT ROTATE LEFT BECAUSE THERE IS NO RIGHT TREE!\n";
                return nullptr;
            }

            Pointer p = root->right;
            root->right = p->left;
            p->left = root;

            return p;
        }

        Pointer RotateRight(Pointer root) {
            if (root == nullptr) {
                std::cerr << "[ERROR] TREE IS EMPTY!\n";
                return nullptr;
            }

            if (root->left == nullptr) {
                std::cerr << "[ERROR] CANNOT ROTATE RIGHT BECAUSE THERE IS NO LEFT TREE!\n";
                return nullptr;
            }

            Pointer s = root->left;
            root->left = s->right;
            s->right = root;
            return s;
        }

        /**
         * This method is written in the non-recursive way!
        */
        bool Insert(Pointer& root, int key, int info) {

            /*
             * currentNode represent the node which is being manipulated.
             * currentNodeParent is the parent node of the currentNode.
             * currentNodeChild is the child of the currentNode.
             * imbalancedNode is the node before the currentNode which can be an imbalanced node in the AVL Tree.
             * imbalancedNodeParent is the parent of the imbalancedNode.
             * imbalancedNodeChild is the child node of imbalancedNode which could be imbalanced in the AVL Tree.
            */

            Pointer currentNode = root;
            Pointer currentNodeParent = nullptr;
            Pointer currentNodeChild = nullptr;
            Pointer imbalancedNode = currentNode;
            Pointer imbalancedNodeParent = nullptr;
            Pointer imbalancedNodeChild = nullptr;

            int imbalancedFactor = 0;

            /*
            * We first find the parent node of the currentNode.
            * Fint the imbalancedNode, the parent of the imbalancedNode.
            */
            while (currentNode != nullptr) {

                //* If the parameterized key is similar with the currentNode's key, then the parameterized key is not valid.
                if (key == currentNode->key) {
                    return false;
                }

                //* If the parameterized key is smaller than the currentNode's key, then we move to the left child tree of the currentNode.
                if (key < currentNode->key) {
                    currentNodeChild = currentNode->left;
                }
                //* Otherwise we move to the right child tree of the currentNode.
                else {
                    currentNodeChild = currentNode->right;
                }

                //! This if statement logic can be rewrite.
                if (currentNodeChild != nullptr) {
                    //* If the currentNode's child is an imbalanced node.
                    if (currentNodeChild->balanceFactor != 0) {
                        imbalancedNodeParent = currentNode;
                        imbalancedNode = currentNodeChild;
                    }
                }

                currentNodeParent = currentNode;
                currentNode = currentNodeChild;
            }

            /*
             * Add a new node with the parameterized key and info as a child node of the currentNodeParent.
            */
            currentNodeChild = new Node(key, info, 0, nullptr, nullptr);
            currentNodeChild->left = currentNodeChild->right = nullptr;
            if (key < currentNodeParent->key) {
                currentNodeParent->left = currentNodeChild;
            }
            else {
                currentNodeParent->right = currentNodeChild;
            }

            /*
             * We modify the balance factor of all the node between the imbalenced node and the currentNodeChild.
             * If they were to the left, then all the balance factor of them are 1 and -1 in the otherhand.
            */
            if (key < imbalancedNode->key) {
                currentNode = imbalancedNode->left;
            }
            else {
                currentNode = imbalancedNode->right;
            }
            imbalancedNodeChild = currentNode;
            while (currentNode != currentNodeChild) {
                if (key < currentNode->key) {
                    currentNode->balanceFactor = 1;
                    currentNode = currentNode->left;
                }
                else {
                    currentNode->balanceFactor = -1;
                    currentNode = currentNode->right;
                }
            }

            /*
             * Detecting the imbalanced direction, which means that the tree is left heavy or right heavy.
            */
            if (key < imbalancedNode->key) {
                imbalancedFactor = 1; //* Left heavy
            }
            else {
                imbalancedFactor = -1; //* Right heavy
            }

            if (imbalancedNode->balanceFactor == 0) {
                imbalancedNode->balanceFactor = imbalancedFactor;
                return false;
            }

            if (imbalancedNode->balanceFactor != imbalancedFactor) {
                imbalancedNode->balanceFactor = 0;
                return false;
            }

            /*
             * After inserting a new node, if the tree is imbalanced, we will balance it again.
             * Case where we only need to rotate once.
            */
            if (imbalancedNodeChild->balanceFactor == imbalancedFactor) {

                //* Rotate right
                if (imbalancedFactor == 1) {
                    currentNode = RotateRight(imbalancedNode);
                }
                //* rotate left
                else {
                    currentNode = RotateLeft(imbalancedNode);
                }

                imbalancedNode->balanceFactor = 0;
                imbalancedNodeChild->balanceFactor = 0;
            }
            //* Case where we need to rotate twice
            else {
                //* Rotate Left and Right
                if (imbalancedFactor == 1) {
                    imbalancedNode->left = RotateLeft(imbalancedNodeChild);
                    currentNode = RotateRight(imbalancedNode);
                }
                //* Rotate Right and Left
                else {
                    imbalancedNode->right = RotateRight(imbalancedNodeChild);
                    currentNode = RotateLeft(imbalancedNode);
                }

                //* If p is the inserted node
                if (currentNode->balanceFactor == 0) {
                    imbalancedNode->balanceFactor = 0;
                    imbalancedNodeChild->balanceFactor = 0;
                }
                else {
                    if (currentNode->balanceFactor == imbalancedFactor) {
                        imbalancedNode->balanceFactor = -imbalancedFactor;
                        imbalancedNodeChild->balanceFactor = 0;
                    }
                    else {
                        imbalancedNode->balanceFactor = 0;
                        imbalancedNodeChild->balanceFactor = imbalancedFactor;
                    }
                }
                currentNode->balanceFactor = 0;
            }

            if (imbalancedNodeParent == nullptr) {
                root = currentNode;
            }
            else {
                if (imbalancedNode == imbalancedNodeParent->right) {
                    imbalancedNodeParent->right = currentNode;
                }
                else {
                    imbalancedNodeParent->left = currentNode;
                }
            }

            return true;
        }

        void CountNode(Pointer const& root, int& counter) {
            if (root != nullptr) {
                ++counter;
                CountNode(root->left, counter);
                CountNode(root->right, counter);
            }
        }

        void NonrecursiveInOrderTraversal(const Pointer& root) {
            STACK::Stack stk;
            STACK::Initialize(stk);

            Pointer p = root;
            do {
                while (p != nullptr) {
                    STACK::Push(stk, p);
                    p = p->left;
                }

                if (STACK::IsEmpty(stk) == false) {
                    p = STACK::Pop(stk);
                    std::cout << p->info << " ";
                    p = p->right;
                }
                else {
                    break;
                }
            } while (true);
            std::cout << "\n";
        }

        void AssignToArr(const Pointer& root, int* arr) {
            STACK::Stack stk;
            STACK::Initialize(stk);

            Pointer p = root;
            int index = 0;
            do {
                arr[index++] = p->info;

                if (p->right != nullptr) {
                    STACK::Push(stk, p->right);
                }
                if (p->left != nullptr) {
                    p = p->left;
                }
                else if (STACK::IsEmpty(stk)) {
                    break;
                }
                else {
                    p = STACK::Pop(stk);
                }
            } while (true);
        }
	}
}
