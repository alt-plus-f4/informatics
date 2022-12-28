#include <stdio.h>

#define Nmax 1000000

struct query {
	int p;
	int m;
};

int N;
struct query queries[Nmax+1];
long long SMweight[Nmax+1];
long long total_weight=0;

void input(){
	scanf("%d", &N);
	for (int i=1;i<=N;i++)
		scanf("%d %d", &queries[i].p, &queries[i].m);
}

void transform_queries() {
	int k;

	queries[0].p=0;
	queries[0].m=0;
	
	for (int i=1;i<=N;i++)
		if (queries[i].m == 0){
			k = queries[queries[i].p].p;
			queries[i].p = queries[k].p;
			queries[i].m = queries[k].m;
		}
}

void calc_weight(){
SMweight[0]=0;
for (int i=1;i<=N;i++){
SMweight[i]=SMweight[queries[i].p]+queries[i].m;
total_weight = total_weight+SMweight[i];
}
}

int main() {
input();
transform_queries();
calc_weight();

printf("%lld\n", total_weight);
return 0;
}