#include <list> // подключаем list
#include <string> // подключаем строки string
#include <iostream> // подключаем cout

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
    
        list<string> Spisok; // инициализация list
 
        Spisok.push_back("Nikolay");    // IVT
        Spisok.push_back("Ignat");      // IVT
        Spisok.push_back("Danil");      // IVT
        Spisok.push_back("Vladimir");   // MTS
        Spisok.push_back("Egor");       // MTS
        Spisok.push_back("Nikita");     // MTS
        Spisok.push_back("Ilya");       // AES
        Spisok.push_back("Igor");       // AES
        Spisok.push_back("Slava");      // AES
        Spisok.push_back("Konstantin"); // MRM
        Spisok.push_back("Alexandr");   // MRM
        Spisok.push_back("Ivan");       // MRM


    Students students;

    IVT ivt;
    MTS mts;
    AES aes;
    MRM mrm;

    students.print(Spisok);
    ivt.print(Spisok);
    mts.print(Spisok);
    aes.print(Spisok);
    mrm.print(Spisok);

}