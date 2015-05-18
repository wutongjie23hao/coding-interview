#include <iostream>
using namespace std;

const int kind = 26;

struct Treenode{
    int count;
    Treenode* next[kind];
    Treenode(){
        count=1;
        for(int i=0; i<kind; i++)
            next[i] = NULL;
    }
};

void insert(Treenode *&root, char* str){
    Treenode *p = root;
    int i=0;
    int branch = 0;

    if(root == NULL){
        p=new Treenode();
        root = p;
    }

    while(str[i]!='\0'){
        branch = str[i] - 'a';
        if(p->next[branch]==NULL)
            p->next[branch] = new Treenode();
        else
            p->next[branch]->count++;
        p = p->next[branch];
        i++;
    }
}

int search(Treenode *root, char *str){
    Treenode *p = root;
    int ans=0;
    int i=0, branch = 0;

    if (root == NULL || str == NULL)
        return 0;

    while(str[i]!='\0'){
        branch = str[i] - 'a';
        if(p->next[branch]!=NULL){
            p = p->next[branch];
            ans = p->count;
            i++;
        } else {
            ans = 0;
            break;
        }
    }

    return ans;
}

int main(){
    char word[101];
    char ask[101];
    Treenode *root = NULL;
    int m, n;

//    printf("n:");
    scanf("%d",&n);
    while(n>0){
        scanf("%s", word);
        insert(root, word);
        n--;
    }

//    printf("m:");
    scanf("%d",&m);
    while(m>0){
        scanf("%s", ask);
        printf("%d\n",search(root, ask));
        m--;
    }

    return 0;
}