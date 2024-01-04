#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include <iostream>
#include <string>
#include <exception>

///Definicion del Arbol
template <class T>
class BTree {
    private:
        ///Definicion del Nodo
        class Node {
            private:
                T* dataPtr;
                Node* left;
                Node* right;

            public:
                ///Definicion de Excepcion para el Nodo
                class Exception : public std::exception {
                    private:
                        std::string msg;
                    public:
                        explicit Exception(const char* message): msg(message) {}
                        explicit Exception(const std::string& message): msg(message) {}
                        virtual ~Exception() throw() {}
                        virtual const char* what() const throw () {
                            return msg.c_str();
                            }
                    };

                Node();
                Node(const T&);

                ~Node();

                T* getDataPtr()const;
                T getData()const;
                Node*& getLeft();
                Node*& getRight();

                void setDataPtr(T*);
                void setData(const T&);
                void setLeft(Node*&);
                void setRight(Node*&);
            };

    public:
        typedef Node* Position;

        ///Definicion de Excepcion para el arbol
        class Exception : public std::exception {
            private:
                std::string msg;
            public:
                explicit Exception(const char* message): msg(message) {}
                explicit Exception(const std::string& message): msg(message) {}
                virtual ~Exception() throw() {}
                virtual const char* what() const throw () {
                    return msg.c_str();
                    }
            };

    private:
        Position root;

        void copyAll(BTree<T>&);

        void insertData(Position&, const T&);
        void deleteData(Position&, const T&);
        Position& findData (Position&, const T&);

        Position& getLowest (Position&);
        Position& getHighest (Position&);
        Position& getPreviusPos(Position&, Position&);

        void parsePostOrderDeleteAll(Position&);

        void parsePreOrderCopy(Position&, Position&);

        void parsePreOrder (Position&, int);
        void parseInOrder (Position&, int);
        void parsePostOrder (Position&, int);


    public:
        ///Constructores
        BTree();
        BTree(BTree<T>&);
        ~BTree(); ///Destructor

        ///Sobrecarga de operador
        BTree<T>& operator = (const BTree<T>&);

        ///Metodos para un Arbol
        bool isEmpty()const;

        void insertData(const T&);
        void deleteData(const T&);
        void deleteAll();

        T retrieve(Position&)const;

        Position& findData(const T&);
        Position& getLowest();
        Position& getHighest();
        Position& getPreviusPos(Position&);

        bool isLeaf(Position&);

        int getHeight(Position&);
        int getHeight();

        void parsePreOrder (int);
        void parseInOrder (int);
        void parsePostOrder (int);
    };

///Implementacion
using namespace std;

///del Nodo
template <class T>
BTree<T>::Node::Node():dataPtr(nullptr),left(nullptr), right(nullptr) {}

template <class T>
BTree<T>::Node::Node(const T& e): dataPtr(new T(e)), left(nullptr), right(nullptr) {
    if(dataPtr == nullptr) {
        throw Exception ("Memoria insuficiente, creando nodo");
        }
    }

template <class T>
BTree<T>::Node::~Node() {
    delete dataPtr;
    }

template <class T>
T* BTree<T>::Node::getDataPtr()const {
    return dataPtr;
    }

template <class T>
T BTree<T>::Node::getData()const {
    if(dataPtr == nullptr) {
        throw Exception("Dato inexistente, getData");
        }

    return *dataPtr;
    }

template <class T>
typename BTree<T>::Position& BTree<T>::Node::getLeft() {
    return left;
    }

template <class T>
typename BTree<T>::Position& BTree<T>::Node::getRight() {
    return right;
    }

template <class T>
void BTree<T>::Node::setDataPtr(T* e) {
    dataPtr = e;
    }

template <class T>
void BTree<T>::Node::setData(const T& e) {
    if(dataPtr == nullptr) {
        if((dataPtr = new T(e)) == nullptr) {
            throw Exception("Memoria no disponible, setData");
            }
        }
    else {
        *dataPtr = e;
        }
    }

template <class T>
void BTree<T>::Node::setLeft(Node*& p) {
    left = p;
    }

