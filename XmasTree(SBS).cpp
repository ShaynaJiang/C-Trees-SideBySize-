#include <stdio.h>
//未更改顏色版本 
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
        printf("請輸入三顆聖誕葉的高度(介於3~13的奇數並用空格隔開)： ");
        scanf("%d %d %d", &tree_H[0], &tree_H[1], &tree_H[2]);
        for (i=0; i<3; i++) {
            if (tree_H[i] < 3 || tree_H[i] > 13 || tree_H[i]%2 == 0) {
                printf("輸入錯誤，請重新輸入：\n");
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

