#include <iostream>
#include <vector>
using namespace std;

const int Nmax = 1000000;
struct query {
  int p;
  int m;
};

vector<int> balls[Nmax+1];

int n;
query queries[Nmax+1];
long long total_weight=0;

void input(){
  int p,m;
  cin >> n;
  for (int i=1;i<=n;i++){
    cin >> p >> m;
    for (int j=0; j<balls[p].size();j++){
        balls[i].push_back(balls[p][j]);
    }

    if (m>0){
        balls[i].push_back(m);
    }
    else{
        balls[i].pop_back();
    }

  }
}



int main() {
   ios::sync_with_stdio(false);
   input();
   for (int i=1;i<=n;i++)
     for (int j=0; j<balls[i].size(); j++)
       total_weight=total_weight+balls[i][j];
   cout << total_weight<<endl;


}
