#include<stdio.h>
#include<assert.h>

typedef struct {
  int pc;
  int *arr, *reg, start, end;
  int len, mid, start1, start2, end1, end2;
} Frame;

#define call(...) ({ *(++top) = (Frame) { .pc = 0, __VA_ARGS__ }; })
#define ret()     ({ top--; })
#define goto(loc) ({ f->pc = (loc) - 1; })

void merge_sort_iter_stack(int *arr, int *reg, int start, int end) {
    Frame stk[64], *top = stk - 1;
    call(arr, reg, start, end);
    for(Frame *f; (f=top) >= stk; f->pc++) {
        f->len = f->end - f->start;
        f->mid = (f->len >> 1) + f->start;
        switch(f->pc) {
            case 0: if (f->start >= f->end) goto(4); break;
            case 1: 
                f->start1 = f->start; f->end1 = f->mid;
                call(f->arr, f->reg, f->start1, f->end1);
                break;
            case 2: 
                f->start2 = f->mid + 1; f->end2 = f->end;
                call(f->arr, f->reg, f->start2, f->end2);
                break;
            case 3: 
                int k = f->start;
                while (f->start1 <= f->end1 && f->start2 <= f->end2)
                    (f->reg)[k++] = (f->arr)[f->start1] < (f->arr)[f->start2] ? (f->arr)[(f->start1)++] : (f->arr)[(f->start2)++];
                while (f->start1 <= f->end1)
                    (f->reg)[k++] = (f->arr)[(f->start1)++];
                while (f->start2 <= f->end2)
                    (f->reg)[k++] = (f->arr)[(f->start2)++];
                for (k = f->start; k <= f->end; k++)
                    (f->arr)[k] = (f->reg)[k];
                break;
            case 4: ret(); break;
            default: assert(0);
        }
    }
}

void merge_sort(int arr[], const int len) {
    int reg[len];
    merge_sort_iter_stack(arr, reg, 0, len - 1);
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    merge_sort(arr, 7);
    for(int i=0; i<7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 1;
}
