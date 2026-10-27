#include<iostream>
#include<fstream>
using namespace std;
 const int MAX =100;
 const int INF =9999;
 int n;
 int A[MAX][MAX];
 void Nhap(){
 	ifstream f("Graph3.txt");
 	if(!f){
 		cout<<"Khong mo dc file ";
 		return;
	 }
	 f>>n;
	 for(int i=0; i<n; i++){
	 	for(int j=0; j<n; j++){
	 		f>>A[i][j];
		 }
	 }
	 f.close();
 }
 void Hienthi(){
 	cout<<"\nMa tran trong so: \n";
 	for(int i=0 ;i<n; i++){
 		for(int j =0; j<n; j++){
 			cout <<A[i][j]<<"\t";
		 }
		 cout<<endl;
	 }
 }
 void Dijkstra(int s, int t){
 	int d[MAX];
 	int truoc[MAX];
 	bool visited[MAX];
	for(int i=0;i<n;i++){
		d[i]= INF;
		truoc[i]=-1;
		visited[i]= false;
	} 
	d[s]= 0;
	for(int k=0; k<n; k++){
		int min = INF ;
		int u=-1;
		for(int i=0; i<n; i++){
			if(!visited[i]&& d[i]<min){
				min = d[i];
				u=i;
			}
		}
		if(u == -1){
			break;
		}
		visited[u]=true;
		for(int v=0; v<n; v++){
			if(A[u][v] != INF && !visited[v]){
				if(d[v]> d[u]+ A[u][v]){
					 d[v] = d[u] + A[u][v];
					 truoc[v]=u;
			}
		}
	}
}
 if(d[t] == INF ){
	cout<<"\nKhong co duong di: ";
	return ;
} 
cout<<"\nDo dai duong di ngan nhat: "<<d[t]<<endl;
int path[MAX];
int dem=0;
int temp=t;
 while (temp != -1){
	path[dem++]=temp;
	temp =truoc[temp];
}
 cout<<"Duong di: ";
for(int i=dem-1; i>=0; i--){
	cout<<"V"<<path[i]+1;
	if(i != 0){
		cout<<"->";
	}
	}
}
int main(){
	Nhap();
	Hienthi();
	cout<<"\nTim duong di tu V1 den V6\n";
	Dijkstra(0, 5);
	return 0;
}
