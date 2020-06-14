#include <iostream>
#include "team.h"
#include <string>
#include <iomanip>
using namespace std;

void team::appendNode(string n, int w, int l,double wp){
	ListNode *newNode;
	ListNode *nodeptr;

	newNode = new ListNode;
	newNode->name = n;
  newNode->wins = w;
  newNode->losses = l;
  newNode->win_percentage = wp;
	newNode ->next = nullptr;

	if (!head){
		head = newNode;
	}
	else {
		nodeptr = head;

		while (nodeptr ->next){
			nodeptr = nodeptr->next;
		}
    
		nodeptr->next = newNode;
	}
}

void team::displaylist() const{
	ListNode *nodeptr;

	nodeptr = head;

	while(nodeptr){
    cout << setprecision(3) << fixed;
		cout << nodeptr->name << endl << nodeptr->wins << "-" << nodeptr->losses << "            " << nodeptr->win_percentage << endl;
		nodeptr = nodeptr->next;
	}

}

void team::displayWinningTeams() const{
	ListNode *nodeptr;

	nodeptr = head;

	while(nodeptr){
    if (nodeptr->win_percentage > .500){
      cout << setprecision(3) << fixed;
      cout << nodeptr->name << endl << nodeptr->wins << "-" << nodeptr->losses << "            " << nodeptr->win_percentage << endl;
    }
    nodeptr = nodeptr->next;
	}

}

bool team::exists(string n){
	ListNode *nodeptr;
  bool status;
	nodeptr = head;

	while(nodeptr){
	  if (nodeptr->name == n){
      return true;
    }
		nodeptr = nodeptr->next;
	}
  return false;
}

team::ListNode* team::returnNode(string n){
	ListNode *nodeptr;
  ListNode *empty;
	nodeptr = head;
  empty = new ListNode;
	empty->name = "";
  empty->wins = 0;
  empty->losses = 0;
  empty->win_percentage = 0;
	while(nodeptr){
		if (nodeptr->name == n){
      return nodeptr;
    }
    nodeptr = nodeptr->next;
	}
  cout << "Node Does not exist" << endl;
  cout << "returning Empty Node" << endl;
  return empty;

}

void team::editNode(string n, int w, int l,double wp){
	ListNode *newNode;
	ListNode *nodeptr;
	ListNode *previousNode = nullptr;

	if (!head){
    appendNode(n, w, l, wp);
	}
	else{
		nodeptr = head;
		previousNode = nullptr;

		while(nodeptr != nullptr && nodeptr->name != n){
			previousNode = nodeptr;
      nodeptr = nodeptr->next;
		}
	  
		if (nodeptr->next == nullptr && nodeptr->name != n){
      appendNode(n, w, l, wp);
    }
		else {
      nodeptr->name = n;
      nodeptr->wins = w;
      nodeptr->losses = l;
      nodeptr->win_percentage = wp;
		}
	}
}

void team::deleteNode(string n, int w, int l,double wp){
	ListNode *nodeptr;
	ListNode *previousNode;

	if (!head)
	  {return;}
  if (head->win_percentage == wp){
		nodeptr = head->next;
		delete head;
		head = nodeptr;
	}
	else {
		nodeptr = head;

		while (nodeptr != nullptr && nodeptr->win_percentage != wp){
			previousNode = nodeptr;
			nodeptr = nodeptr->next;
		}
		if (nodeptr){
			previousNode->next = nodeptr->next;
			delete nodeptr;
		}
	}
}

team::~team(){
	ListNode *nodeptr;
	ListNode *nextNode;

	nodeptr = head;

	while (nodeptr != nullptr){
		nextNode = nodeptr->next;
		delete nodeptr;
		nodeptr = nextNode;
	}
}


