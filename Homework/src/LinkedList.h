/*
 * LinkedList.h
 *
 *  Created on: Nov 5, 2016
 *      Author: Designing Future
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

using namespace std;

void initNode(struct Node *head,int id, string Pat, string Addr, string Flag);
void addNode(struct Node *head, int id, string Pat, string Addr, string Flag);
bool searchNode(int id, string Pat, string Addr, string Flag );
void displayAll();
void displayPatternWithFlags(int choice);
void addLinklist(int id, string pat, string addr, string flag);
void createLinklist();


#endif /* LINKEDLIST_H_ */
