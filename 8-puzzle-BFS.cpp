#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define pr pair<lli,lli>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<lli>
#define vpi vector<pr> 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define NA(i,s,n) for(lli i=s;i<n;i++)
using namespace std;
struct Node 
{ 
    Node* parent; 
    int m[3][3]; 
    int x, y; 
    int prevOP;
}; 
void printNode(Node *n){
    cout<<"--------------"<<endl;
    NA(i,0,3){
        NA(j,0,3){
            cout<<n->m[i][j]<<" ";
        } cout<<endl;
    }
    return;
}
int check(Node *n,int d[3][3]){
    NA(i,0,3){
        NA(j,0,3){
            if(n->m[i][j]!=d[i][j]) return 0;
        }
    } return 1;
}
void backtrack(Node *n){
    while(n->parent!=NULL){
        printNode(n);
        n = n->parent;
    }
}
Node* newNode(Node *nd,int px,int py,int dir){
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->parent = nd; n->x=px; n->y=py; n->prevOP = dir;
    NA(i,0,3){
        NA(j,0,3){
            n->m[i][j] = nd->m[i][j];
        }
    }
    lli t = n->m[px][py];
    n->m[px][py]=-1;
    n->m[nd->x][nd->y]=t;
    return n;
}
Node* opr(Node *nd,lli dir){
    if(nd==NULL) return NULL;
    if(dir==1){
        if(nd->prevOP!=-1 && (nd->x)-1>-1)return newNode(nd,(nd->x)-1,(nd->y),dir);
        return NULL;
    } else if(dir==2){
        if(nd->prevOP!=-2 && (nd->y)-1>-1)return newNode(nd,(nd->x),(nd->y)-1,dir);
        return NULL; 
    } else if(dir==-1){
        if(nd->prevOP!=1 && (nd->y)+1<3) return newNode(nd,(nd->x),(nd->y)+1,dir);
        return NULL;
    } else {
        if(nd->prevOP!=2 && (nd->x)+1<3) return newNode(nd,(nd->x)+1,(nd->y),dir);
        return NULL;
    }
}
void bfs(Node *n,int d[3][3]){
    queue<struct Node*> q;
    q.push(n);
    while(!q.empty()){
        if(q.front()==NULL) {
            q.pop(); continue;
        }
        if(check(q.front(),d)) {
            backtrack(q.front());
            return;
        }
        Node* s = (struct Node*)malloc(sizeof(struct Node));
        s = q.front();
        q.pop();
        NA(i,-2,3){
            if(i!=0) q.push(opr(s,i));
        }
    }
}
int main(){
    int init[3][3],fin[3][3];
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->parent = NULL; n->prevOP = 0;
    cout<<"Enter initial state"<<endl;
    NA(i,0,3){
        NA(j,0,3){
            cin>>n->m[i][j];
            if(n->m[i][j]==-1){
                n->x=i; n->y=j;
            }
        }
    }    
    cout<<"enter final state"<<endl;
    NA(i,0,3){
        NA(j,0,3){
            cin>>fin[i][j];
        }
    }
    bfs(n,fin);
    return 0;
}