template <class T>
void BTree<T>::Node::setRight(Node*& p) {
    right = p;
    }

///del Arbol
///Metodos privados
template <class T>
void BTree<T>::copyAll( BTree<T>& t) {
    //Position rootCopy(t.root);
    parsePreOrderCopy(root, t.root);
    }

template <class T>
void BTree<T>::insertData(Position& r, const T& e) {
    if(r == nullptr) {
        try {
            if((r = new Node(e)) == nullptr) {
                throw Exception("Memoria no disponible, insertData");
                }
            }
        catch (typename Node::Exception ex) {
            throw Exception(ex.what());
            }
        }
    else {
        if(e < r->getData()) {
            insertData(r->getLeft(),e);
            }
        else {
            insertData(r->getRight(),e);
            }
        }
    }

template <class T>
void BTree<T>::deleteData(Position& r, const T& e) {
    if(isEmpty()) {
        return;
        }
    if(e == r->getData()) {
        if(isLeaf(r)) {//Es hoja
            delete r;
            r = nullptr;
            return;
            }
        else if(r->getRight() == nullptr or r->getLeft() == nullptr) {//Tiene un hijo
            Position aux(r);
            r = r->getLeft() == nullptr? r->getRight():r->getLeft();
            delete aux;
            return;
            }
        //(r->getRight() != nullptr and r->getLeft() != nullptr) {//Tiene dos hijos
        T sustitution(getHighest(r->getLeft())->getData());
        r->setData(sustitution);
        deleteData(r->getLeft(),sustitution);


        }
    else {
        if(e < r->getData()) {
            deleteData(r->getLeft(), e);
            }
        else {
            deleteData(r->getRight(), e);
            }
        }
    }

template <class T>
typename BTree<T>::Position& BTree<T>::findData (Position& r, const T& e) {
    if(r == nullptr or r->getData() == e) {
        return r;
        }
    if(e < r->getData()) {
        return findData(r->getLeft(), e);
        }
    return findData(r->getRight(), e);
    }

template <class T>
typename BTree<T>::Position& BTree<T>::getLowest (Position& r) {
    if(r == nullptr or r->getLeft() ==nullptr) {
        return r;
        }
    return getLowest(r->getLeft());
    }

template <class T>
typename BTree<T>::Position& BTree<T>::getHighest (Position& r) {
    if(r == nullptr or r->getRight() == nullptr) {
        return r;
        }
    return getHighest(r->getRight());
    }

template <class T>
typename BTree<T>::Position& BTree<T>::getPreviusPos (Position& theRoot, Position& r) {
    if(theRoot->getRight() == r || theRoot->getLeft() == r) {
        return theRoot;
        }
    if(theRoot->getData() > r->getData()) {
        return getPreviusPos(theRoot->getLeft(), r);
        }
    return getPreviusPos(theRoot->getRight(), r);
}

template <class T>
void BTree<T>::parsePostOrderDeleteAll(Position& r) {
    if(r == nullptr) {
        return;
        }

    parsePostOrderDeleteAll(r->getLeft());
    parsePostOrderDeleteAll(r->getRight());
    delete r;
    }

template <class T>
void BTree<T>::parsePreOrderCopy(Position& r, Position& rCopy) {
    if(rCopy == nullptr) {
        r = nullptr;
        }
    else {
        try {
            if((r = new Node(rCopy->getData())) == nullptr) {
                throw Exception("Memoria no disponible, copyAll");
                }
            }
        catch (typename Node::Exception ex) {
            throw Exception(ex.what());
            }

        parsePreOrderCopy(r->getLeft(), rCopy->getLeft());
        parsePreOrderCopy(r->getRight(), rCopy->getRight());
        }
    }


template <class T>
void BTree<T>::parsePreOrder (Position& r, int n) {
    if(r == nullptr) {
        return;
        }
        for(int i(0);i<n;i++)
        cout<<"\t";
    std::cout << r->getData().toString() << endl;
    parsePreOrder(r->getLeft(),n+1);
    parsePreOrder(r->getRight(),n+1);
    }

