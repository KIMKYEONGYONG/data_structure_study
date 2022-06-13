#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define NODECOUNT	7
/**
 @author maluchi (https://maluchisoft.com)
*/
struct Edge{
	int s, e; // start node, end node
	int distance;
	Edge(int a, int b, int dist)
	{
		s = a;
		e = b;
		distance = dist;
	}

	// ascending order
	bool operator < ( Edge &edge )
	{
		return distance < edge.distance;
	}
};

// Search parent node
int getParent(int d[], int x)
{
	if(d[x] == x)
		return x;
	return d[x] = getParent(d, d[x]);	
}

// Union to parent node
void unionParent(int d[], int a, int b)
{
	a = getParent(d, a);
	b = getParent(d, b);

	if( a < b) d[b] = a;
	else d[a] = b;
}

// return whether same parent exists  or not
bool findParent(int d[], int a, int b)
{
	a = getParent(d, a);
	b = getParent(d, b);

	if(a == b)
		return true;
	return false;
}

void print(vector<Edge> &v)
{
	vector<Edge>::iterator it;
	for(it=v.begin();it !=v.end();it++)
	{
		cout<<it->s<<"->"<<it->e<<" :"<<it->distance<<endl;
	}

	cout<<endl;
}


void solve()
{
	int Node[NODECOUNT + 1]; // 총 노드7개, NODE를 Index 1부터 시작하기 위해 

	vector<Edge> v;
	v.push_back(Edge(1,2,9));
	v.push_back(Edge(1,3,12));
	v.push_back(Edge(1,4,5));
	v.push_back(Edge(1,5,35));
	v.push_back(Edge(2,4,14));
	v.push_back(Edge(2,5,17));
	v.push_back(Edge(3,4,10));
	v.push_back(Edge(3,6,23));
	v.push_back(Edge(3,7,53));
	v.push_back(Edge(4,5,20));
	v.push_back(Edge(4,6,19));
	v.push_back(Edge(5,6,47));
	v.push_back(Edge(5,7,32));
	v.push_back(Edge(6,7,37));


	sort(v.begin(), v.end());
	print(v);
	
	// 각 정점을 자기 자신으로 임시 설정
	for(int i=1;i<=NODECOUNT;i++)
	{
		Node[i] = i;
	}

	int total = 0;
	for(int i=0;i<(int)v.size();i++)
	{
		// 사이클이 발생하지 않도록 체크하며, 사이클이 아니면 누적
		if(!findParent(Node, v[i].s , v[i].e))
		{
			total += v[i].distance;
			unionParent(Node, v[i].s, v[i].e);
		}
	}

	v.clear();

	cout<<"total distance:"<<total<<"\n";


}

int main()
{
	solve();
	return 0;
}