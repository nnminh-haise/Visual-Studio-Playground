#pragma once

#include <iostream>
#include <string>

namespace BOOK {
	const int MAX_SIZE = 100000;

	enum Status { AVAILABLE, UNAVAILABLE, SOLD };

	class Book {
	public:
		Book();

		Book(std::string id, Status status, std::string description);

		void SetID(std::string id);

		std::string GetID();

		void SetStatus(Status status);

		Status GetStatus();

		std::string StringfyStatus();

		void SetDescription(std::string description);

		std::string GetDescription();

		void Log();

		inline friend bool operator== (const Book& bookA, const Book& bookB);

	private:
		std::string id;
		Status status;
		std::string description;
	};

	class LinkedList {
	public:
		struct Node {
			Book info;
			Node* next;
			
			Node();

			Node(Book info, Node* next);
		};

		typedef Node* Pointer;
		
	public:
		LinkedList();

		void Initialize();

		bool Empty();

		int Size();

		void InsertFirst(Book info);

		void InsertLast(Book info);

		bool Delete(Book info);

		void Log();

	private:
		int size;
		Pointer first;
	};
}

namespace BOOK_TITLE {

	class BookTitle {
	public:
		BookTitle();

		BookTitle(std::string isbn, std::string title, int pageCount, std::string author, int publiationYear, std::string category,
			BOOK::LinkedList catalogue);

		void SetISBN(std::string isbn);

		std::string GetISBN();

		void SetTitle(std::string title);

		std::string GetTitle();

		void SetPageCount(int sotrang);

		int GetPageCount();

		void SetAuthor(std::string author);

		std::string GetAuthor();

		void SetPublicationYear(int publiationYear);

		int GetPublicationYear();

		void SetCategory(std::string category);

		std::string GetCategory();

		void SetCatalogue(BOOK::LinkedList catalogue);

		BOOK::LinkedList GetCatalogue();

		void Log();

	private:
		std::string isbn;
		std::string title;
		int pageCount;
		std::string author;
		int publiationYear;
		std::string category;
		BOOK::LinkedList catalogue;
	};

	const int MAX_SIZE = 100000;

	class LinearList {
	public:
		LinearList();

		int Size();

		BookTitle*& operator[] (int index);

		void Initialize();

		bool IsEmpty();

		bool IsFull();

		bool Insert(BookTitle* newObject, int index = -1);

		BookTitle* Remove(int index);

		void Print(const std::string& message = "List");

	private:
		int size;
		BookTitle* nodes[MAX_SIZE]{};
	};
}
