//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;

#include "../include/macierz/Matrix.hpp"

int main()
{
    Matrix m1(4);
    Matrix m2(4);
    cout<<"Po wywolaniu konstruktora"<<endl;
    m1.print();
    cout<<endl;
    m2.print();
    cout<<endl;

    for(int i=0; i<4;i++)
    {
        int l=1;
        for(int j=0;j<4;j++)
        {
            m1.set(i,j,l);
            l++;
        }
    }

    for(int i=0; i<4;i++)
    {
        int l=10;
        for(int j=0;j<4;j++)
        {
            m2.set(i,j,l);
            l--;
        }
    }

    cout<<"Po ustawieniu wartosci metoda set"<<endl;
    m1.print();
    cout<<endl;
    m2.print();
    cout<<endl;

    cout<<endl<<"Metoda get "<<endl;
    for(int i=0; i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<m1.get(i,j);
            cout<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    for(int i=0; i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<m2.get(i,j);
            cout<<" ";
        }
        cout<<endl;
    }

    cout<<"Metoda add subtract multiply"<<endl;


    (m1.add(m2)).print();
    cout<<endl;
    (m1.subtract(m2)).print();
    cout<<endl;
    (m1.multiply(m2)).print();
    cout<<endl;
    
    cout<<"Kostruktor dla macierzy prostokatnej"<<endl;
    Matrix m3(4,5);
    m3.print();

    cout<<"metoda cols i rows dla macierzy prostokatnej"<<endl;
    cout<<m3.cols()<<" "<<m3.rows()<<endl;

    for(int i=0; i<4;i++)
    {
        int l=20;
        for(int j=0;j<5;j++)
        {
            m3.set(i,j,l);
            l++;
        }
    }
    cout<<"Metoda set dla prostokatnej"<<endl;
    m3.print();

    cout<<"Zapis macierzy prostokatnej w plik"<<endl;
    m3.store("macierz.txt","C:\\Users\\gmate\\projects\\lab3\\");
    

    cout<<"Nowa macierz na podstawie zapisanej do pliku"<<endl;
    Matrix m4("C:\\Users\\gmate\\projects\\lab3\\macierz.txt");
    cout<<endl;
    m4.print();
    cout<<endl;

    return 0;
}