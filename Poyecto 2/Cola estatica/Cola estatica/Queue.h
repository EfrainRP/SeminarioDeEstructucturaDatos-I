#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <windows.h>
#include <ctime>

#include <string>
#include "AnyException.h"

//Definicion
template <class T, int ARRAYSIZE = 1024>
class Queue {
    private:
        //Atributos
        T data[ARRAYSIZE];
        int frontPos;
        int endPos;

        //Metodos privados
        void copyAll(const Queue<T, ARRAYSIZE>&);

    public:
        //Constructores
        Queue();
        Queue(const Queue<T, ARRAYSIZE>&);

        //Sobrecarga de operador
        Queue<T, ARRAYSIZE>& operator = (const Queue<T, ARRAYSIZE>&);

        //Metodos para una Lista
        bool isEmpty();
        bool isFull();

        void enqueue(const T&);
        T dequeue();
        T getFrontPos();

        void eliminar();

        void showQueue();
        void gotoxy(int,int);
    };

//Implementacion

using namespace std;

//Metodos privados
template <class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::copyAll(const Queue<T, ARRAYSIZE>& q) {
    int i(q.frontPos);
    while(i != q.endPos + 1) {
        data[i] = q.data[i];

        if(++i == ARRAYSIZE) {
            i=0;
            }
        }

    frontPos = q.frontPos;
    endPos = q.endPos;
    }

//Constructores
template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue() : frontPos(0), endPos(ARRAYSIZE-1) {}

template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue(const Queue<T, ARRAYSIZE>& q) {
    copyAll(q);
    }

//Sobrecarga de operador
template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>& Queue<T, ARRAYSIZE>::operator = (const Queue<T, ARRAYSIZE>& q) {
    copyAll(q);
    return *this;
    }

//Metodos para una Lista
template <class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isEmpty() {
    return frontPos == endPos + 1
           or (frontPos == 0 and endPos == ARRAYSIZE - 1);
    }

template <class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isFull() {
    return frontPos == endPos + 2
           or (frontPos == 0 and endPos == ARRAYSIZE - 2)
           or (frontPos == 1 and endPos == ARRAYSIZE - 1);
    }

template <class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::enqueue(const T& newElement) {
    if(isFull()) {
        throw AnyException("Desbordamiento de datos, enqueue");
        }

    if(++endPos == ARRAYSIZE) {
        endPos = 0;
        }
    data[endPos] = newElement;
    }

template <class T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::dequeue() {
    if(isEmpty()) {
        throw AnyException("Insuficiencia de datos, dequeue");
        }

    T result(data[frontPos]);

    if (++frontPos == ARRAYSIZE) {
        frontPos = 0;
        }
    return result;
    }

template <class T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::getFrontPos() {
    if(isEmpty()) {
        throw AnyException("Insuficiencia de datos, getFrontPos");
        }
    return data[frontPos];
    }

template <class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::showQueue(){
    int cont=1,i;
    if(!isEmpty()){
        system("cls");

        for(i=endPos;i>=0;i--){
            cont+=4;
            gotoxy(cont,2);

            if(i==endPos){
                printf("%c%c%c%c%c ", 201,205,205,205,187);}
                else{ printf("%c%c%c%c%c ",203,205,205,205,187);}
                gotoxy(cont,3),printf("%c ",186);cout<<data[i];printf(" %c",186);
                if(i==endPos){gotoxy(cont,4);printf("%c%c%c%c%c\n",200,205,205,205,188);}
                else{gotoxy(cont,4);printf("%c%c%c%c%c\n",202,205,205,205,188);}
            }
            cout<<"       ^ \n       | \n       | \n Final";
            gotoxy(cont,5);cout<<"   ^";gotoxy(cont,6);cout<<"   |";gotoxy(cont,7);cout<<"  Inicio";
    }
    cout<<endl<<endl;
}

template <class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::eliminar(){
	if(!isEmpty()){
		for(int i=0;i<=endPos;i++){
			data[i]=data[i+1];
		}
		data[endPos]=-1;
		endPos--;
	}
}

template <class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

#endif // QUEUE_H_INCLUDED
