#include <iostream>
using namespace std;

const string bases = "ACGT" ;

char complementary(const char& c) {

    if (c == 'A') return 'T' ;
    else if (c == 'C') return 'G' ;
    else if (c == 'G') return 'C' ;
    else return 'A' ;
}

void BackTrack(int i, string& A, string& B) {

    if (i == A.size()) {
        for (const char& c : A) cout << c ;
        cout << endl ;

        for (const char& c : B) cout << c ;
        cout << endl << endl ;
    }
    else {
        if (A[i] != '.' and B[i] != '.' and complementary(A[i]) != B[i]) return ;
        else if (A[i] == '.' and B[i] == '.') {
            for (const char& b : bases) {
                A[i] = b ;
                B[i] = complementary(b) ;
                BackTrack(i + 1, A, B) ;
                A[i] = B[i] = '.' ;
            }
        }
        else if (A[i] != '.') {
            char old = B[i] ;
            B[i] = complementary(A[i]) ;
            BackTrack(i + 1, A, B) ;
            B[i] = old ;
        }
        else {
            char old = A[i] ;
            A[i] = complementary(B[i]) ;
            BackTrack(i + 1, A, B) ;
            A[i] = old ;
        }
    }
}

int main () {

    int n ;

    while (cin >> n) {
        string A ;
        string B ;
        A.resize(n) ;
        B.resize(n) ;

        for (int i = 0 ; i < n ; ++i) cin >> A[i] ;
        for (int i = 0 ; i < n ; ++i) cin >> B[i] ;
        BackTrack(0, A, B) ;
        cout << string(10, '-') << endl ;
    }
}