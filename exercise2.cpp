//latihan tree

#include <iostream>
using namespace std;

struct simpul{
    int info;
    simpul* left;
    simpul* right;
};

typedef simpul* pointer;
typedef pointer tree;

void createSimpul (pointer& pBaru){
    pBaru= new simpul;
    cout << "Masukkan angka:"; cin >> pBaru->info;
    pBaru->left=NULL;
    pBaru->right=NULL;
}

void insertBST (tree& root, pointer pBaru){
    if (root == NULL){
        root = pBaru;
    }
    else if (pBaru->info < root->info){
        insertBST(root->left, pBaru);
    }
    else if (pBaru->info >= root->info){
        insertBST(root->right, pBaru); 
    }
    else {
        cout<<"Sudah ada"<<endl;
    }
}

void travPreorder (tree root){
    if (root != NULL){
        cout << root->info<<endl;
        travPreorder (root->left);
        travPreorder (root->right);
    }
}

void travInorder (tree root){
    if (root != NULL){
        travInorder (root->left);
        cout << root->info<<endl;
        travInorder (root->right);
    }
}

void travPostorder (tree root){
    if (root != NULL){
        travPostorder (root->left);
        travPostorder (root->right);
        cout << root->info <<endl;
    }
}

/*
void travLevelorder (tree root){
    int h = kedalaman(root);
    for (int i=1; i<=h; i++){
        cout<<i<<": ";
        givenLevel(root,i);
        cout<<endl;
    }
}
 */

int kedalaman(tree root){
    if(root==NULL){
        return 0;
    }
    else{
        int tLeft = kedalaman(root->left);
        int tRight = kedalaman(root->right);
        if (tLeft > tRight) return (tleft+1);
        else return (tRight+1);
    }
}

void levelT(tree root, int level){
    if (root==NULL)
        return;
    if (level==1)
        cout<<root->info<<" ";
    else if (level>1){
        levelT(root->left,level-1);
        levelT(root->right,level-1);
    }
}

void anakOrtu(tree root, pointer pBaru){
    pBaru = root;
    if(pBaru != NULL){
        cout<<"Orangtua : "<<pBaru->info<<endl;
        cout<<"Anak : "<<endl;
        if(pBaru->left==NULL){
            cout<<"Kiri : Tidak Ada"<<endl;
        }
        else{
            cout<<"Kiri : "<<pBaru->left->info<<endl;
        }
            
        
        if(pBaru->right==NULL){
            cout<<"Kanan : Tidak Ada"<<endl;
        }
        else {
            cout<<"Kanan : "<<pBaru->right->info<<endl;
        }
        
        cout<<endl;
        anakOrtu(root->left, pBaru);
        anakOrtu(root->right, pBaru);
    }
}

int main (){
    tree t;
    pointer p;
    
    cout<<"Menu"<<endl;
    cout<<"1. Insert Data"<<endl;
    cout<<"2. Traversal Preorder"<<endl;
    cout<<"3. Traversal Inorder"<<endl;
    cout<<"4. Traversal Postorder"<<endl;
    cout<<"5. Cetak Kedalaman"<<endl;
    cout<<"6. Cetak Level"<<endl;
    cout<<"7. Banyak Anak"<<endl;
    cout<<"8. exit"<<endl;
    cout<<"Pilihan: "; cin>>pil;
    cout<<endl;
    
    if (pil==1){
        cout<<"Insert Data"<<endl;
        createSimpul(p);
        insertBST(t, p);
    }
    else if (pil==2){
        cout<<"Traversal PreOrder"<<endl;
        travPreorder(t);
        cout<<endl;
    }
    else if (pil==3){
        cout<<"Traversal InOrder"<<endl;
        travInorder(t);
        cout<<endl;
    }
    else if (pil==4){
        cout<<"Traversal PostOrder"<<endl;
        travPostorder(t);
        cout<<endl;
    }
    else if (pil==5){
        cout<<"Kedalaman"<<endl;
        kedalaman(t);
        cout<<endl;
    }
    else if (pil==6){
        cout<<"Level / Tingkatan"<<endl;
        levelT(t);
        cout<<endl;
    }
    else if (pil==7){
        cout<<"Anak"<<endl;
        anakOrtu(t);
        cout<<endl;
    }
    else if (pil==8){
        return 0;
    }
    
}
