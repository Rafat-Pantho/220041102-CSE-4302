#include <iostream>
#include <string>

using namespace std;

enum class CoverType {Hardcover,paperback};

class LibraryResource{
    protected:
        string title;
        string author;
        double price;

    public:
        LibraryResource(string t, string a, double p):title(t),author(a),price(p){}
        virtual ~LibraryResource(){}
};

class Book : public LibraryResource{
    CoverType cover;

    public:
        Book(string t,string a, double p, CoverType c):LibraryResource(t,a,p),cover(c){}
};

class EBook: public LibraryResource{
    double file_size;

    public:
        EBook(string t,string a, double p, double f):LibraryResource(t,a,p),file_size(f){}
};

class Audiobook: public LibraryResource{
    int duration;

    public:
        Audiobook(string t,string a, double p, int d):LibraryResource(t,a,p),duration(d){}
};

int main(){
    LibraryResource* resource_list[100];
    resource_list[0] = new Book("The Alchemist", "Paulo Coelho", 500,CoverType::Hardcover);
    resource_list[1] = new EBook("1984", "George Orwell", 300, 2.5);
    resource_list[2] = new Audiobook("Becoming", "Michelle Obama", 700, 120);

    return 0;
}