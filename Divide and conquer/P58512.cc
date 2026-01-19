#include <iostream>
#include <cmath>
using namespace std;

int BetterDeal(double m, double f, double r, int left, int right) {

    if (left >= right) return left ;
    else {
        int mid = (left + right)/2 ;
        double costOak = m + f*mid ;
        double costBank = m*pow(1 + r/100.0, mid) ;

        if (costOak <= costBank) return BetterDeal(m, f, r, left, mid) ;
        else return BetterDeal(m, f, r, mid + 1, right) ; 
    }
}

int BetterDeal(double m, double f, double r, int left, int right) {

    while (left < right) {
        int mid = (left + right)/2 ;
        double costOak = m + f*mid ;
        double costBank = m*pow(1 + r/100.0, mid) ;

        if (costOak <= costBank) right = mid ;
        else left = mid + 1 ; 
    }
    return left ;
}

int main () {

    double m , f , r ;

    while (cin >> m >> f >> r) {
        cout << BetterDeal(m, f, r, 1, 10000000) << endl ;
    }
}

/*
#include <iostream>
#include <cmath>
using namespace std;

double EvaluateDeal(double m, double f, double r, int day) {

    return log(m) + day*log(1 + 0.01*r) - log(m + f*day) ;
}

int BetterDeal(double m, double f, double r, int left, int right) {

    if (left + 1 >= right) return right ;
    else {
        int day = (left + right)/2 ;

        if (EvaluateDeal(m, f, r, day) >= 0) return BetterDeal(m, f, r, left, day) ;
        else return BetterDeal(m, f, r, day, right) ;
    }
}

int main () {

    double m , f , r ;

    while (cin >> m >> f >> r) {
        if (EvaluateDeal(m, f, r, 1) >= 0) cout << 1 << endl ;
        else cout << BetterDeal(m, f, r, 1, 10000000) << endl ;
    }
}
*/