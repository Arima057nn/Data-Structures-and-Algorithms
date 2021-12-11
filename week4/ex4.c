#include <stdio.h>

typedef struct point{
  int x;
  int y;

} point;

typedef struct circle{
  point A;
  int R;

} circle;

int is_circle(circle *p,point *w){
  if( ((w->x - p->A.x)*(w->x - p->A.x) + (w->y - p->A.y)*(w->y - p->A.y)) < p->R * p->R){
    return 1;
  }
  else return 0;
}
int main(){
  circle  O;
  point A;
  printf("Nhap toa do cua tam 0 la: ");
  scanf("%d%d",&O.A.x,&O.A.y);
  printf("Nhap toa do cua diem A la: ");
  scanf("%d%d",&A.x,&A.y);
  printf("Nhap ban kinh: ");
  scanf("%d",&O.R);
  printf("return  %d",is_circle(&O,&A));
  return 0;
}
