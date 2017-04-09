#include<stdio.h>
#include<string.h>
#include<limits.h>
char *nspace(char *s,int n){
	//n�̃X�y�[�X������Ԃ�
	int i;
	for(i=0;i<n;i++){
		s[i]=' ';
	}
	s[i]='\0';
	return s;
}
//�\���p
int bm_print(const char txt[], const char pat[],int txt_len,int pat_len,int pt,int pp) {
	char *r;//�L���\���p
	char *space1=" ";//�X�y�[�X����1
	char *space2=" ";//�X�y�[�X����2
	char s[128];
	int x,y,k;
	int i=0;

	if (pp != pat_len - 1){
		printf("\t");
	}
	else {
		printf("%d\t", pt - pp);
		k = pt - pp;
	}
	
		printf("%s pt=%d pp=%d\n",txt,pt,pp);//�e�L�X�g
	
		if(txt[pt]==pat[pp]){
			r="+";
			x=pt;
			y=pt-pp;
			pt++;
			pp++;
			
		}
		else{
			r="|";
			x=pt;
			y=pt-pp;
			pt=pt-pp+1;
			pp=0;

		}
		
		printf("\t%s%s\t",nspace(s,x),r);//��r�ʒu
		printf("\n");
		printf("\t%s%s\t",nspace(s,y),pat);//�p�^�[��
		printf("\n");

}
//Boyer-Moore�@�ɂ�镶����T���i�T���ߒ��̏ڍׂ�\���j
int bm_match(const char txt[], const char pat[]) {
	int pt;//txt���Ȃ���J�[�\��
	int pp;//pat���Ȃ���J�[�\��
	int txt_len = strlen(txt);//txt�̕�����
	int pat_len = strlen(pat);//pat�̕�����
	int skip[UCHAR_MAX + 1];//�X�L�b�v�e�[�u��
	//int i,cnt;
	//�X�L�b�v�e�[�u���̍쐬
	for (pt = 0; pt <= UCHAR_MAX; pt++) {
		skip[pt] = pat_len;
	}
	for (pt = 0; pt < pat_len - 1; pt++) {
		skip[pat[pt]] = pat_len - pt - 1;
	}

	while (pt < txt_len) {
		pp = pat_len - 1;//pat�̍Ō�̕����ɒ���
		while (bm_print(txt,pat,txt_len,pat_len,pt,pp),txt[pt] == pat[pp]){
	
			// match
			if (pp == 0)  
				// last match
			
				return pt;
			
			pp--;
			pt--;
		}
		// unmatch
		pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;

    
	}
	return -1;
}

int main(void){
		int idx;
	char s1[80];//�e�L�X�g�p
	char s2[80];//�p�^�[���p
	int cnt= 0;
		
	//puts("s1617118 �c�㏃��");
	puts("Boyer-Moore�@");

	//�e�L�X�g�o��
	printf("�e�L�X�g:");
	scanf_s("%s",s1,sizeof(s1));

	//�p�^�[���o��
	printf("�p�^�[��:");
	scanf_s("%s",s2,sizeof(s2));

	//������s1���當����s2��Boyer-Moore�@�ŒT��
	idx=bm_match(s1,s2);

	//�p�^�[�������݂��邩����̕\��
		if(idx==-1)
		puts("�e�L�X�g���Ƀp�^�[�������݂��Ă��܂���B\n");
	
	else
		printf("%d�����ڂɃ}�b�`���܂��B\n",idx+1);

return 0;
}
