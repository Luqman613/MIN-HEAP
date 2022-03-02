#include<iostream>
using namespace std;

class Node{
	private:
		int data;
	public:
		void SetData(int data){
			this->data=data;
		}
		int GetData(){
			return data;
		}
};

class MinHeap{
	private:
		Node* arr;
		int size;
		int curentindex;
		
		bool isfull(){
			return curentindex==getsize();
		}
		bool isempty(){
			return curentindex==-1;
		}
		int parent(int index){
			return (index-1)/2;
		}
		int leftchild(int index){
			return (index*2)+1;
		}
		int rightchild(int index){
			return (index*2)+2;
		}
		int find(int key){
			if(isempty()){
				return -1;
			}else{
				int index=-1;
				for(int i = 0; i<=curentindex; i++){
					if(arr[i].GetData()==key){
						index=i;
						break;
					}
				}
				return index;
			}
		}
		public:
			MinHeap(){
				curentindex=-1;
				arr = new Node[getsize()];
			}
		void setsize(int size){
			this->size=size;
		}
		int getsize(){
			return size;
		}
		
		/* FOR INSERTION
		1/ check if the array is full, empty  or nither full nor empty.
		2/ if the array is full print "ARRAY IS FULL". 
		3/ if array is empty increment curent index with 1 and insert data at first index of array.
		4/ if array is nither full nor empty then increment curent index with 1 and insert data at that index.
		4.1/ declear a temporary veriable and initialize it with value of curent index and start a while loop until it become to 0.
		4.2/ check if the value at temp index is greater then its parent index or not until to the end of loop.
		4.2.1/ if temp index value is greater then swap it with parent value and update temp with index of its parent. 
		*/
		void insert(int data){
			if(isfull()){
				cout<<"TREE IS ALREADY FULL..!"<<endl;
			}else if(isempty()){
				curentindex +=1;
				arr[curentindex].SetData(data);
			}else{
				curentindex +=1;
				arr[curentindex].SetData(data);
				int temp=curentindex;
				while(temp!=0){
					if(arr[parent(temp)].GetData()>arr[temp].GetData()){
						int largest = arr[parent(temp)].GetData();
						arr[parent(temp)].SetData(arr[temp].GetData());
						arr[temp].SetData(largest);
					}
					temp=parent(temp);
				}
			}
		}
		
		/* FOR SEARCH
		1/ check if the array is empty or not.
		2/ if the array is empty print "ARRAY IS EMPTY".
		3/ if array is not empty then get a key from user and start a loop until to the curent index and compare it with data at all the indexes.
		3.1/ if data match with key at any index break the loop and return that index.
		3.2/ if loop end and key do not match with any index's data then return -1. 
		*/
		void search(int key){
			cout<<"______________________________________"<<endl;
			int index = find(key);
			if(index>0){
				cout<<"DATA IS IN NODE NUMBER: "<<index<<endl;
				cout<<"PARENT NODE DATA IS :"<<arr[parent(index)].GetData()<<endl;
				int left = leftchild(index);
				int right = rightchild(index);
				if(left<getsize()){
					cout<<"LEFT CHILD DATA IS : "<<arr[leftchild(index)].GetData()<<endl;
				}
				if(right<getsize()){
					cout<<"RIGHT CHILD DATA IS: "<<arr[rightchild(index)].GetData()<<endl;
				}
			}else if(index==0){
				cout<<"DATA IS AT ROOT NODE..!"<<endl;
				int left = leftchild(index);
				int right = rightchild(index);
				if(left<getsize()){
					cout<<"LEFT CHILD IS : "<<arr[leftchild(index)].GetData()<<endl;
				}
				if(right<getsize()){
					cout<<"RIGHT CHILD IS : "<<arr[rightchild(index)].GetData()<<endl;
				}
			}else{
				cout<<"DATA IS NOT PRESENT IN TREE..!"<<endl;
			}
			cout<<"______________________________________"<<endl;
		}
		
