#include<stdio.h>

void move(int no,int x,int y){
	if(no>1)
		move(no-1,x,6-x-y);
	printf("\n‰~”Õ[%d]‚ğ%d²‚©‚ç%d²‚ÖˆÚ“®\n",no,x,y);
	if(no>1)
		move(no-1,6-x-y,y);
}
int hano1_main(void){
	int n;
	printf("ƒnƒmƒC‚Ì“ƒ\n‰~”Õ‚Ì–‡”F");
	scanf_s("%d",&n);
	move(n,1,3);
	return 0;
}