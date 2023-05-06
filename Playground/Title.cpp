#include "Title.h"

BOOK::Book::Book() {
    this->id = std::string();
    this->status = BOOK::Status::AVAILABLE;
    this->description = std::string();
}

BOOK::Book::Book(std::string id, BOOK::Status status, std::string description) {
    this->id = id;
    this->status = status;
    this->description = description;
}

void BOOK::Book::SetID(std::string id) {
    this->id = id;
}

std::string BOOK::Book::GetID() {
    return this->id;
}

void BOOK::Book::SetStatus(Status status) {
    this->status = status;
}

BOOK::Status BOOK::Book::GetStatus() {
    return this->status;
}

std::string BOOK::Book::StringfyStatus() {
    switch (this->status) {
        case(BOOK::Status::AVAILABLE):
            return "AVAILABLE";
        case(BOOK::Status::UNAVAILABLE):
            return "UNAVAILABLE";
        case(BOOK::Status::SOLD):
            return "SOLD";
    }
    return std::string();
}

void BOOK::Book::SetDescription(std::string description) {
    this->description = description;
}

std::string BOOK::Book::GetDescription() {
    return this->description;
}

void BOOK::Book::Log() {
    std::cout << "__BOOK INFO__\n";
    std::cout << "|         ID: " << this->id << "\n";
    std::cout << "|     Status: " << this->StringfyStatus() << "\n";
    std::cout << "|Description: " << this->description << "\n";
    std::cout << "+-----------+\n";
}

bool BOOK::operator==(const Book& bookA, const Book& bookB) {
    return bookA.id.compare(bookB.id) == 0;
}


BOOK::LinkedList::Node::Node() {
    this->info = BOOK::Book();
    this->next = nullptr;
}

BOOK::LinkedList::Node::Node(Book info, Node* next) {
    this->info = info;
    this->next = next;
}

BOOK::LinkedList::LinkedList() {
    this->size = 0;
    this->first = nullptr;
}

void BOOK::LinkedList::Initialize() {
    this->size = 0;
    this->first = nullptr;
}

bool BOOK::LinkedList::Empty() {
    return this->first == nullptr;
}

int BOOK::LinkedList::Size() {
    return this->size;
}

void BOOK::LinkedList::InsertFirst(Book info) {
    BOOK::LinkedList::Pointer newNode = new BOOK::LinkedList::Node(info, this->first);
    this->first = newNode;
    this->size += 1;
}

void BOOK::LinkedList::InsertLast(Book info) {
    if (this->Empty()) {
        this->InsertFirst(info);
        return;
    }

    BOOK::LinkedList::Pointer lastNode = this->first;
    for (; lastNode->next != nullptr; lastNode = lastNode->next);
    BOOK::LinkedList::Pointer newNode = new BOOK::LinkedList::Node(info, nullptr);
    lastNode->next = newNode;
    this->size += 1;
}

bool BOOK::LinkedList::Delete(Book info) {
    if (this->Empty()) {
        return false;
    }

    if (this->first->info == info) {
        this->size -= 1;
        BOOK::LinkedList::Pointer deleteNode = this->first;
        this->first = this->first->next;
        delete deleteNode;
        return true;
    }

    BOOK::LinkedList::Pointer currentNode = this->first;
    for (; currentNode->next != nullptr && currentNode->next->info != info; currentNode = currentNode->next);
    if (currentNode->next == nullptr) {
        return false;
    }

    BOOK::LinkedList::Pointer deleteNode = currentNode->next;
    currentNode->next = deleteNode->next;
    delete deleteNode;
    return true;
}

void BOOK::LinkedList::Log() {
    for (BOOK::LinkedList::Pointer currentNode = this->first; currentNode != nullptr; currentNode = currentNode->next) {
        currentNode->info.Log();
    }
}

BOOK_TITLE::BookTitle::BookTitle() {
    this->isbn = std::string();
    this->title = std::string();
    this->pageCount = 0;
    this->author = std::string();
    this->publiationYear = 0;
    this->category = std::string();
    this->catalogue.Initialize();
}

BOOK_TITLE::BookTitle::BookTitle(std::string isbn, std::string title, int pageCount, std::string author, int publiationYear, std::string category, BOOK::LinkedList catalogue) {
    this->isbn = isbn;
    this->title = title;
    this->pageCount = pageCount;
    this->author = author;
    this->publiationYear = publiationYear;
    this->category = category;
    this->catalogue = catalogue;
}

void BOOK_TITLE::BookTitle::SetISBN(std::string isbn) {
    this->isbn = isbn;
}

