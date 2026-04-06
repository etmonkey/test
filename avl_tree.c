#include <stdio.h>
#include <stdlib.h>

#define LH (+1)
#define EH (0)
#define RH (-1)

typedef struct BSTNode {
    int    data;
    int     bf;
    struct BSTNode *lchild, *rchild;
} BSTNode;

void R_Rotate(BSTNode** p) {
    BSTNode* lc = (*p)->lchild;
    (*p)->lchild = lc->rchild;
    lc->rchild = (*p);
    (*p) = lc;
}

void L_Rotate(BSTNode** p) {
    BSTNode* rc = (*p)->rchild;
    (*p)->rchild = rc->lchild;
    rc->lchild = (*p);
    (*p) = rc;
}

void LeftBalance(BSTNode** T) {
    BSTNode* lc = (*T)->lchild;
    switch(lc->bf) {
        case LH:
            (*T)->bf = lc->bf = EH;
            R_Rotate(T); break;
        case RH:
            BSTNode* rd = lc->rchild;
            switch(rd->bf) {
                case EH: (*T)->bf = lc->bf = EH; break;
                case LH: (*T)->bf = RH; lc->bf = EH; break;
                case RH: (*T)->bf = EH; lc->bf = LH; break;
            }
            rd->bf = EH;
            L_Rotate(&lc); (*T)->lchild = lc;
            R_Rotate(T);
    }
}

void RightBalance(BSTNode** T) {
    BSTNode* rc = (*T)->rchild;
    switch(rc->bf) {
        case RH:
            (*T)->bf = rc->bf = EH;
            L_Rotate(T); break;
        case LH:
            BSTNode* ld = rc->lchild;
            switch(ld->bf) {
                case EH: (*T)->bf = rc->bf = EH; break;
                case LH: (*T)->bf = EH; rc->bf = RH; break;
                case RH: (*T)->bf = LH; rc->bf = EH; break;
            }
            ld->bf = EH;
            R_Rotate(&rc); (*T)->rchild = rc;
            L_Rotate(T);
    }
}

int InsertAVL(BSTNode** T, int e, int* taller) {
    if(!*T) {
        *T = (BSTNode*) malloc(sizeof(BSTNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL; (*T)->bf = EH; *taller = 1;
    }
    else {
        if(e == (*T)->data) {
            *taller = 0; return 0;
        } else if(e < (*T)->data) {
            if(!InsertAVL(&((*T)->lchild), e, taller)) return 0;
            if(*taller) {
                switch((*T)->bf) {
                    case LH:
                        LeftBalance(T); *taller = 0; break;
                    case EH:
                        (*T)->bf = LH; *taller = 1; break;
                    case RH:
                        (*T)->bf = EH; *taller = 0; break;
                }
            }
        } else{
            if(!InsertAVL(&((*T)->rchild), e, taller)) return 0;
            if(*taller) {
                switch((*T)->bf) {
                    case LH:
                        (*T)->bf = EH; *taller = 0; break;
                    case EH:
                        (*T)->bf = RH; *taller = 1; break;
                    case RH:
                        RightBalance(T); *taller = 0; break;
                }
            }
        }
    }
    return 1;
}

int main() {
    int e_arr[] = {13, 24, 37, 90, 53};
    BSTNode* root = NULL;
    int taller = 0;
    for(int i = 0; i<5; i++) {
        InsertAVL(&root, e_arr[i], &taller);
    }
}