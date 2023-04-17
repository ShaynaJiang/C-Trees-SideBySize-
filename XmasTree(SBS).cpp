#include <stdio.h>
//������C�⪩�� 
void print_tree(int height, int row){
	int i; 
	if(row < height){ 
		//drow leaves
		for(i=1-height; i<height; i++){
			printf(-row<=i && i<=row ? "*" : "-"); 
		}
	}
	else if(row < height+height/2){
		//drow drunk
		for(i=1-height; i<height; i++){
			printf(i==0 ? "*" : "-");
		}
	}
	//print empty
	else
		for(i=1-height; i<height;i++){
			putchar(' ');
		}	
}

int main() {
    int tree_H[3], is_repeat=0, i, H, count_row;
    do{
        printf("�п�J�T���t�ϸ�������(����3~13���_�ƨåΪŮ�j�})�G ");
        scanf("%d %d %d", &tree_H[0], &tree_H[1], &tree_H[2]);
        for (i=0; i<3; i++) {
            if (tree_H[i] < 3 || tree_H[i] > 13 || tree_H[i]%2 == 0) {
                printf("��J���~�A�Э��s��J�G\n");
                is_repeat = 1;
            }
            else
            	is_repeat = 0;
        }
    }while (is_repeat); 
    
	//find the max height 
	int max = 0;
    for (i=0; i<3; i++) {
        if (tree_H[i] > max) {
            max = tree_H[i];
        }
    }
    
	//total rows
	int nRows = max + max/2;
	    
    //print tree
    for(count_row=0; count_row<nRows; count_row++){
    	for(H=0; H<3; H++){
    		if(H>0){
    			putchar(' ');
			}
			print_tree(tree_H[H], count_row);
		}
		printf("\n");
	}
    
    return 0;
}

