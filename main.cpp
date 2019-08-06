#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct
{
    int x[5] = {1,2,3,4,5};
}X;

void print(int x[], int n)
{
    QTextStream out(stdout);
    for (int i=0;i<n;i++) {
      //printf("%d",x[i]);
      out<<x[i];
    }
    out<<endl;
}

void swap(int x[], int p1, int p2)
{
    int temp = x[p1];
    x[p1] = x[p2];
    x[p2] = temp;

}


void permutation(X x, int k, int j, int n)
{
    if( j < k)
    {

        return;
    }
    else
    {

        for(int i = k;i<n;i++)
        {

           j--;
           permutation(x, k, j, n);
           swap(x.x, i,j+1);

           if ( i == 0 || i != j + 1  )
             print(x.x, n);
           k++;
           j = n -1;

        }
    }
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    X x;
    permutation(x, 0,4,5);
    return a.exec();
}
