#include<iostream>
using namespace std;
class point{
public:
	point();
	point(int row,int col);
	int get_x();
	int get_y();
private:
	int x,y;
};
point::point(){
	x=0;
	y=0;
}
point::point(int row,int col):x(row),y(col){
}
int point::get_x(){
	return x;
}
int point::get_y(){
	return y;
}
class line{
public:
	line(point start,point end);
	float slope();
private:
	point start,end;
};
line::line(point start_point,point end_point)
	:start(start_point),end(end_point){}
	
float line::slope(){
	int x1,y1,x2,y2;
	float slope;
	x1=start.get_x();
	y1=start.get_y();
	x2=end.get_x();
	y2= end.get_y();
	slope = static_cast<float>(y2-y1)/(x2-x1);
	return slope;
}
void cheak (line L1,line L2){
	if(L1.slope()*L2.slope()==-1){
		cout<<"´¹Ö±"<<endl;
	}else{
		cout<<"²»´¹Ö±"<<endl;
	} 
}
main(){
	point start1(0,1),end1(1,0);
	line L1(start1,end1); 
	point start2(0,0),end2(1,1);
	line L2(start2,end2);
	cheak(L1,L2);
	
}

