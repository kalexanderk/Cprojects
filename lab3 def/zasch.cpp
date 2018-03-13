#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

const int size=16;

int compare_func(int d1,int d2,int mask[]){
	int i,j,a=0,d1b,d2b;
	for (i=1;i<size+1;++i){
		for (j=0;j<size;++j){
			if (mask[j]==i){
				a=j+1;
				d1b=(d1>>(size-a))&1;
				d2b=(d2>>(size-a))&1;
				if (d1b==d2b) continue;
				if ((a==1)||(a==4)||(a==5)||(a==7)||(a==9)||(a==13)||(a==14)||(a==16)){//hi
					if (d1b>d2b) return 1;
					if (d1b<d2b) return 0;
				}
				if ((a==2)||(a==3)||(a==6)||(a==8)||(a==10)||(a==11)||(a==12)||(a==15)){//low
					if (d1b<d2b) return 1;
					if (d1b>d2b) return 0;
				}
			}
		}
	}
}

int main(){
	int n,k1,k2,i;
	cout<<"Input quantity of numbers to sort: ";
	cin>>n;
	if (n<=0){
		cout<<"Error! Invalid value.";
		return 0;
	}
	int arr[n];
	int mask[size]={ 15, 11, 9, 1, 16, 12, 8, 7, 14, 4, 5, 13, 10, 2, 6, 3 };
	for(i=0;i<n;++i){
		cout<<"Input number "<<i+1<<" : ";
		cin>>arr[i];
		}
	cout<<endl;
	for (k1=0;k1<n;++k1){
		for (k2=k1+1;k2<n;k2++){
			int f=compare_func(arr[k1],arr[k2],mask);
			if(f==1) swap(arr[k1],arr[k2]);
		}
	}
	cout<<"Sorted list is { increasing sequence --> }:"<<endl;
	for(i=0;i<n;++i){
		cout<<" "<<arr[i];
		}
	return 0;
}
