#include<stdio.h>
#include<string.h>
#include<limits.h>
char *nspace(char *s,int n){
	//n個のスペース文字を返す
	int i;
	for(i=0;i<n;i++){
		s[i]=' ';
	}
	s[i]='\0';
	return s;
}
//表示用
int bm_print(const char txt[], const char pat[],int txt_len,int pat_len,int pt,int pp) {
	char *r;//記号表示用
	char *space1=" ";//スペース文字1
	char *space2=" ";//スペース文字2
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
	
		printf("%s pt=%d pp=%d\n",txt,pt,pp);//テキスト
	
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
		
		printf("\t%s%s\t",nspace(s,x),r);//比較位置
		printf("\n");
		printf("\t%s%s\t",nspace(s,y),pat);//パターン
		printf("\n");

}
//Boyer-Moore法による文字列探索（探索過程の詳細を表示）
int bm_match(const char txt[], const char pat[]) {
	int pt;//txtをなぞるカーソル
	int pp;//patをなぞるカーソル
	int txt_len = strlen(txt);//txtの文字数
	int pat_len = strlen(pat);//patの文字数
	int skip[UCHAR_MAX + 1];//スキップテーブル
	//int i,cnt;
	//スキップテーブルの作成
	for (pt = 0; pt <= UCHAR_MAX; pt++) {
		skip[pt] = pat_len;
	}
	for (pt = 0; pt < pat_len - 1; pt++) {
		skip[pat[pt]] = pat_len - pt - 1;
	}

	while (pt < txt_len) {
		pp = pat_len - 1;//patの最後の文字に着目
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
	char s1[80];//テキスト用
	char s2[80];//パターン用
	int cnt= 0;
		
	//puts("s1617118 田代純一");
	puts("Boyer-Moore法");

	//テキスト出力
	printf("テキスト:");
	scanf_s("%s",s1,sizeof(s1));

	//パターン出力
	printf("パターン:");
	scanf_s("%s",s2,sizeof(s2));

	//文字列s1から文字列s2をBoyer-Moore法で探索
	idx=bm_match(s1,s2);

	//パターンが存在するか判定の表示
		if(idx==-1)
		puts("テキスト中にパターンが存在していません。\n");
	
	else
		printf("%d文字目にマッチします。\n",idx+1);

return 0;
}
