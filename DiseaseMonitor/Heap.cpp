#include "Heap.h"
#include <tgmath.h>

Heap::Heap() {
    root = NULL;
    height = numOfNodes = 0;
}

Heap::~Heap() {
    deleteHeap(root);
}

void Heap::deleteHeap(HeapNode *current) {
    if (current != NULL) {
        deleteHeap(current->left);
        deleteHeap(current->right);
        delete current;
    }
}

void Heap::insert(string key) {

    //cout << "Heap Insert " << key << endl;
    if (root == NULL) {
        root = new HeapNode();
        root->left = root->right = NULL;
        root->counter = 1;
        root->id = key;
        root->parent = NULL;
        height = numOfNodes = 1;
        //cout << "Root created : " << root->id << endl;
    } else {
        HeapNode *temp = find(root, key); // find the country. ..
        if (temp == NULL) { // if it does not exist add with counter 1;
            //cout << "Didn t find it,going to insert" << endl;
            int max = pow(2, height) - 1;
            if (numOfNodes == max) height++;
            numOfNodes++;
            //            cout << " max is " << max << endl;
            //            cout << "height is " << height << endl;
            //            cout << "nodes are " << numOfNodes << endl;
            insertNode(root, key, numOfNodes, height);
            //cout << "I inserted " << numOfNodes << " with " << key << endl;
        } else swim(temp); // if it does increase counter by 1 and swim()
    }




}

void Heap::insertNode(HeapNode* current, string key, int nodesCounter, int h) {
    if (h == 2) {
        //cout << "nodeCounter is " << nodesCounter << endl;
        HeapNode *temp = current;
        if ((numOfNodes % 2) == 0) { // if your node number is even save it on the left child
            //cout << "Num Of nodes is even" << endl;
            current->left = new HeapNode();
            current = current->left;

        } else {
            //cout << "Num Of nodes is odd" << endl;
            current->right = new HeapNode();
            current = current->right;
        }
        current->parent = temp;
        current->left = current->right = NULL;
        current->counter = 1;
        current->id = key;
        //cout << "I just inserted " << current->id << endl;
    } else {
        //        cout << "nodeCounter is " << nodesCounter << endl;
        //        cout << "my subtrees are " << 3 * pow(2, h - 2) << endl;
        int max = pow(2, h - 1); // max of h-1
        if (nodesCounter < (3 * pow(2, h - 2))) {
            //cout << "I went left " << endl;
            current = current->left;
            // nodesCounter -= max/2;
            max /= 2;
        } else {
            //cout << "I went right " << endl;
            current = current->right;
            // nodesCounter -= max;
        }
        //        cout << "I passed " << max << " nodes at  " << h << endl;
        //        cout << "my new counterNode is " << nodesCounter - max << endl;
        //        cout << "I am at " << current->id << endl;
        insertNode(current, key, nodesCounter - max, h - 1);

    }
}

HeapNode* Heap::find(HeapNode *current, string key) {
    // DFS
    if (current == NULL) return NULL;
    else {
        if (current->id == key) {
            current->counter++;
            //cout << "Found it!! counter increased" << endl;
            return current;
        } else {
            HeapNode *temp = find(current->left, key);
            if (temp == NULL) temp = find(current->right, key);
            return temp;
        }
    }
}

HeapNode* Heap::findLastNode(HeapNode *current, int nodesCounter, int h) {
    if (h == 2) {
        if ((numOfNodes % 2) == 0) return current->left;
        else return current->right;
    } else {
        int max = pow(2, h - 1); // max of h-1
        if (nodesCounter < (3 * pow(2, h - 2))) {
            current = current->left;
            max /= 2;
        } else {
            current = current->right;
        }
        return findLastNode(current, nodesCounter - max, h - 1);
    }
    //return current;
}

void Heap::swim(HeapNode* current) {

    while (current->parent != NULL && current->counter > current->parent->counter) {
        HeapNode *parent = current->parent;
        HeapNode *child = current;

        string id = parent->id;
        int counter = parent->counter;

        parent->id = child->id;
        parent->counter = child->counter;

        child->id = id;
        child->counter = counter;
    }

}

void Heap::sink(HeapNode* current) {

    while (current->left != NULL) {
        HeapNode *left = current->left;
        HeapNode *right = current->right;
        string id = current->id;
        int counter = current->counter;

        if (right != NULL) {
            if (current->counter < left->counter || current->counter < right->counter) {


                if (left->counter > right->counter) { // left is bigger
                    current->id = left->id;
                    current->counter = left->counter;

                    left->id = id;
                    left->counter = counter;
                    current = left;
                } else {
                    current->id = right->id;
                    current->counter = right->counter;

                    right->id = id;
                    right->counter = counter;
                    current = right;
                }
            } else break;
        } else {
            if (current->counter < left->counter) {
                current->id = left->id;
                current->counter = left->counter;

                left->id = id;
                left->counter = counter;
                current = left;
            } else break;
        }
    }


}

void Heap::removeMax() {
    // remove max from top for the heap and sink()
    //HeapNode *max = NULL; //saving the max node
    //    string id = root->id;
    //    int counter = root->counter;
    //    max->id = id;
    //    max->counter = counter;
    //return max;
    if (numOfNodes) {
        cout << root->id << " " << root->counter << endl;
    //cout << "Searching for last Node ";
    //cout << numOfNodes << endl;
        HeapNode *last = findLastNode(root, numOfNodes, height);
        //cout << "Last Node is " << last->id << endl;
        HeapNode *parent = last->parent;
        //cout << "Where" << endl;
        if ((numOfNodes % 2) == 0) parent->left = NULL;
        else parent->right = NULL;

        //swapping the last node with root
        root->id = last->id;
        root->counter = last->counter;
        delete last;

        //cout << "new root " << root->id << " with " << root->counter << endl;
        numOfNodes--;
        int maxNodes = pow(2, height - 1) - 1;
        if (numOfNodes == maxNodes) height--;
        //cout << "Before sink " << endl;
        sink(root);
    }
    //printTree();
    // standard
    //return max;
}

void Heap::printTree() {
    if (root != NULL) printNode(root);
    cout << root->id << " with counter " << root->counter << endl;
    cout << root->left->id << " with counter " << root->left->counter << endl;
    cout << root->right->id << " with counter " << root->right->counter << endl;
}

void Heap::printNode(HeapNode *current) {
    if (current->left != NULL)
        printNode(current->left);
    cout << current->id << " with counter " << current->counter << endl;
    if (current->right != NULL)
        printNode(current->right);
}