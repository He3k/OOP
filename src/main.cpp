#include <list> 
#include <string> 
#include <iostream> 

using namespace std;

class Show{ // abstruct class
    public:
        virtual void speak() = 0;
};

class Students : public Show { // inheritance
    private:
        list<string>::iterator i;
    public:
	void speak()
    	{
        	cout << ":::::::::::" <<  endl;
    	}
        char* k="All";
        Students(); // constructor
        Students(int x); // constructor with element
        int print(list<string> Spisok){
            cout << "Students" << "\n";
            for(i = Spisok.begin(); i != Spisok.end(); i++)
            cout << (*i) << "\n";
        }
};

Students::Students(){ // constructor
    cout << "";
}
Students::Students(int x){ // constructor with element
    cout << "\n" << "------------------" << "\n";
}

class IVT : public Students{ // inheritance
    private:
        list<string>::iterator i, pe;
    public:
	void speak()
    	{
        	cout << "+++++++++++" <<  endl;
    	}      
        int print(list<string> Spisok){
            cout << "\n" << "IVT" << "\n";
            pe = Spisok.begin();
            advance(pe,3);
            for(i = Spisok.begin(); i != pe; i++)
                cout << (*i) << "\n";
            cout << (k);
        }
};


class MTS : public Students{ // inheritance
    private:
        list<string>::iterator i, pb, pe;
    public:
	void speak()
    	{
        	cout << "===========" <<  endl;
    	}
        int print(list<string> Spisok){
            cout << "\n" << "MTS" << "\n";
            pb = Spisok.begin();
            advance(pb,3);
            pe = Spisok.begin();
            advance(pe,6);
            for(i = pb; i != pe; i++)
                cout << (*i) << "\n";
            cout << (k);
        }
};
class AES : public Students{ // inheritance
    private:
        list<string>::iterator i, pb, pe;
    public:
	void speak()
    	{
        	cout << "+++++++++++" <<  endl;
    	}
        int print(list<string> Spisok){
            cout << "\n" << "AES" << "\n";
            pb = Spisok.begin();
            advance(pb,6);
            pe = Spisok.begin();
            advance(pe,9);
            for(i = pb; i != pe; i++)
                cout << (*i) << "\n";
            cout << (k) << "\n";
        }
};

class MRM : public Students{ // inheritance
    private:
        list<string>::iterator i, pb, pe;
    public:
	void speak()
    	{
        	cout << "===========" <<  endl;
    	}
        int print(list<string> Spisok){
            cout << "\n" << "MRM" << "\n";
            pb = Spisok.begin();
            advance(pb,9);
            pe = Spisok.begin();
            advance(pe,12);
            for(i = pb; i != pe; i++)
                cout << (*i) << "\n";
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
    MTS mts;
    AES aes;
    MRM mrm;

    //Show show;

    int i;
    while (i != 9){
        cout << "\n" << "Please choise option ";
        cout << "\n"<< "0) Students" << "\n" << "1) IVT" << "\n" << "2) MTS" 
        << "\n" << "3) AES" << "\n" << "4) MRM" << "\n" << "9) exit" << "\n";
        cin >> i;
        if(i == 0){
	    students.speak();
            Students ob1;
            students.print(Spisok);
            Students ob2(1);
        }
        else if (i == 1){
	    ivt.speak();
            Students ob1;
            ivt.print(Spisok);
            Students ob2(1);
        }
        else if (i == 2){
	    mts.speak(); 
            Students ob1;
            mts.print(Spisok);
            Students ob2(1);
        }
        else if (i == 3){
	    aes.speak();
            Students ob1;
            aes.print(Spisok);
            Students ob2;
        }
        else if (i == 4){
	    mrm.speak();
            Students ob1;
            mrm.print(Spisok);
            Students ob2(1);
        }    
    }
}
