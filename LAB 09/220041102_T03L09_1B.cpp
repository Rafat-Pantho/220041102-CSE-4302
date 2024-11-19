#include <iostream>
#include <string>

using namespace std;


enum class CoverType {Hardcover,Paperback};

string CoverTypeToString(CoverType cover){
    return cover == CoverType::Hardcover ? "Hardcover" : "Paperback";
}

class LibraryResource{
    protected:
        string title;
        string author;
        double price;
        int copy_cnt;

    public:
        LibraryResource(string t, string a, double p,int cc=1):title(t),author(a),price(p),copy_cnt(cc){}
        virtual ~LibraryResource(){}

        void set_cc(int cc){
            copy_cnt = cc;
        }

        virtual void resourceRetails()const = 0;
};

class Book : public LibraryResource{
    CoverType cover;

    public:
        Book(string t,string a, double p, CoverType c,int cc=1):LibraryResource(t,a,p,cc),cover(c){}

        void resourceRetails()const override{
            cout<<"Title: "<<title<<endl<<"Author: "<<author<<endl<<"Price: "<<price <<endl<<"Cover type: "<<CoverTypeToString(cover)<<endl<<"No. of Copies: "<<copy_cnt<<endl;
        }
};

class EBook: public LibraryResource{
    double file_size;

    public:
        EBook(string t,string a, double p, double f,int cc=1):LibraryResource(t,a,p,cc),file_size(f){}
};

class Audiobook: public LibraryResource{
    int duration;

    public:
        Audiobook(string t,string a, double p, int d,int cc):LibraryResource(t,a,p,cc),duration(d){}
};

int main(){
    LibraryResource *resource_list[100];
    resource_list[0] = new Book("The Alchemist", "Paulo Coelho", 500, CoverType::Hardcover);
    resource_list[1] = new Book("1984", "George Orwell", 300, CoverType::Paperback);
    resource_list[2] = new Book("Becoming", "Michelle Obama", 700, CoverType::Hardcover);

    for (int i = 0; i < 3; i++) {
        resource_list[i]->resourceRetails();
    }

    resource_list[0]->set_cc(50);
    resource_list[1]->set_cc(5);
    resource_list[2]->set_cc(1);

    for (int i = 0; i < 3; i++) {
        resource_list[i]->resourceRetails();
    }


    return 0;
}
