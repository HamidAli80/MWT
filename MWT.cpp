// The code is written by Hamid Ali
// A greedy approach for minimum weight triangulation is implemented
// It takes two arrays for coordinate points of a convex polygon
// It generates two minimum weight triangulations using clock wise and Anti-clock wise direction

#include<stdlib.h>
#include<iostream>
#include<conio.h> 
#include<cmath>
#include<graphics.h>
using namespace std;
class node { 
		public: 
				int data_x;
				int data_y;
				node *next; 
	};

class List { 
			int item;
			node *head;
			node *tail;
			node *minimum_edge_start;
		public: 
			List( ); 
			void minimum_edge(); 
			void insert(int, int); 
			void mwt(int); 
		//	void delete_end( ); 
			void display( ); 
		//	int node_count(); 
		//	void delete_before_pos();
		//	void delete_after_pos(); 
		};

List::List( ) { 
				head = NULL;
				tail = NULL;
			} 
//code to insert an item at end of List
void List::insert(int a, int b) { 
							node *temp = new node; 
							temp->data_x = a;
							temp->data_y = b;  
							temp->next = NULL; 
							if(head == NULL) {
											 head = temp;
											 tail = temp;
											 tail->next = head;
											} 
										else 
											{ 
											 	temp -> next = tail -> next;
   												tail -> next = temp;
   												tail = temp; 												 	 
											} 
//										cout<<"\nInserted an element at end of Linked List Sucesfully....\n"; 
						} 

void List::display() { 
						node *t; 
						if(head==NULL) 
							cout<<"\nList Under Flow"; 
						else 
							{ 
//								cout<<"Points of polygone are....\n"; 
								t = head; 
								while(t != tail) { 
									cout<<"("<<t->data_x <<", "<<t->data_y<<"), "; 
									t = t->next; 
								} 
								cout<<"("<<tail->data_x <<", "<<tail->data_y<<")";
							} 
					}

void List::minimum_edge(){
	double minimum_edge = 1000000;
	double distance;
	node *t1;
	node *t2;
	t1 = head;
	t2 = t1->next;
	minimum_edge_start = t1;
	cout<<endl;
	while(t1 != tail){
		distance = sqrt(pow((t2->data_x - t1->data_x),2) + pow((t2->data_y - t1->data_y),2));
		//cout<<"distance "<<distance<<endl;
		if(distance < minimum_edge){
			minimum_edge = distance;
			minimum_edge_start = t1;
		}
		t1 = t2;
		t2 = t1->next;
	}
	distance = sqrt(pow((t2->data_x - t1->data_x),2) + pow((t2->data_y - t1->data_y),2));
	//cout<<"distance "<<distance<<endl;
	if(distance < minimum_edge){
		minimum_edge = distance;
		minimum_edge_start = t1;
	}
//	cout<<"Starting point of minimum edge of polygon is (";
//	cout<<minimum_edge_start->data_x;
//	cout<<", ";
//	cout<<minimum_edge_start->data_y;
//	cout<<")";
}

void List::mwt(int size_polygon){
	double mwt1 = 0;
	int i = 0;
	node *t1;
	node *t2;
	node *t3;
	node *t4;
	double distance_1, distance_2;
	t1 = minimum_edge_start;
	t2 = t1->next;
	t3 = t2->next;
	t4 = t3->next;
	while(i < (size_polygon - 3)){
		distance_1 = sqrt(pow((t3->data_x - t1->data_x),2) + pow((t3->data_y - t1->data_y),2));
//		cout<<"\n"<<distance_1;
		distance_2 = sqrt(pow((t4->data_x - t2->data_x),2) + pow((t4->data_y - t2->data_y),2));
//		cout<<"\n"<<distance_2;
		if(distance_1 < distance_2){
			setlinestyle(1,0,3);
			line(t1->data_x,t1->data_y,t3->data_x,t3->data_y);
			node *temp = t2;
			t1->next = t3;
//			cout<<endl;
//			cout<<"("<<t1->data_x <<", "<<t1->data_y<<"), ";
			t2 = t3;
//			cout<<"("<<t2->data_x <<", "<<t2->data_y<<"),";
			t3 = t4;
//			cout<<"("<<t3->data_x <<", "<<t3->data_y<<"), ";
			t4 = t4->next;
//			cout<<"("<<t4->data_x <<", "<<t4->data_y<<"), ";
//			cout<<"Delete ("<<temp->data_x <<", "<<temp->data_y<<")";
			delete(temp);
			mwt1 = mwt1 + distance_1;
		}
		else{
			setlinestyle(1,0,3);
			line(t2->data_x,t2->data_y,t4->data_x,t4->data_y);
			node *temp = t3;
			t2->next = t4;
			t1 = t2;
//			cout<<endl;
//			cout<<"("<<t1->data_x <<", "<<t1->data_y<<"), ";
			t2 = t4;
//			cout<<"("<<t2->data_x <<", "<<t2->data_y<<"),";
			t3 = t4->next;
//			cout<<"("<<t3->data_x <<", "<<t3->data_y<<"), ";
			t4 = t3->next;
//			cout<<"("<<t4->data_x <<", "<<t4->data_y<<"), ";			
//			cout<<"Delete ("<<temp->data_x <<", "<<temp->data_y<<")";
			delete(temp);
			mwt1 = mwt1 + distance_2;
		}
		i++;
	}
	cout<<"\n\tThe Total Length of Minimum Weight Triangulation is "<<mwt1<<endl;
}
int main( ) { 
	int size_polygon = 5;
//	int x[size_polygon] = {7,10,13,15,15,14,10,6,3,1,1,2,4};
//	int y[size_polygon] = {1,1,3,6,9,13,15,15,13,10,7,4,2};
	
	int x[size_polygon] = {152, 216, 540, 619, 398};
	int y[size_polygon] = {90, 326, 324, 160, 9};

//----------------------------------------------------------------	
// Creating a Graph in Anti clock wise			
	initwindow(800, 800);
	setlinestyle(0,3,3);
	for(int i = 0; i<size_polygon-1; i++){
		line(x[i], y[i],x[i+1], y[i+1]);
	}
	
//    outtextxy(x[0]-40,y[0]-20,"(x1, y1)");
	line(x[0], y[0],x[size_polygon-1], y[size_polygon-1]);
//----------------------------------------------------------------
	
	List CWL, ACWL; 
	for(int i = 0; i <size_polygon; i++){
		CWL.insert(x[i], y[i]);
	}
	cout<<"Points of polygone are....\n";
	CWL.display( );
	CWL.minimum_edge();
	cout<<"\nClock Wise Method:"<<endl;
	CWL.mwt(size_polygon);
//----------------------------------------------------------------	
// Creating a Graph in Anti clock wise	
	initwindow(800, 800);
	setlinestyle(0,3,3);
	for(int i = 0; i<size_polygon-1; i++){
		line(x[i], y[i],x[i+1], y[i+1]);
	}
	line(x[0], y[0],x[size_polygon-1], y[size_polygon-1]);
//--------------------------------------------------------------	
	for(int i = size_polygon-1; i >= 0; i--){
		ACWL.insert(x[i], y[i]);
	}

	ACWL.minimum_edge();
	cout<<"\nAnti Clock Wise Method:"<<endl;
	ACWL.mwt(size_polygon);	
	getch();				
}

