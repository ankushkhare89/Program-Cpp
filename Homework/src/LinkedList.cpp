#include <iostream>
#include "LInkedList.h"
#include "Patterns.h"
using namespace std;

//----------------------------------------------------------------------------------------------

static struct Node * HeadAddress;

struct Node {
	int Id;
	string pat, addr, flag;
	Node* next;
};
//----------------------------------------------------------------------------------------------

// only for the 1st Node
void initNode(struct Node *head,int id, string Pat, string Addr, string Flag){

	head->Id = id;
	head->pat = Pat;
	head->addr = Addr;
	head->flag = Flag;
	head->next =NULL;
}
//----------------------------------------------------------------------------------------------

// adding new node to linklist
void addNode(struct Node *head, int id, string Pat, string Addr, string Flag) {
	Node *newNode = new Node;
	newNode->Id = id;
	newNode->pat = Pat;
	newNode->addr = Addr;
	newNode->flag = Flag;
	newNode->next = NULL;

	Node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}
//----------------------------------------------------------------------------------------------

//return the node address of the node containing id
bool searchNode(int id, string Pat, string Addr, string Flag ) {
	Node *cur = HeadAddress;
	while(cur) {
		if(cur->Id == id){
			if(cur->pat == Pat){
				if(cur->addr == Addr){
					if(cur->flag == Flag){
						return 1;
					}
				}
			}
		}
		cur = cur->next;
	}
	return 0;
}
//----------------------------------------------------------------------------------------------

// Display the contents of link list
void displayAll() {

	Node *list = HeadAddress;
		while(list) {
			cout << list->Id << " "<<list->pat << " "<<list->addr <<" "<<list->flag << endl;
			list = list->next;
		}
		cout << endl;
		cout << endl;
}
//----------------------------------------------------------------------------------------------

// Display pattern names based on flags
void displayPatternWithFlags(int choice){
	Node *list = HeadAddress;
	while(list) {
		switch(choice){
		case 1:
			if(list->flag == "true"){
				cout <<list->pat <<" ";
				show_pattern(list->pat);
			}
		break;
		case 2:
			if(list->flag == "false"){
				cout <<list->pat <<" ";
				show_pattern(list->pat);
			}
		break;
		default:
			cout<<"invalid input"<<endl;
			return;
		break;
		}
		list = list->next;
	}
	cout << endl;
	cout << endl;
}
//----------------------------------------------------------------------------------------------

// function called from outside to insert elements in link list
void addLinklist(int id, string pat, string addr, string flag){
	static int count = 1;
	if(count ==1){
		initNode(HeadAddress, id, pat, addr, flag);
		count++;
	}else{
		addNode(HeadAddress, id, pat, addr, flag);
	}
}
//----------------------------------------------------------------------------------------------
// new link list created, store the head address for other functions
void createLinklist(){
	struct Node *head = new Node;
	HeadAddress = head;
}
//----------------------------------------------------------------------------------------------