		/* FOR DISPLAY
		1/ check if the array is empty or not.
		2/ if the array is empty print "ARRAY IS EMPTY".
		3/ if array is not empty then start a loop until the curent index and print all indexes data. 
		*/
		void display(){
			cout<<"___________________________________"<<endl;
			if(isempty()){
				cout<<"TREE IS EMPTY"<<endl;
			}else{
				for(int i = 0; i<=curentindex; i++){
					cout<<"Data At Node "<<i<<" :"<<arr[i].GetData()<<endl;
				}
			}
			cout<<"___________________________________"<<endl;
		}
		
		/* FOR DELETION.
		1/ check if the array is empty or not.
		2/ if array is empty print "ARRAY IS ALREADY EMPTY".
		3/ if there are only one value in array then decrement curent index with 1.
		4/ if there are more then one value in array then replace root value with last value and decrement 1 in curent index.
		4.1/ start a loop until the curent index.
		4.2/ check wether the left childe of root is greater or right child is greater.
		4.2.1/ if left child is smaller then check if it is smaler then root or not.
		4.2.2/ if 4.2.1 is true then swap both values and make left child root for next iteration of loop. 
		4.3.1/ if right child is smaller then check if it smaller then root or not.
		4.3.2/ if 4.3.1 is true then swap both values and make right child root for next iteration of loop.
		4.4/ if both 4.2.1 and 4.3.1 are false the break the loop. 
		*/
		void delet(){
			cout<<"_________________________________"<<endl;
			if(isempty()){
				cout<<"TREE IS ALREADY EMPTY.."<<endl;
			}else if(curentindex==0){
				cout<<"DELETED NODE IS : "<<arr[0].GetData()<<endl;
				curentindex -=1;
			}else{
				cout<<"DELETED NODE IS : "<<arr[0].GetData()<<endl;
				arr[0].SetData(arr[curentindex].GetData());
				curentindex -=1;
				int largest;
				int smalest;
				int temp = 0;
				while(temp<curentindex){
					if(arr[leftchild(temp)].GetData()<=arr[rightchild(temp)].GetData() && arr[temp].GetData()>arr[leftchild(temp)].GetData()){
							largest = arr[temp].GetData();
							smalest = arr[leftchild(temp)].GetData();
							arr[temp].SetData(smalest);
							arr[leftchild(temp)].SetData(largest);
						if(leftchild(leftchild(temp))>curentindex){
								break;
							}else{
								temp = leftchild(temp);
							}
					}else if(arr[leftchild(temp)].GetData()>arr[rightchild(temp)].GetData() && arr[temp].GetData()>arr[rightchild(temp)].GetData()){
						
							largest = arr[temp].GetData();
							smalest = arr[rightchild(temp)].GetData();
							arr[temp].SetData(smalest);
							arr[rightchild(temp)].SetData(largest);
						
						if(rightchild(rightchild(temp))>curentindex){
								break;
							}else{
								temp = rightchild(temp);
							}
						}else{
							temp = curentindex;
						}
					}
				}
			}
	
};

int main(){
	MinHeap objHeap;
	int size,choice,data,key;
	cout<<"_____________MIN HEAP TREE______________"<<endl;
	cout<<"Enter Size Of Heap Tree :";cin>>size;
	objHeap.setsize(size);
		cout<<"FOR INSERTION PRESS /1"<<endl;
		cout<<"FOR DELETION PRESS  /2"<<endl;
		cout<<"FOR SEARCHING PRESS /3"<<endl;
		cout<<"FOR DISPLAY PRESS   /4"<<endl;
		cout<<"FOR QUIT PRESS      /0"<<endl;
	do{
	
		cout<<"_________________________________"<<endl;
		cout<<"ENTER YOUR CHOICE : ";cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter Data :";cin>>data;
				objHeap.insert(data);
				break;
			case 2:
				objHeap.delet();
				break;
			case 3:
				cout<<"Enter Key :";cin>>key;
				objHeap.search(key);
				break;
			case 4:
				objHeap.display();
				break;
			case 0:
				exit(0);
				break;
			default:
				cout<<"INVALID SELECTION.."<<endl;
		}
	}while(1);


	return 0;
}