std::string BOOK_TITLE::BookTitle::GetISBN() {
    return this->isbn;
}

void BOOK_TITLE::BookTitle::SetTitle(std::string title) {
    this->title = title;
}

std::string BOOK_TITLE::BookTitle::GetTitle() {
    return this->title;
}

void BOOK_TITLE::BookTitle::SetPageCount(int soTrang) {
    this->pageCount = soTrang;
}

int BOOK_TITLE::BookTitle::GetPageCount() {
    return this->pageCount;
}

void BOOK_TITLE::BookTitle::SetAuthor(std::string author) {
    this->author = author;
}

std::string BOOK_TITLE::BookTitle::GetAuthor() {
    return this->author;
}

void BOOK_TITLE::BookTitle::SetPublicationYear(int publiationYear) {
    this->publiationYear = publiationYear;
}

int BOOK_TITLE::BookTitle::GetPublicationYear() {
    return this->publiationYear;
}

void BOOK_TITLE::BookTitle::SetCategory(std::string category) {
    this->category = category;
}

std::string BOOK_TITLE::BookTitle::GetCategory() {
    return this->category;
}

void BOOK_TITLE::BookTitle::SetCatalogue(BOOK::LinkedList catalogue) {
    this->catalogue = catalogue;
}

BOOK::LinkedList BOOK_TITLE::BookTitle::GetCatalogue() {
    return this->catalogue;
}

void BOOK_TITLE::BookTitle::Log() {
    std::cerr << "_____BOOK TITLE____\n";
    std::cerr << "|             ISBN: " << this->isbn << "\n";
    std::cerr << "|            Title: " << this->title << "\n";
    std::cerr << "|       Page count: " << this->pageCount << "\n";
    std::cerr << "|           Author: " << this->author << "\n";
    std::cerr << "| Publication year: " << this->publiationYear << "\n";
    std::cerr << "|         Category: " << this->category << "\n";
    std::cerr << "+-----------------+\n";
}

BOOK_TITLE::LinearList::LinearList() {
    this->size = 0;
    for (int i = 0; i < BOOK_TITLE::MAX_SIZE; ++i) {
        this->nodes[i] = nullptr;
    }
}

int BOOK_TITLE::LinearList::Size() {
    return this->size;
}

BOOK_TITLE::BookTitle*& BOOK_TITLE::LinearList::operator[] (int index) {
    if (index < 0 || index > this->size) {
        std::cerr << "[ERROR] LINEAR LIST - Index access out of range!\n";
        exit(1);
    }

    return this->nodes[index];
}

void BOOK_TITLE::LinearList::Initialize() {
    this->size = size;
    for (int i = 0; i < BOOK_TITLE::MAX_SIZE; ++i) {
        this->nodes[i] = nullptr;
    }
}

bool BOOK_TITLE::LinearList::IsEmpty() {
    return this->size == 0;
}

bool BOOK_TITLE::LinearList::IsFull() {
    return this->size == BOOK::MAX_SIZE;
}

bool BOOK_TITLE::LinearList::Insert(BOOK_TITLE::BookTitle* newObject, int index) {
    if (this->IsFull()) {
        std::cerr << "[ERROR] LINEAR LIST - List full!\n";
        return false;
    }

    if (index == -1) {
        this->nodes[this->size] = newObject;
        this->size += 1;
        return true;
    }

    if (index < 0 || index >= this->size) {
        std::cerr << "[ERROR] LINEAR LIST - Index access out of range!\n";
        return false;
    }

    for (int i = this->size; i > index; --i) {
        this->nodes[i] = this->nodes[i - 1];
    }
    this->nodes[index] = newObject;
    this->size += 1;
    return true;
}

BOOK_TITLE::BookTitle* BOOK_TITLE::LinearList::Remove(int index) {
    if (this->IsFull()) {
        std::cerr << "[ERROR] LINEAR LIST - List full!\n";
        return nullptr;
    }

    if (index < 0 || index > this->size) {
        std::cerr << "[ERROR] LINEAR LIST - Index access out of range!\n";
        return nullptr;
    }

    BOOK_TITLE::BookTitle* returnObject = this->nodes[index];

    for (int i = index; i < this->size; ++i) {
        this->nodes[i] = this->nodes[i + 1];
    }

    delete this->nodes[this->size];
    this->size -= 1;

    return returnObject;
}

void BOOK_TITLE::LinearList::Print(const std::string& message) {
    std::cout << message << "\n";
    for (int i = 0; i < this->size; ++i) {
        this->nodes[i]->Log();
    }
}





