#include <list> 
#include <string> 
#include <iostream> 

using namespace std;

class Show{ // abstruct class
    public:
        virtual const char* speak() { return "-"; }
};
class Students : public Show { // inheritance
    private:
        list<string>::iterator i;
    public:
        char* k="All";
        Students(); // constructor
        Students(int x); // constructor with element
        int print(list<string> Spisok){
            cout << "Students" << "\n";
            for(i = Spisok.begin(); i != Spisok.end(); i++)
            cout << speak() << (*i) << "\n";
        }
};

Students::Students(){ // constructor
    cout << "" << "\n";
}
Students::Students(int x){ // constructor with element
    cout << "\n" << "------------------" << "\n";
}

class IVT : public Students{ // inheritance
    private:
        list<string>::iterator i, pe;
    public:       
        int print(list<string> Spisok){
            cout << "\n" << "IVT" << "\n";
            pe = Spisok.begin();
            advance(pe,3);
            for(i = Spisok.begin(); i != pe; i++)
                cout << speak() << (*i) << "\n";
            cout << (k);
        }
};


class MTS : public Students{ // inheritance
    private:
        list<string>::iterator i, pb, pe;
    public:
        int print(list<string> Spisok){
            cout << "\n" << "MTS" << "\n";
            pb = Spisok.begin();
            advance(pb,3);
            pe = Spisok.begin();
            advance(pe,6);
            for(i = pb; i != pe; i++)
                cout << speak() << (*i) << "\n";
            cout << (k);
        }
};
class AES : public Students{ // inheritance
    private:
        list<string>::iterator i, pb, pe;
    public:
        int print(list<string> Spisok){
            cout << "\n" << "AES" << "\n";
            pb = Spisok.begin();
            advance(pb,6);
            pe = Spisok.begin();
            advance(pe,9);
            for(i = pb; i != pe; i++)
                cout << speak() << (*i) << "\n";
            cout << (k) << "\n";
        }
};

class MRM : public Students{ // inheritance
    private:
        list<string>::iterator i, pb, pe;
    public:
        int print(list<string> Spisok){
            cout << "\n" << "MRM" << "\n";
            pb = Spisok.begin();
            advance(pb,9);
            pe = Spisok.begin();
            advance(pe,12);
            for(i = pb; i != pe; i++)
                cout << speak() << (*i) << "\n";
            cout << (k) << "\n";
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

    Students students; // object
    IVT ivt; // object
    Show show;
    MTS mts;
    AES aes;
    MRM mrm;

    //Students ob1;
    //students.print(Spisok);
    //Students ob2(1);

    //ivt.print(Spisok);
    //cout << show.speak();
    
    //mts.print(Spisok);
    //aes.print(Spisok);
    //mrm.print(Spisok);
    
    
    int i;
    while (i != 9){
        cout << "\n" << "Please choise option ";
        cout << "\n"<< "0) Students" << "\n" << "1) IVT" << "\n" << "2) MTS" 
        << "\n" << "3) AES" << "\n" << "4) MRM" << "\n" << "9) exit" << "\n";
        cin >> i;
        if(i == 0){
            Students ob1;
            students.print(Spisok);
            Students ob2(1);
        }
        else if (i == 1){
            Students ob1;
            ivt.print(Spisok);
            Students ob2(1);
        }
        else if (i == 2){ 
            Students ob1;
            mts.print(Spisok);
            Students ob2(1);
        }
        else if (i == 3){
            Students ob1;
            aes.print(Spisok);
            Students ob2;
        }
        else if (i == 4){
            Students ob1;
            mrm.print(Spisok);
            Students ob2(1);
        }    
    }
}
