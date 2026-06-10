// template <typename T>
// It is a template declaration that allows us to create a class that can work with any data type. 
// The "T" is a placeholder for the data type that will be specified when we create an instance of the class. 
// This way, we can create binary tree nodes that can hold any type of data, such as integers, floats, or even custom objects.

template <typename T>
class BinaryTreeNode 
{
  public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) 
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() 
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};