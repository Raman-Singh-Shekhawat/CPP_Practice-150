// 168. Level order traversal: For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. Elements on every level will be printed in a linear fashion and a single space will separate them.

/**********************************************************

    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        if (front == NULL)
        {
            if (pendingNodes.empty())
            {
                break;
            }
            cout << "\n";
            pendingNodes.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if (front->left != NULL)
            {
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pendingNodes.push(front->right);
            }
        }
    }
}