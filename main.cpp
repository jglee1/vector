#include <QCoreApplication>
#include <iostream>

using namespace std;

struct Entry {
    string name;
    int number;
};

ostream& operator<<(ostream& os, const Entry& e)
{
    return os << "{\"" << e.name << "\", " <<
           e.number << "}";
}

istream& operator>>(istream& is, Entry& e)
{
    char c, c2;
    if (is>>c && c=='{' && is>>c2 && c2=='"') {
        string name;
        while(is.get(c) && c!='"')
            name+=c;
        if(is>>c && c==',') {
            int number = 0;
            if(is>>number>>c && c=='}')  {
                e.name = name;
                e.number= number;
                return is;
            }
        }
    }
    is.setf(ios_base::failbit);
    return is;
}


void print_book(const vector<Entry>& book)
{
   // for (int i = 0; i!=book.size(); ++i)
   // {
   //    cout << book[i] << '\n';
   // }

      for (const auto& x:book)
          cout << x << '\n';
}

void input(vector<Entry>& phone_book)
{
    for (Entry e; cin>>e;)
        phone_book.push_back(e);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<Entry> phone_book(3);
 //   phone_book[0] = {"David Hume", 123456};
//
//        {"Karl Popper", 234567},
//        {"Bertrand Arthur William Russell", 345678}

    phone_book[0].name = "Karl Popper";
    phone_book[0].number = 123456;

    print_book(phone_book);

    vector<Entry> book2 = phone_book;
    print_book(book2);

    input(book2);
    print_book(book2);
    return a.exec();
}
