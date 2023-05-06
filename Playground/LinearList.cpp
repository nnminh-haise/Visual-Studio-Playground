//
//#include "LinearList.h"
//#include "iostream"
//#include "string"
//
//
//
//BOOK::LinearList::LinearList() {
//    this->size = 0;
//    this->nodes = nullptr;
//}
//
//int BOOK::LinearList::Size() {
//    return this->size;
//}
//
//Book*& BOOK::LinearList::operator[] (int index) {
//    if (index < 0 || index > this->size) {
//        std::cerr << "[ERROR] LINEAR LIST - Index access out of range!\n";
//        exit(1);
//    }
//
//    return this->nodes[index];
//}
//
//void BOOK::LinearList::Initialize(int size) {
//    this->size = size;
//    this->nodes = new int*[size + 1];
//    for (int i = 0; i <= size; ++i) {
//        this->nodes[i] = nullptr;
//    }
//}
//
//bool BOOK::LinearList::IsEmpty() {
//    return this->size == 0;
//}
//
//bool BOOK::LinearList::IsFull() {
//    return this->size == BOOK::MAX_SIZE;
//}
//
//bool BOOK::LinearList::Insert(Book* newObject, int index) {
//    if (this->IsFull()) {
//        std::cerr << "[ERROR] LINEAR LIST - List full!\n";
//        return false;
//    }
//
//    if (index < 0 || index > this->size) {
//        std::cerr << "[ERROR] LINEAR LIST - Index access out of range!\n";
//        return false;
//    }
//
//    if (index == 0) {
//        this->size += 1;
//        this->nodes[this->size] = newObject;
//        return true;
//    }
//
//    for (int i = this->size + 1; i > index; --i) {
//        this->nodes[i] = this->nodes[i - 1];
//    }
//
//    this->nodes[index] = newObject;
//    this->size += 1;
//
//    return true;
//}
//
//Book* BOOK::LinearList::Remove(int index) {
//    if (this->IsFull()) {
//        std::cerr << "[ERROR] LINEAR LIST - List full!\n";
//        return nullptr;
//    }
//
//    if (index < 0 || index > this->size) {
//        std::cerr << "[ERROR] LINEAR LIST - Index access out of range!\n";
//        return nullptr;
//    }
//
//    int* returnObject = this->nodes[index];
//
//    for (int i = index; i < this->size; ++i) {
//        this->nodes[i] = this->nodes[i + 1];
//    }
//
//    delete this->nodes[this->size];
//    this->size -= 1;
//
//    return returnObject;
//}
//
//void BOOK::LinearList::Print(const std::string& message) {
//    std::cout << message << ": [";
//    for (int i = 1; i <= this->size; ++i) {
//        
//    }
//}
//
//
//
//
