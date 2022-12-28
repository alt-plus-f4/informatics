#include<iostream>
#include<assert.h>
#define MAXN 1000000
using namespace std;
int queries[MAXN+1][2],snowmen[MAXN+1][2];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    assert(cin >> n );
    assert((n>=1)&&(n<=MAXN));
    //assert(n<=5000);
    long long int total=0;
    snowmen[0][0]=-1; snowmen[0][1]=0;
    queries[0][0]=-1;
    for (int i=1; i<=n; i++) {
        assert(cin >> queries[i][0] >> queries[i][1] );
        assert((queries[i][0]>=0)&&(queries[i][0]<i));
        assert((queries[i][1]>=0)&&(queries[i][1]<=1000));
        if (queries[i][1]>0) {
            snowmen[i][0]=queries[i][0];
            snowmen[i][1]=snowmen[queries[i][0]][1]+queries[i][1];
        }
        else {
            assert(snowmen[queries[i][0]][0]!=-1);
            snowmen[i][0]=queries[snowmen[queries[i][0]][0]][0];
            snowmen[i][1]=snowmen[snowmen[queries[i][0]][0]][1];
        }
        total+=snowmen[i][1];
    }
    char dummy; assert(!(cin >> dummy ));
    cout << total ;
    cout << endl ;
    return 0;
}
