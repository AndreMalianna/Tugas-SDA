#include <iostream>
#define max 5

using namespace std;
string data[max];
int top = 0;

bool isFull(){
	if(top >= max){
		return true;
	} else{
		return false;
	}
}

bool isEmpty(){
	if(top == 0){
		return true;
	} else {
		return false;
	}
}

void view(){
	if(!isEmpty()){
		cout << "Data Antrian: " << endl;
		for(int a = top - 1; a >= 0; a--){
			cout << a + 1 << ". " << data[a] << endl;
		}
	} else {
		cout << "Antrian Kosong" << endl;
	}
	
	if(isFull()){
		cout << "Antrian Penuh" << endl;
	}
	cout << endl;
}

void enqueue(){
	if(!isFull()){
		cout << "Masukkan Data: ";
		cin >> data[top];
		top ++;
	}
}

void dequeue(){
	if(!isEmpty()){
		for(int a = 0; a < top - 1; a++){
			data[a] = data[a + 1];
		}
		top--;
	}
}

int main(){
	int pil;
	string isi;
	
	queue:
		system("cls");
		view();
		cout << "Menu Utama\n1. Enqueue\n2. Dequeue\n";
		cout << "Pilihan: ";
		cin >> pil;
	
	if(pil == 1){
		system("cls");
		enqueue();
		goto queue;
	} else if (pil == 2){
		system ("cls");
		dequeue();
		goto queue;
	}
	
}