template <class T>
void BTree<T>::parseInOrder (Position& r, int n) {
    if(r == nullptr) {
        return;
        }
    parseInOrder(r->getLeft(),n+1);
    for(int i(0);i<n;i++)
        cout<<"\t";
    cout << r->getData().toString() << endl;
    parseInOrder(r->getRight(),n+1);
    }

template <class T>
void BTree<T>::parsePostOrder (Position& r, int n) {
    if(r == nullptr) {
        return;
        }
    parsePostOrder(r->getLeft(),n+1);
    parsePostOrder(r->getRight(),n+1);
    for(int i(0);i<n;i++)
        cout<<"\t";
    cout << r->getData().toString() << endl;
    }

///Constructores
template <class T>
BTree<T>::BTree(): root(nullptr) {}

template <class T>
BTree<T>::BTree(BTree<T>& t): BTree() {//Llama otra vez al contructor
    copyAll(t);
    }

template <class T>
BTree<T>::~BTree() {///Destructor
    deleteAll();
    }

///Sobre carga de operador
template <class T>
BTree<T>& BTree<T>::operator =(const BTree<T>&t) {
    deleteAll();
    copyAll(t);
    return *this;
    }

///Metodos publicos de la BTreea
template <class T>
bool BTree<T>::isEmpty() const {
    return root == nullptr;
    }

template <class T>
void BTree<T>::insertData(const T& e) {
    insertData(root, e);
    }

template <class T>
void BTree<T>::deleteData(const T& e) {
    deleteData(root, e);
    }

template <class T>
void BTree<T>::deleteAll() {
    parsePostOrderDeleteAll(root);
    root = nullptr;
    }

template <class T>
T BTree<T>::retrieve(Position& r) const {
    if(!isEmpty()){
    return r->getData();
    }else{
        cout<<"ARBOL VACIO"<<endl<<endl;
    }
    }

template <class T>
typename BTree<T>::Position& BTree<T>::findData(const T& e) {
    if(!isEmpty()){
    return findData(root, e);
    }else{
        cout<<"ARBOL VACIO"<<endl<<endl;
    }
    }

template <class T>
typename BTree<T>::Position& BTree<T>::getLowest() {
    if(!isEmpty()){
    return getLowest(root);
    }else{
        cout<<"ARBOL VACIO"<<endl<<endl;
    }
    }

template <class T>
typename BTree<T>::Position& BTree<T>::getHighest() {
    if(!isEmpty()){
    return getHighest(root);
    }else{
        cout<<"ARBOL VACIO"<<endl<<endl;
    }
    }

template <class T>
typename BTree<T>::Position& BTree<T>::getPreviusPos(Position& r) {
    if(!isEmpty()){
        if(r==root){
            return r;
        }
        return getPreviusPos(root, r);
    }else{
        cout<<"ARBOL VACIO"<<endl<<endl;
    }
    }

template <class T>
bool BTree<T>::isLeaf(Position& r) {

    return r != nullptr and r->getLeft() == r->getRight();

    }

template <class T>
int BTree<T>::getHeight() {
    return getHeight(root);
    }

template <class T>
int BTree<T>::getHeight(Position& r) {
    if(r == nullptr) {
        return 0;
        }
    int lH(getHeight(r->getLeft()));
    int rH(getHeight(r->getRight()));

    return (lH > rH ? lH : rH) + 1;
    }

template <class T>
void BTree<T>::parsePreOrder (int n) {
    if(!isEmpty()){
        parsePreOrder(root,n);
    }else{
        cout<<"ARBOL VACIO"<<endl<<endl;
    }
    }

template <class T>
void BTree<T>::parseInOrder (int n) {
    if(!isEmpty()){
        parseInOrder(root,n);
    }else{
        cout<<"ARBOL VACIO"<<endl<<endl;
    }
    }

template <class T>
void BTree<T>::parsePostOrder (int n) {
    if(!isEmpty()){
        parsePostOrder(root,n);
    }else{
        cout<<"ARBOL VACIO"<<endl<<endl;
    }
    }

#endif // BTREE_H_INCLUDED
