#ifndef LAB4_HPP
#define LAB4_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <exception>


using namespace std;

class Matrix
{
    private:
        int n,m;
        double **tab;
    
    public:
        Matrix(int a); //konstruktor
        Matrix(int a, int b); //konstruktor
        Matrix(string path); //konstruktor czytajacy z pliku
        ~Matrix(); //destruktor
        void set(int a, int b, double c); //ustawia element (n,m) na wartość c
        double get(int a, int b); //zwraca wartość z miejsca (n,m) w tablicy
        void print();//wypisuje macierz
        int cols();//zwraca liczbę kolumn 
        int rows();//zwraca liczbę wierszy
        Matrix add(Matrix&); //metoda dodawania macierzy
        Matrix subtract(Matrix&); //metoda odejmowania macierzy
        Matrix multiply(Matrix&); //metoda mnożenia macierzy
        Matrix operator+(Matrix&);//definicja operatora dodawania macierzy
        Matrix operator-(Matrix&);//definicja operatora odejmowania macierzy
        Matrix operator*(Matrix&);//definicja operatora mnożenia macierzy
        bool operator==(Matrix&);
        double* operator[](unsigned int index);
        void store(string filename,string path);//zapis do pliku
        friend ostream& operator<<(ostream&,Matrix&);
};

class MyExeption_read : public exception
{
    virtual const char *what() const throw()
    {
        return "\nUnable to read from file\n";
    }
};

class MyExeption_get : public exception
{
    virtual const char *what() const throw()
    {
        return "\nUnable to get that element\n";
    }
};

class MyExeption_set : public exception
{
    virtual const char *what() const throw()
    {
        return "\nUnable to set that element\n";
    }
};

class MyExeption_add : public exception
{
    virtual const char *what() const throw()
    {
        return "\nAdd err\n";
    }
};

class MyExeption_subtract : public exception
{
    virtual const char *what() const throw()
    {
        return "\nSubtract err\n";
    }
};

class MyExeption_multiply : public exception
{
    virtual const char *what() const throw()
    {
        return "\nMultiply err\n";
    }
};

class MyExeption_save : public exception
{
    virtual const char *what() const throw()
    {
        return "\nUnable to save to file\n";
    }
};

#endif