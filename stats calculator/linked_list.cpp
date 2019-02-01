#include "linked_list.h"

Node::Node() {
	this->pNext = nullptr;
	this->pPre = nullptr;
	this->value = -1;
}
Node::~Node() {
	delete(pNext);
	delete(pPre);
}
double Node::get_value() {
	return this->value;
}
void Node::set_value(double v) {
	this->value = v;
}

Node* Node::get_pPre() {
	return pPre;

}
Node* Node::get_pNext() {
	return pNext;
}

void Node::set_pPre(Node* pre) {
	pPre = pre;
}
void Node::set_pNext(Node* next) {
	pNext = next;

}

//list==================================================

list::list(){
	this->size = 0;
	this->pHead = nullptr;
	this->pTail = nullptr;
}
list::~list() {
	
	erase_all();
}

Node* list::makeNode(double v) {

	Node* newNode=new(Node);
	newNode->set_value(v);
	return newNode;

}

void list::insert(double v) {
	
	Node* temp = makeNode(v);
	if (size == 0) {
		pHead = temp;
		pTail = temp;
		size++;
	}
	else if(size==1){

		pHead->set_pNext(temp);
		temp->set_pPre(pHead);
		pTail = temp;
		size++;
	}
	else {
		pTail->set_pNext(temp);
		temp->set_pPre(pTail);
		pTail = temp;
		size++;
	}
}

void list::insert_inorder(double v) {
	Node* temp = makeNode(v);
	if (size == 0) {
		pHead = temp;
		pTail = temp;
		size++;
	}
	else if (size == 1) {
		if (temp->get_value() <= pHead->get_value()) {
			temp->set_pNext(pHead);
			pHead->set_pPre(temp);
			pHead = temp;
	}
		else {
			pTail->set_pNext(temp);
			temp->set_pPre(pTail);
			pTail = temp;
		}

		size++;
	}
	else {
		Node* pCur = pHead;
		if (temp->get_value() < pHead->get_value()) {
			temp->set_pNext(pHead);
			pHead->set_pPre(temp);
			pHead = temp;
		}
		else if (temp->get_value() > pTail->get_value()) {
			pTail->set_pNext(temp);
			temp->set_pPre(pTail);
			pTail = temp;
		}
		else {
			while (pCur->get_pNext() != nullptr&&pCur->get_value() <= temp->get_value()) {
				pCur = pCur->get_pNext();
			}
			Node* pnew = pCur->get_pPre();
			temp->set_pNext(pCur);

			pnew->set_pNext(temp);

			temp->set_pPre(pnew);
			pCur->set_pPre(temp);
		}
		size++;
	}



	/*if (size == 0) {
		pHead = temp;
		pTail = temp;
		size++;
	}
	else if (size == 1) {
		if (pHead->get_value() >= temp->get_value()) {
			temp->set_pNext(pTail);
			pTail->set_pPre(temp);
			pHead = temp;
		}
		else {
			pHead->set_pNext(temp);
			temp->set_pPre(pHead);
			pTail = temp;
		}
		size++;
	}*/


}

void list::erase_all() {// code later

}

double list::get_pos(int p) {
	Node* pCur = pHead;
	if (p <= size) {
		for (int i = 0; i < p; i++) {
			pCur = pCur->get_pNext();
		}
		return pCur->get_value();
	}
	return-1;
}

int list::get_size() {
	return size;
}



void list::set_size() {

	
	}


Node* list::getHead() {

	return this->pHead;
}