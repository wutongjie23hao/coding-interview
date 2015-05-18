#1014 trie树
##输入
输入的第一行为一个正整数n，表示词典的大小，其后n行，每一行一个单词（不保证是英文单词，也有可能是火星文单词哦），单词由不超过10个的小写英文字母组成，可能存在相同的单词，此时应将其视作不同的单词。接下来的一行为一个正整数m，表示小Hi询问的次数，其后m行，每一行一个字符串，该字符串由不超过10个的小写英文字母组成，表示小Hi的一个询问。

在20%的数据中n, m<=10，词典的字母表大小<=2.

在60%的数据中n, m<=1000，词典的字母表大小<=5.

在100%的数据中n, m<=100000，词典的字母表大小<=26.

##输出
对于小Hi的每一个询问，输出一个整数Ans,表示词典中以小Hi给出的字符串为前缀的单词的个数。
##样例输入
	5
	babaab
	babbbaaaa
	abba
	aaaaabaa
	babaababb
	5
	babb
	baabaaa
	bab
	bb
	bbabbaab
##样例输出
	1
	0
	3
	0
	0
##代码
```c++
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
```