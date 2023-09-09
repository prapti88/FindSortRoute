#include<bits/stdc++.h>
using namespace std;

int u,v,w,i,edge,sc;

struct city
{
    int nd,Distance;

}temp;

struct Line
{
    int Name,Key;
    bool flag;
} A[100];

vector<city> g[100];
int n, dis[100],par[100];

int pop()
{
    int min=1000000;
    int index;
    for(int i=0; i<n; i++)
    {
        if(A[i].Key < min && A[i].flag==true)
        {
            min=A[i].Key;
            index=i;
        }
    }
    A[index].flag=false;
    return index;
}

bool isEmpty()
{
    for(int i=0; i<n; i++)
    {
        if(A[i].flag)
            return false;
    }
    return true;
}
int Dijkstra(int n,int u, int v, int w)
{
    while(!isEmpty())
    {
        int u=pop();
        for(int i=0; i<g[u].size(); i++)
        {
            city t=g[u][i];
            int v=t.nd;
            int w=t.Distance;
            if(dis[v]>dis[u]+w)
            {
            dis[v]=dis[u]+w;
            par[v]=u;
            A[v].Key=dis[v];
            }
        }
    }
}

void PrintPath(int parent[],int city,int length)
{
    if(city==-1) return;
    PrintPath(parent,parent[city],length+1);
    cout<<(char)(65+city);
    if(length!=0){
        cout<<", ";
    }
}

void PrintCost(int sc)
{
    int i;
    for(i=0; i<n; i++)
    {
        dis[i]=99999;
        par[i]=-1;
    }
    dis[sc]=0;
    for(i=0; i<n; i++)
    {
        A[i].Name=i;
        A[i].Key=dis[i];
        A[i].flag=true;
    }
    cout<<"From your City: "<<(char)(65+sc);
    cout<<"\nDestination City\tMin Distance\tMin Route\n"<<endl;
    Dijkstra(n,u,v,w);
    for(i=0; i<n; i++)
    {
        cout<<(char)(65+i)<<"\t\t\t";
        cout<<dis[i]<<"\t\t";
        PrintPath(par,i,0);
        cout<<endl;
    }
}

int main()
{
    while(1)
    {
        cout<<"\n 1. Create Route Map.\n 2. Your Location to Destination City .\n 3. Distance to destinations from all cities.\n 4. Exit \n";
        int ch;
        cin>>ch;
        if(ch==1)
        {
            cout<<"Enter Number of Cities: ";
            cin>>n;
            cout<<"Enter Number of Route: ";
            cin>>edge;
            for(i=0; i<edge; i++)
            {
                cout<<"Route "<<i+1<<" Edges: \n";
                cin>>u>>v;
                cout<<"Distance: \n";
                cin>>w;
                temp.nd=v;
                temp.Distance=w;
                g[u].push_back(temp);
                temp.nd=u;
                g[v].push_back(temp);
            }
          //  break;
        }
        else if(ch==2)
        {
            cout<<"Enter Your Location: ";
            cin>>sc;
            if(sc<=n)
            PrintCost(sc);
            else

                cout<<"You Have To Choose from 0 to n";
        }

        else if(ch==3)
        {
            for(int k=0; k<n; k++)
            {
                PrintCost(k);
            }

        }
        else if(ch==4)
        {
            break;
        }
        else
            cout<<"WRONG CHOOSE";
    }
    return 0;
}


