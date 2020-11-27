//#include <iostream>
//#include <fstream>
//#include <string>

#include "../include/lab4/Matrix.hpp"

//using namespace std;


Matrix::Matrix(string path)
{
    fstream plik;
    plik.open(path, ios::in);

    if(!plik.good())
    {
        exit (2);
    }
    else
    {
        cout<<"Otwarto na odczyt"<<endl;
    }
    

    plik>>n;
    plik>>m;
    
     tab=new double*[n];
    for(int i=0; i<n; i++)
      tab[i]=new double[m];

    for(int j=0; j<n; j++)
      for(int k=0;k<m; k++)
        plik>>tab[j][k];
}

void Matrix::store(string filename, string path)
{
  string droga=path+filename;
  fstream plik;
  plik.open(droga, ios::out);

  if(!plik.good())
  {
      exit (1);
  }
  else
  {
    cout<<"Otwarto"<<endl;
  }

  plik<<n;
  plik<<" ";
  plik<<m;
  plik<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            plik<<tab[i][j];
            plik<<" ";
        }
        plik<<endl;
    }

    plik.close();
}

Matrix::Matrix(int a)
{
    n=a;
    m=a;

    tab=new double*[n];
    for(int i=0; i<n; i++)
      tab[i]=new double[m];

    for(int j=0; j<n; j++)
      for(int k=0;k<m; k++)
        tab[j][k]=0;
}

Matrix::Matrix(int a, int b)
{
    n=a;
    m=b;

    tab=new double*[n];
    for(int i=0; i<n; i++)
      tab[i]=new double[m];

    for(int j=0; j<n; j++)
      for(int k=0;k<m; k++)
        tab[j][k]=0;
}

Matrix::~Matrix()
{
    if(tab)
    {
        for(int i=0; i<n; i++)
        {
            if(tab[i]) delete []tab[i];
        }
        delete []tab;
    }
    cout<<"Destruktor"<<endl;
}

void Matrix::set(int a, int b, double c)
{
    tab[a][b]=c;
}

double Matrix::get(int a, int b)
{
    return tab[a][b];
}

void Matrix::print()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
}

int Matrix::cols()
{
    return m;
}

int Matrix::rows()
{
    return n;
}

Matrix Matrix::add(Matrix& a)
{
    if(n!=a.n || m!=a.m)
    {
        exit(1);
    }
        Matrix w(n,m);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                w.tab[i][j]=tab[i][j]+a.tab[i][j];;
            }
        }

    return w;
}

Matrix Matrix::subtract(Matrix& a)
{
   if(n!=a.n || m!=a.m)
    {
        exit(1);
    }
        Matrix w(n,m);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                w.tab[i][j]=tab[i][j]-a.tab[i][j];
            }
        }
    
    return w;
}

Matrix Matrix::multiply(Matrix& a)
{
    if(m!=a.n)
    {
        exit(1);
    }
        Matrix w(n,a.m);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<a.m;j++)
            {
                for(int k=0;k<m;k++)
                    w.tab[i][j] +=tab[i][k]*a.tab[k][j];
            }
        }
    
    return w;
}


Matrix& Matrix::operator+(Matrix& a)
{
    if(n!=a.n || m!=a.m)
    {
        exit(1);
    }
        Matrix w(n,m);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                w.tab[i][j]=tab[i][j]+a.tab[i][j];;
            }
        }

    return w;
}

Matrix& Matrix::operator-(Matrix& a)
{
     if(n!=a.n || m!=a.m)
    {
        exit(1);
    }
        Matrix w(n,m);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                w.tab[i][j]=tab[i][j]-a.tab[i][j];
            }
        }
    
    return w;
}

Matrix& Matrix::operator*(Matrix& a)
{
     if(m!=a.n)
    {
        exit(1);
    }
        Matrix w(n,a.m);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<a.m;j++)
            {
                for(int k=0;k<m;k++)
                    w.tab[i][j] +=tab[i][k]*a.tab[k][j];
            }
        }
    
    return w;
}