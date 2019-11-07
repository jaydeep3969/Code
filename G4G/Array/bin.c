#include <stdio.h>

typedef unsigned long long int ulli;

struct node {
    ulli x;
    ulli count;
    struct node* l;
    struct node* r;
}*root;

// void inorder(struct node *root){
//     if(root -> l)  
//         inorder(root -> l);
    
// 	printf("%d ", root->x);
//     //cout << root -> x << " ";
    
//     if(root -> r)
//         inorder(root -> r);
// }

void insert(struct node* root, ulli i){
    
    if(root -> x  == i)
        root -> count += 1;
    else if(root -> x < i){
        //cout << i << " :In right" << "\n";
        if(root -> r != NULL)
            insert(root->r, i);
        else{
          //  cout << i << " :New right" << "\n";
            struct node n;
			n.x = i;
			n.count = 0;
			n.l = n.r = NULL;
            root -> r = &n;
            return;
        }
    }
    else {
        //cout << i << " :In Left" << "\n";
        if(root -> l != NULL)
            insert(root->l, i);
        else{
            //cout << i << " :New Left" << "\n";
            //struct node n = {i, 0, NULL, NULL};
            struct node n;
			n.x = i;
			n.count = 0;
			n.l = n.r = NULL;
			root -> l = &n;
            
            //cout  << (root -> l -> x) << " " << (root-> l -> l) << "\n";
            return;
        }
    }
}

int main() {
    int t;
    ulli n;
    
    scanf("%d",&t);
    
    while(t--){
        scanf("%d",&n);
        
        ulli i;
        scanf("%d",&i);
        n--;
        
        struct node tmp;
		tmp.x = i;
		tmp.count = 0;
		tmp.l = tmp.r = NULL;
        root = &tmp;
        
        while(n--){
            scanf("%d",&i);
            insert(root, i);
        }
        
        // inorder(root);
    }   
	return 0;
}
