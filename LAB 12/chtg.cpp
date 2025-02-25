#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <fstream>

using namespace std;

class Book {
private:
    string title, author, ISBN;
public:
    Book(string t, string a, string i) : title(t), author(a), ISBN(i) {}
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }
    void display() const { cout << "Title: " << title << ", Author: " << author << ", ISBN: " << ISBN << endl; }
};

class Library {
private:
    vector<Book> inventory;
    deque<Book> borrowedBooks;
    list<Book> archivedBooks;
public:
    void addBook(const string &title, const string &author, const string &ISBN) {
        inventory.emplace_back(title, author, ISBN);
    }

    bool borrowBook(const string &ISBN) {
        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            if (it->getISBN() == ISBN) {
                borrowedBooks.push_back(*it);
                inventory.erase(it);
                return true;
            }
        }
        return false;
    }

    bool returnBook(const string &ISBN) {
        for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
            if (it->getISBN() == ISBN) {
                inventory.push_back(*it);
                borrowedBooks.erase(it);
                return true;
            }
        }
        return false;
    }

    bool archiveBook(const string &ISBN) {
        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            if (it->getISBN() == ISBN) {
                archivedBooks.push_back(*it);
                inventory.erase(it);
                return true;
            }
        }
        return false;
    }

    void displayBooks() const {
        cout << "\nInventory:\n";
        for (const auto &book : inventory) book.display();
        cout << "\nBorrowed Books:\n";
        for (const auto &book : borrowedBooks) book.display();
        cout << "\nArchived Books:\n";
        for (const auto &book : archivedBooks) book.display();
    }

    void saveData() {
        ofstream invFile("inventory.txt"), borFile("borrowed.txt"), archFile("archived.txt");
        for (const auto &book : inventory) invFile << book.getTitle() << "," << book.getAuthor() << "," << book.getISBN() << "\n";
        for (const auto &book : borrowedBooks) borFile << book.getTitle() << "," << book.getAuthor() << "," << book.getISBN() << "\n";
        for (const auto &book : archivedBooks) archFile << book.getTitle() << "," << book.getAuthor() << "," << book.getISBN() << "\n";
    }

    void loadData() {
        ifstream invFile("inventory.txt"), borFile("borrowed.txt"), archFile("archived.txt");
        string title, author, ISBN;
        inventory.clear(); borrowedBooks.clear(); archivedBooks.clear();
        while (getline(invFile, title, ',') && getline(invFile, author, ',') && getline(invFile, ISBN))
            inventory.emplace_back(title, author, ISBN);
        while (getline(borFile, title, ',') && getline(borFile, author, ',') && getline(borFile, ISBN))
            borrowedBooks.emplace_back(title, author, ISBN);
        while (getline(archFile, title, ',') && getline(archFile, author, ',') && getline(archFile, ISBN))
            archivedBooks.emplace_back(title, author, ISBN);
    }
};

int main() {
    Library lib;
    lib.addBook("C++ Primer", "Lippman", "12345");
    lib.addBook("Effective C++", "Meyers", "67890");
    lib.displayBooks();
    
    lib.borrowBook("12345");
    lib.displayBooks();
    
    lib.returnBook("12345");
    lib.displayBooks();
    
    lib.archiveBook("67890");
    lib.displayBooks();
    
    lib.saveData();
    lib.loadData();
    lib.displayBooks();
    
    return 0;
}
