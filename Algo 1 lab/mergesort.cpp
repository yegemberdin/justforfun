#include <iostream>
using namespace std;
int n, a[100100];
int sz=0, tmp[100100];
void mergesort(int l, int r){
	if (l>=r) return;

	if (l==r) return;
	int mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1, r);
	int i=l;
	int j=mid+1;
	sz=0;
	while(i<=mid && j<=r){
		if (a[i]<a[j]){
			tmp[sz]=a[i];
			sz++; i++;
		}
		else{
			tm[sz]=a[i];
			sz++; j++;
		}
	}
	while (i<=mid){
		tmp[sz++]=a[i++]
	}
	while (j<=r) {
		tmp[sz++]=a[j++]

	}
	for (int t=l; t<=r; t++) a[t]=tmp[t-1];
}

int main(){
	scanf("%d", &n);
	//zhalgasy sotkada surett
}