// #include "tp1.h"
// #include <QApplication>
// #include <time.h>

// int isMandelbrot(Point z, int n, Point point){
//     // recursiv Mandelbrot

//     // check n

//     // check length of z
//     // if Mandelbrot, return 1 or n (check the difference)
//     // otherwise, process the square of z and recall
//     // isMandebrot
//     return 0;
// }

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     MainWindow* w = new MandelbrotWindow(isMandelbrot);
//     w->show();

//     a.exec();
// }

#include <iostream>

using namespace std;

int isMandelbrot(int z[], int n, int point[]){
    if (n==0){
        return 0;
    }

    if (z[0]*z[0]+z[1]*z[1]>4){
        return n;
    }

    int z2[2];
    z2[0]=z[0]*z[0]-z[1]*z[1]+point[0];
    z2[1]=2*z[0]*z[1]+point[1];

    return isMandelbrot(z2, n-1, point);
}

int main()
{
    int z[2];
    z[0]=0;
    z[1]=0;
    int point[2];
    point[0]=0;
    point[1]=0;
    cout << isMandelbrot(z, 100, point) << endl;
    return 0;
}
