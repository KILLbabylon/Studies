#include <iostream>
#include <cmath>
using namespace std;

double f(const double &x)
{
    return // wzór aproksymacji
}
double f2(const double &x)
{
    return // wzór interpolacji
}

double calkainter(double h, double a, int n)
{
    double wynik = 0;
    for (int i = 0; i < n; ++i)
    {
        double xl = a + i * h;
        double xp = a + i * h + h;
        double xs = a + i * h + h / 2;
        wynik += (h / 6) * (f(xl) + f(xp) + 4 * f(xs));
    }
    return wynik;
}
double calkaaproks(double h, double a, int n)
{
    double wynik = 0;
    for (int i = 0; i < n; ++i)
    {
        double xl = a + i * h;
        double xp = a + i * h + h;
        double xs = a + i * h + h / 2;
        wynik += (h / 6) * (f2(xl) + f(xp) + 4 * f2(xs));
    }
    return wynik;
}
int main()
{
    double a = 0, b = 1;
    int n = 400;
    double h = (b - a) / n;
    cout << "calka z aproksymacji: " << calkainter(h, a, n) << endl;
    cout << "calka z interpolacji: " << calkaaproks(h, a, n) << endl;
    return 0;
}