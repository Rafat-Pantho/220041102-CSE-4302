#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <deque>
#include <fstream>

using namespace std;

class Book{
    private:
        string title, author, ISBN;

    public:
        Book(): title(""),author(""),ISBN(""){}
        Book(string title1, string author1, string ISBN1): title(title1), author(author1), ISBN(ISBN1){}

        string getTitle() const {return title;}
        string getAuthor() const {return author;}
        string getISBN() const {return ISBN;}
        void display() const{
            cout<<"Title: "<<title<<"\nAuthor: "<<author<<"\nISBN: "<<ISBN<<endl;
        }

        ~Book(){}
};

class Library{
    private:
        vector <Book> inventory;
        deque <Book> borrowed_books;
        list <Book> archiveed_books;

    public:
        void addBooks(const string &title, const string & author, const string &isbn){
            inventory.push_back(Book(title,author,isbn));
        }

        void borrowBook(const string &isbn){
            if(inventory.empty()){
                cout<<"No books available in the library."<<endl;
                return;
            }
            for (auto it = inventory.begin(); it!=inventory.end();it++){
                if (it->getISBN()==isbn){
                    borrowed_books.push_back(*it);
                    inventory.erase(it);
                    cout<<"The book borrow complete!"<<endl;
                    return;
                }
            }
            cout<<"The book borrow is not possible!"<<endl;
        }

        void returnBook(const string &isbn){
            for(auto x = borrowed_books.begin(); x != borrowed_books.end(); x++){
                if(x->getISBN() == isbn){
                    inventory.push_back(*x);
                    borrowed_books.erase(x);
                    cout<<"The book return complete!"<<endl;
                    return;
                }
            }
            cout<< "Wrong library!" <<endl;
        }

        void archiveBook(const string &isbn){
            if(inventory.empty()){
                cout<<"The library was just founded."<<endl;
                return;
            }
            for(auto x = inventory.begin(); x != inventory.end(); x++){
                if(x->getISBN() == isbn){
                    archiveed_books.push_back(*x);
                    inventory.erase(x);
                    cout<<"The book archive complete!"<<endl;
                    return;
                }
            }
            cout<< "Invalid ISBN"<<endl;
        }

        void displayBooks() const{
            cout << "Inventory books:" << endl;
            for (const auto &book : inventory) book.display();
            cout << "Borrowed books:" << endl;
            for (const auto &book : borrowed_books) book.display();
            cout << "Archive books:" << endl;
            for (const auto &book : archiveed_books) book.display();
        }

        void saveData(){
            ofstream inv("inventory.txt"), bowbo("borrowed.txt"), arcbo("archived.txt");
            for(auto book: inventory) inv<< book.getTitle()<<","<<book.getAuthor()<<","<<book.getISBN()<<endl;
            for(auto book: borrowed_books) bowbo<< book.getTitle()<<","<<book.getAuthor()<<","<<book.getISBN()<<endl;
            for(auto book: archiveed_books) arcbo<< book.getTitle()<<","<<book.getAuthor()<<","<<book.getISBN()<<endl;
        }

        void loadData(){
            ifstream inv("inventory.txt"), bowbo("borrowed.txt"), arcbo("archived.txt");
            string title, author, isbn;
            while(getline(inv, title, ',')&& getline(inv, author,',')&&getline(inv,isbn))inventory.push_back(Book(title,author, isbn));
            while(getline(bowbo, title, ',')&& getline(bowbo, author,',') && getline(bowbo, isbn)) borrowed_books.push_back(Book(title,author, isbn));
            while(getline(arcbo, title, ',')&& getline(arcbo, author,',') && getline(arcbo, isbn)) archiveed_books.push_back(Book(title,author, isbn));
        }
};

void options(){
    cout<<"1. Add Book\n2. Borrow Book\n3. Return Book\n4. Archive Book\n5. Display Books\n6. Save Data\n7. Load Data\n8. Exit"<<endl;
}

int main(){
    Library library;
    int comand;
    options();
    while(cin>>comand and comand!=8){
        if(comand == 1){
            string t,a,i;
            cout<<"Input Title: ";cin>>t;
            cout<<"Input Author: ";cin>>a;
            cout<<"Input ISBN: "; cin>>i;
            library.addBooks(t,a,i);
            options();
        }
        else if(comand == 2){
            string i;
            cout<<"Input ISBN: "; cin>>i;
            library.borrowBook(i);
            options();
        }
        else if(comand == 3){
            string i;
            cout<<"Input ISBN: "; cin>>i;
            library.returnBook(i);
            options();
        }
        else if (comand == 4){
            string i;
            cout<<"Input ISBN: "; cin>>i;
            library.archiveBook(i);
            options();
        }
        else if(comand == 5){
            library.displayBooks();
            options();
        }
        else if(comand == 6){
            library.saveData();
            options();
        }
        else if(comand==7){
            library.loadData();
            options();
        }
    }
    return 0;
}