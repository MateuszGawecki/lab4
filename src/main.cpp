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

    try
    {
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


        m1.set(10,10,4); //wyrzuci exception
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        cout<< e.what()<<endl;
    }
    

    cout<<"Po ustawieniu wartosci metoda set"<<endl;
    m1.print();
    cout<<endl;
    m2.print();
    cout<<endl;

    try
    {
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

        m1.get(18,2); //wyrzuci exception
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        cout<<e.what()<<endl;
    }
    

    cout<<"Przeciazenie oeratorow + - * "<<endl;
    try
    {
        (m1+m2).print();
        cout<<endl;
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        cout<<e.what()<<endl;
    }
    
    try
    {
        (m1-m2).print();
        cout<<endl;
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        cout<<e.what()<<endl;
    }
    
    try
    {
        (m1*m2).print();
        cout<<endl;
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        cout<<e.what()<<endl;
    }
    


    cout<<"Metoda add subtract multiply"<<endl;

    try
    {
        (m1.add(m2)).print();
        cout<<endl;
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        cout<<e.what()<<endl;
    }
    
    try
    {
        (m1.subtract(m2)).print();
        cout<<endl;
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        cout<<e.what()<<endl;
    }
    
    try
    {
        (m1.multiply(m2)).print();
        cout<<endl;
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        cout<<e.what()<<endl;
    }


    cout<<"Przeladowanie operatora []"<<endl;
    
    for(int i=0; i<m1.cols(); i++)
    {
        cout<<m1[2][i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"Przeladowanie operatora <<"<<endl;

    cout<<m1<<endl;
    cout<<endl<<endl;

    
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

    cout<<"Przeladowanie operatora <<"<<endl;

    cout<<m3<<endl;
    cout<<endl<<endl;

    cout<<"Zapis macierzy prostokatnej w plik"<<endl;

    try
    {
        m3.store("macierz.txt","C:\\Users\\gmate\\projects\\macierz\\");
        //m3.store("macierz.txt","C:\\Users\\gmate\\project\\macierz\\"); //exception
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        cout<<e.what()<<endl;
    }
    

    /*
    cout<<"Zapis macierzy prostokatnej w plik z przeładowaniem operatora <<"<<endl;
    fstream plik;
    plik.open("C:\\Users\\gmate\\projects\\macierz\\macierz.txt", ios::out);

    if(!plik.good())
    {
        exit (1);
    }
    else
    {
        cout<<"Otwarto"<<endl;
    }

    plik<<m3;

    plik.close();*/
    

    cout<<"Nowa macierz na podstawie zapisanej do pliku"<<endl;
    try
    {
       // Matrix m4("C:\\Users\\gmate\\projects\\macierz\\macierz.txt");
       Matrix m4("C:\\Users\\gmate\\project\\macierz\\macierz.txt"); // bez s przy projects, wyrzuci excp

        cout<<endl;
        //m4.print();
        cout<<m4;
        cout<<endl;
    }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        cout<<e.what()<<endl;
    }
    

    cout<<"Przeciazenie operatora =="<<endl;

    if(m1==m1)
    {
        cout<<"m1 i m1 sa takie same"<<endl;
    }
    else
    {
        cout<<"m1 i m1 nie sa takie same"<<endl;
    }

    if(m1==m2)
    {
        cout<<"m1 i m2 sa takie same"<<endl;
    }
    else
    {
        cout<<"m1 i m2 nie sa takie same"<<endl;
    }

    cout<<"Tworze nowa macierz taka sama jak m3 "<<endl; 


    try
    {
        Matrix m5("C:\\Users\\gmate\\projects\\macierz\\macierz.txt");


        if(m3==m5)
        {
            cout<<"m3 i m5 sa takie same"<<endl;
        }
        else
        {
            cout<<"m3 i m5 nie sa takie same"<<endl;
        }

        cout<<"Zmieniam jeden element macierzy m5"<<endl;

        try
        {
            m5.set(1,2,40);
        }
        catch(const std::exception& e)
        {
            //std::cerr << e.what() << '\n';
            cout<<e.what()<<endl;
        }

        if(m3==m5)
        {
            cout<<"m3 i m5 sa takie same"<<endl;
        }
        else
        {
            cout<<"m3 i m5 nie sa takie same"<<endl;
        }
        }
    catch(const std::exception& e)
    {
        //std::cerr << e.what() << '\n';
        cout<<e.what()<<endl;
    }
    
    return 0;
}