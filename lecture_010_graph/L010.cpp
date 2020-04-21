#include <iostream>
#include <vector>

using namespace std;

class Edge{
  
  public: 
    
    int v;
    int w;

    Edge(int v1,int w1)
    {
       this->v=v1;
       this->w=w1;
    }
 
};

int N=8;// vertices
vector<vector<Edge>> graph(N,vector<Edge>());

void addEdge(int u,int v,int w){

    Edge e1(v,w);
    Edge e2(u,w);
    graph[u].push_back(e1);
    graph[v].push_back(e2);
    
}

void display(){

    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        
        for(Edge e:graph[i]){
             
            cout<<"("<<e.v<<","<<e.w<<")"<<" ";

        }
        cout<<endl;
    }

    cout<<endl;
}

int findEdge(int r,int c){    //rth node se cth node  
 
 int idx=-1;
 for(Edge e:graph[r])
 {  ++idx;
    if(e.v==c)
    {
       return idx; 
    }
 }

 return idx;

}

void removeEdge(int u,int v){

   int idx1=findEdge(u,v);
   int idx2=findEdge(v,u);

   graph[u].erase(graph[u].begin()+idx1);  //u se v  jaane vaali edge 
   
   graph[v].erase(graph[v].begin()+idx2);   // v se u jaane vaali edge
   
}

void removevtx(int v){
     
    while(graph[v].size()!=0)
    {
        graph[v].erase(graph[v].begin());
    }

}

void graphConstruct(){
 
 addEdge(0,1,10);
 addEdge(0,3,10);
 addEdge(1,2,10);
 addEdge(2,3,40);
 addEdge(3,4,2);
 addEdge(4,5,2);
 addEdge(4,6,3);
 addEdge(5,6,18);


 display();
 cout<<endl;
}

bool haspath(int src,int des,vector <bool> arr){
   
   if(src==des){ return true; }   //bse case
   
   bool res=false;
   arr[src]=true;
   for(Edge e:graph[src])
   { 
       if(arr[e.v]==false)    //unmarked neighbour ko dhund lia
       {
         res=res || haspath(e.v,des,arr);
       }
       if (res) return true;
   }

   return res;
}


int allPath(int src,int des,vector<bool> arr,string ans)
{   
    if(src==des){
        
        cout<<ans<<endl;

    }
     
    int count=0;

    arr[src]=true;

    for(Edge e:graph[src])
    {
        if(arr[e.v]==false)
        {
            count+=allPath(e.v,6,arr,ans+to_string(e.v)+" ");
        }
    }
  
    arr[src]=false;
  
    return count;
}

class ansPair
{
    public:
        int heavy=0;
        int light=1e7;;
        int floor=0;;
        int ceil=1e7;
};

void allSolution(int src, int dest, vector<bool> &vis, int w, string ans, ansPair &pair, int data)
{
    if (src == dest)
    {  

       ans = ans + " "+ to_string(dest);
       cout<<ans<<endl;

       pair.heavy=max(pair.heavy,w);
       pair.light=min(pair.light,w);

       if(w>data)
       {
           pair.ceil=min(pair.ceil,w);
       }

       if(w<data)
       {
           pair.floor=max(pair.floor,w);
       }

       return;
    }

    vis[src] = true;

    for (Edge e : graph[src])
    {
        if (!vis[e.v])
            allSolution(e.v, dest, vis, w + e.w, ans + to_string(src) + " ", pair,data);
    }

    vis[src] = false;
}

void question(){

    vector <bool>arr(N,false);
    //  cout<<haspath(0,7,arr);
    
    // int count=allPath(0,6,arr,"");
    // cout<<count<<endl;

    ansPair obj;

    allSolution(0,6,arr,0,"",obj,30);

    cout<<obj.heavy<<" "<<obj.light<<" "<<" "<<obj.floor<<" "<<obj.ceil<<endl;

}

void basic(){ 
    removeEdge(3,4);    
    removevtx(3); 
}

void solve(){
   graphConstruct();
   //basic();
   question();
}

int main(){

    solve();
    
}