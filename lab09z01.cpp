#include <iostream>
#include <cmath>
using namespace std;

struct SPunkt{
    float x, y;
};

struct SProsta{
    float a, b;
};

struct SOkrag{
    float a, b, r;
};

struct SRownanie{
    float a, b, c;
};

int rozw_rown(const SRownanie& r, SPunkt& p1, SPunkt& p2){
    int w = -1;
    float delta = r.b * r.b - 4 * r.a * r.c;
    if(r.a < 0){
        cout << "Nie moze byc ujemne";
        return 1;
    }
    if(delta<0){
        w = 0;
    }
    else if(delta>0){
                p1.x = (-r.b - sqrt(delta))/(2 * r.a);
                p2.x = (-r.b + sqrt(delta))/(2 * r.a);
                w = 2;
            }
        else{
                p1.x = p2.x = -r.b/(2*r.a);
                w = 1;
            }
    return w;
}

int pkt_przec(const SProsta& p, const SOkrag& o, SPunkt& p1, SPunkt& p2){
    SRownanie r;
    r.a = 1 + p.a * p.a;
    r.b = -2 * (o.a - p.a * (p.b + o.b));
    r.c = o.a * o.a + (p.b - o.b) * (p.b - o.b) - o.r * o.r;

    int w = rozw_rown(r, p1, p2);

    if(w <= 0){
        w = 0;
    }
    else if(w == 1){
            p1.y = p2.y = p.a * p1.x + p.b;
            w = 1;
        }
    else if(w == 2){
            p1.y = p.a * p1.x + p.b;
            p2.y = p.a * p2.x + p.b;
            w = 2;
        }
return w;
}

bool czy_prostopadle(const SProsta p1, const SProsta p2){
    if(p1.a*p2.a==-1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    // { a , b}
    SProsta prosta1 = {1.0, 3.0};
    SProsta prosta2 = {-1.0, -33};
    //SProsta prosta3 = {1.0, -3};
    // { a, b, r}
    SOkrag okrag = {0.0, 1.0, 2.0};

    if(czy_prostopadle(prosta1, prosta2)){
        cout << "proste sa prostopadle\n";
    }
    else{
        cout << "proste nie sa prostopadle\n";
    }

    SPunkt p1 = {1.0, 1.0}; 
    SPunkt p2 = {2.0, 2.0};
    SRownanie r12 = {1, 2, 1};

    cout << "ilosc pierwiastkow: " << rozw_rown(r12, p1, p2) << "\n";

    cout << "ilosc punktow przeciec: " <<pkt_przec(prosta1, okrag, p1, p2) << "\n";
    
    return 0;
}
