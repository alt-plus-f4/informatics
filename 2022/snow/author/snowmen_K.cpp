#include<bits/stdc++.h>
using namespace std;
struct snowman{
    int p;
    int m;
    int lastb;
    int slastb;
    int heavy;
};
const int maxn=1000001;
snowman a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    long long sumh=0;
    cin>>a[1].p>>a[1].m;
    a[1].heavy=a[1].m;
    a[1].lastb=a[1].m;
    a[1].slastb=0;
    sumh+=a[1].heavy;
    for(int i=2;i<=n;i++){
        cin>>a[i].p>>a[i].m;
        int x=a[i].p;
        int y;
        if(a[i].m!=0){
            a[i].heavy=a[x].heavy+a[i].m;
            a[i].lastb=a[i].m;
            a[i].slastb=a[x].lastb;
        }
        else{
            a[i].heavy=a[x].heavy-a[x].lastb;
            a[i].lastb=a[x].slastb;
            y=a[x].p;
            a[i].slastb=a[y].slastb;
        }
        sumh+=a[i].heavy;
    }
    cout<<sumh<<endl;
    return 0;
}
