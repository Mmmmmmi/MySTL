#pragma once

template<class T>
struct BSTree_Node
{
    typedef BSTree_Node<T> Node;
    typedef BSTree_Node<T>* PNode;

    BSTree_Node(const T& data)
        :_data(data)
         ,_leftChild(nullptr)
         ,_rightChild(nullptr)
         ,_patent(nullptr)
    {}


    T _data;
    PNode _leftChild;
    PNode _rightChild;
    PNode _patent;
};


template<class T>
class BinarySearchTree 
{
    typedef BSTree_Node<T> Node;
    typedef BSTree_Node<T>* PNode;
    typedef T& reference;
    typedef BinarySearchTree<T> Self;
public:
    BinarySearchTree()
        :_head(nullptr)
    {}

    void Destroy()
    {
        _Destroy(_head);
        _head = nullptr;
    }

    ~BinarySearchTree()
    {
        Destroy();
    }

    bool Insert(const T& data)
    {
        if (_head == nullptr)
        {
            PNode newNode = new Node(data);
            _head->_patent = newNode;
            newNode->_patent = _head;
            return true;
        }
        
        PNode pParent = nullptr;
        PNode pCur = _head->_patent;

        while(pCur != nullptr)
        {
            pParent = pCur;
            if (data == pCur->_data)
            {
                return false;
            }
            else if (data > pCur->_data)
            {
                pCur = pCur->_leftChild;
            }
            else if (data < pCur->_data)
            {
                pCur = pCur->_rightChild;
            }
        }


        PNode newNode = new Node(data);
        //L
        if (data < pParent->_data)
        {
            pParent->_leftChild = newNode;
        }
        //R
        else
        {
            pParent->_rightChild = newNode;
        }
        return true; 
    }

    bool Erase(const T& data)
    {
        if (_head->_patent == nullptr)
        {
            return false;
        }
        while()
        {

        }
    }

    PNode Find(const T& data)
    {

    }

    void InOrder()
    {
        _InOrder(_head->_patent);
        cout << endl;
    }

private:

    void _InOrder(PNode root)
    {
        if (root == nullptr)
        {
            return;
        }
        _InOrder(root->_leftChild);
        cout << root->_data <<" ";
        _InOrder(root->_rightChild);
    }


    void _Destroy(PNode root)
    {
        if (root != nullptr)
        {
            _Destroy(root->_leftChild);
            _Destroy(root->_rightChild);
            delete root;
        }
    }

    PNode _head;
};

/*
template<class T>
class AVLTree
{
    typedef Tree_Node<T> Node;
    typedef Tree_Node<T>* PNode;
public:

private:
    PNode _head;
};

template<class T>
class RedBlackTree
{
    typedef Tree_Node<T> Node;
    typedef Tree_Node<T>* PNode;
public:

private:
    PNode _head;
};
*/
