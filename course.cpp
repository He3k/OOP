#include <list> 
#include <string> 
#include <iostream> 

using namespace std;

class Students {
    public:
        list<string>::iterator i;
        int print(list<string> Spisok){
            cout << "\n" << "Students" << "\n";
            for(i = Spisok.begin(); i != Spisok.end(); i++)
            cout << (*i) << "\n";
        }
};
class IVT{
    public:       
        int j=0;
        list<string>::iterator i, pe;
        int print(list<string> Spisok){
            cout << "\n"<< "IVT" << "\n";
            pe = Spisok.begin();
            advance(pe,3);
            for(i = Spisok.begin(); i != pe; i++)
            cout << (*i) << "\n";
        }
};
class MTS{
    public:
        int j=0;
        list<string>::iterator i, pb, pe;
        int print(list<string> Spisok){
            cout << "\n" << "MTS" << "\n";
            pb = Spisok.begin();
            advance(pb,3);
            pe = Spisok.begin();
            advance(pe,6);
            for(i = pb; i != pe; i++)
            cout << (*i) << "\n";
        }
};
class AES{
    public:
        int j=0;
        list<string>::iterator i, pb, pe;
        int print(list<string> Spisok){
            cout << "\n" << "AES" << "\n";
            pb = Spisok.begin();
            advance(pb,6);
            pe = Spisok.begin();
            advance(pe,9);
            for(i = pb; i != pe; i++)
            cout << (*i) << "\n";
        }
};
class MRM{
    public:
        int j=0;
        list<string>::iterator i, pb, pe;
        int print(list<string> Spisok){
            cout << "\n" << "MRM" << "\n";
            pb = Spisok.begin();
            advance(pb,9);
            for(i = pb; i != Spisok.end(); i++)
            cout << (*i) << "\n";
        }
};

int main(){   
    list<string> Spisok; // init list
 
    Spisok.push_back("Nikolay");    // IVT
    Spisok.push_back("Ignat");      // IVT
    Spisok.push_back("Danil");      // IVT
    Spisok.push_back("Vladimir");   // MTS
    Spisok.push_back("Egor");       // MTS
    Spisok.push_back("Nikita");     // MTS
    Spisok.push_back("Ilya");       // AES
    Spisok.push_back("Igor");       // AES
    Spisok.push_back("Slava");      // AES
    Spisok.push_back("Ivan");       // MRM
    Spisok.push_back("Konstantin"); // MRM
    Spisok.push_back("Alexandr");   // MRM

    Students students;
    IVT ivt;
    MTS mts;
    AES aes;
    MRM mrm;

    //students.print(Spisok);
    //ivt.print(Spisok);
    //mts.print(Spisok);
    //aes.print(Spisok);
    //mrm.print(Spisok);
    int i;

    while (i != 9){
        cout << "\n" << "Please choise option ";
        cout << "\n"<< "0) Students" << "\n" << "1) IVT" << "\n" << "2) MTS" 
        << "\n" << "3) AES" << "\n" << "4) MRM" << "\n" << "9) exit" << "\n";
        cin >> i;
        if(i == 0) students.print(Spisok);
        else if (i == 1) ivt.print(Spisok);
        else if (i == 2) mts.print(Spisok);
        else if (i == 3) aes.print(Spisok);
        else if (i == 4) mrm.print(Spisok);
    }
}