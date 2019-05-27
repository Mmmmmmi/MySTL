#pragma once

#include <iostream>

template<class T>
struct BSTree_Node
{
    typedef BSTree_Node<T> Node;
    typedef BSTree_Node<T>* PNode;

    BSTree_Node(const T& data = T())
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
        :_head(new Node())
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
        //tree empty
        if (_head->_patent == nullptr)
        {
            PNode newNode = new Node(data);
            _head->_patent = newNode;
            newNode->_patent = _head;
            return true;
        }

        //
        PNode pParent = nullptr;
        PNode pCur = _head->_patent;

        while(pCur != nullptr)
        {
            pParent = pCur;
            if (data == pCur->_data)
            {
                return false;
            }
            else if (data < pCur->_data)
            {
                pCur = pCur->_leftChild;
            }
            else if (data > pCur->_data)
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
        //tree empty
        if (_head->_patent == nullptr)
        {
            return false;
        }

        //1. find
        PNode pParent = nullptr;
        PNode pCur = _head->_patent;
        while(pCur != nullptr)
        {
            if (data < pCur->_data)
            {
                pParent = pCur;
                pCur = pCur->_leftChild;
            }
            else if (data > pCur->_data)
            {
                pParent = pCur;
                pCur = pCur->_rightChild;
            }
            else if (data == pCur->_data)
            {
                //2. erase
                if (pCur->_leftChild == nullptr && pCur->_rightChild == nullptr)
                {
                    //leftChild == nullptr && rightChild == nullptr 
                    if (_head->_patent == pCur)
                    {
                        //erase root
                        _head->_patent = nullptr;
                        delete pCur;
                        return true;
                    }
                    if (data < pParent->_data)
                    {
                        pParent->_leftChild = nullptr; 
                    }
                    else if (data > pParent->_data)
                    {
                        pParent->_rightChild = nullptr;
                    }
                    return true;
                }
                else if (pCur->_leftChild == nullptr && pCur->_rightChild != nullptr)
                {
                    //leftChild == nullptr && rightChild != nullptr 
                    if (_head->_patent == pCur)
                    {
                        _head->_patent = pCur->_rightChild;
                        delete pCur;
                        return true;
                    }
                    if (data < pParent->_data)
                    {
                        pParent->_leftChild = pCur->_rightChild;
                    }
                    else if (data > pParent->_data)
                    {
                        pParent->_rightChild = pCur->_rightChild;
                    }
                    delete pCur;
                    return true;
                }
                else if (pCur->_leftChild != nullptr && pCur->_rightChild == nullptr)
                {
                    //leftChild != nullptr && rightChild == nullptr 
                    if (_head->_patent == pCur)
                    {
                        _head->_patent = pCur->_leftChild;
                        delete pCur;
                        return true;
                    }
                    if (data < pParent->_data)
                    {
                        pParent->_leftChild = pCur->_leftChild;
                    }
                    else if (data > pParent->_data)
                    {
                        pParent->_rightChild = pCur->_leftChild;
                    }
                    delete pCur;
                    return true;
                }
                else
                {
                    //leftChild != nullptr && rightChild != nullptr
                    PNode delParent = nullptr;
                    PNode del = pCur->_leftChild;
                    while(del->_rightChild != nullptr)
                    {
                        delParent = del;
                        del = del->_rightChild;
                    }
                    if (delParent == nullptr)
                    {
                        //del == pCur->_leftChild && del->_rightChild == nullptr;
                        pCur->_leftChild = del->_leftChild;
                    }
                    else 
                    {
                        delParent->_rightChild = del->_leftChild;
                    }
                    std::swap(pCur->_data, del->_data);
                    delete del;
                    return true;
                }
            }
        }
        // pCur == nullptr
        std::cout << "data not find!" <<std::endl;
        return false; 
    }

    PNode Find(const T& data)
    {
        return _Find(_head->_patent, data);
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

    PNode _Find(const PNode& root, const T& data)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        if (data < root->_data)
        {
            return _Find(root->_leftChild, data);
        }
        else if(data > root->_data)
        {
            return _Find(root->_rightChild, data);
        }
        else if (data == root->_data)
        {
            return root;
        }
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


template<class K, class V>
struct AVLTree_Node
{
    typedef AVLTree_Node<K, V> Node;
    typedef AVLTree_Node<K, V>* PNode;

    AVLTree_Node(const K& key, const V& value)
        :_data(key, value)
         ,_bf(0)
         ,_leftChild(nullptr)
         ,_rightChild(nullptr)
         ,_patent(nullptr)
    {}

    
    pair<K, V> _data;
    int _bf;
    PNode _leftChild;
    PNode _rightChild;
    PNode _patent;
};




template<class K, class V>
class AVLTree
{
    typedef AVLTree_Node<K, V> Node;
    typedef AVLTree_Node<K, V>* PNode;
public:
    AVLTree(const K& key = K(), const V& value = V())
        :_head(new Node(key, value))
    {}

    bool Insert()
    {

    }


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
