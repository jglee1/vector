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

void print_book(const vector<Entry>& book)
{
   // for (int i = 0; i!=book.size(); ++i)
   // {
   //    cout << book[i] << '\n';
   // }

      for (const auto& x:book)
          cout << x << '\n';
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<Entry> phone_book = {
        {"David Hume", 123456},
        {"Karl Popper", 234567},
        {"Bertrand Arthur William Russell", 345678}
    };

    print_book(phone_book);

    return a.exec();
}
