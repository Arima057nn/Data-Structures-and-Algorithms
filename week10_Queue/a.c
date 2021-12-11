#include<stdio.h>


void bai1(){
	char a[100];
	char b[100];
	char c[100];
	char d;
	printf("nhap vao ten sinh vien : ");
	d = getchar();
	gets(a);
	printf("nhap vao ma sinh vien : ");
	d = getchar();
	gets(b);
	printf("nhap vao diem cua sinh vien :");
	gets(c);	
	printf("\nten cua sinh vien la : %s\n",a);
	printf("ma sinh vien la : %s\n",b);
	printf("diem cua sinh vien la : %s\n",c);
}
void bai2(){
	int n;
	printf("xin moi nhap vao so n : ");
	scanf("%d",&n);
	int tong = 0;
	if(n % 2 == 0){
		printf("n la so chan :\n");
		}else{
			printf("n la so le :\n");
		}
	for(int i = 1; i <= n; i++){
		tong += i;
	}
	printf("tong cac so tu 1 den n la : %d\n",tong);
}

int main(){
	while(1){
		int chon;
		printf("\t1.thong tin sinh vien\n");
		printf("\t2.so nguyen\n");
		printf("\t3.so tv\n");
		scanf("%d",&chon);
	switch(chon){
		case 1:
			bai1();
			break;
		case 2:
			bai2();
			break;
		}
	}
}
