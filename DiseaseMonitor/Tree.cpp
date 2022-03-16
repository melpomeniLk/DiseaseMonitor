#include "Tree.h"
#include "Heap.h"

Tree::Tree() {
    root = NULL;
}

Tree::~Tree() {
    deleteTree(root);
}

int Tree::getHeight(TreeNode *current) {
    if (current == NULL) return 0;
    return current->height;
}

int Tree::getBalance(TreeNode *current) {
    if (current == NULL) return 0;
    else return (getHeight(current->left) - getHeight(current->right));
}

void Tree::insertData(Record* info) {
    if (root == NULL) {
        root = new TreeNode();
        root->entryDate.copyDate(info->getEntryDate());
        root->left = root->right = NULL;
        root->records = new RecordLL();
        root->records->InsertNode(info);
        root->height = 1;
    } else {
        root = insertTreeNode(info, root);
    }
}

TreeNode* Tree::insertTreeNode(Record* info, TreeNode *current) {
    if (!current) {
        current = new TreeNode();
        current->entryDate.copyDate(info->getEntryDate());
        current->left = NULL;
        current->right = NULL;
        current->records = new RecordLL();
        current->records->InsertNode(info);
        current->height = 1;
        return current;
    } else {
        Date d;
        d.copyDate(info->getEntryDate());
        int result = current->entryDate.compareDate(d);

        if (result > 0) {
            current->left = insertTreeNode(info, current->left);
        } else if (result < 0) {
            current->right = insertTreeNode(info, current->right);
        } else if (result == 0) {
            current->records->InsertNode(info);
            return current;
        }
        //cout << "Node inserted making it AVL" << endl;

        current->height = max(getHeight(current->left), getHeight(current->right)) + 1;
        int balance = getBalance(current);
        //        cout << "Balance is " << balance <<  endl;
        //cout << "Do i have left or right" << endl;

        int resultLeft = 0;
        int resultRight = 0;

        if (current->left != NULL)
            resultLeft = current->left->entryDate.compareDate(d);
        if (current->right != NULL)
            resultRight = current->right->entryDate.compareDate(d);

        if (balance > 1 && resultLeft > 0) {
            return rightRotation(current);
            //            cout << "case 1 " << endl;
        }

        if (balance < -1 && resultRight < 0) {
            return leftRotation(current);
            //            cout << "case 2 " << endl;
        }

        if (balance > 1 && resultLeft < 0) {
            //            cout << "case 3 " << endl;
            current->left = leftRotation(current->left);
            return rightRotation(current);
        }

        if (balance < -1 && resultRight > 0) {
            //            cout << "case 4" << endl;
            current->right = rightRotation(current->right);
            return leftRotation(current);
        }


        return current;
    }
}

int Tree::max(int left, int right) {
    if (left > right) return left;
    else return right;
}

TreeNode* Tree::leftRotation(TreeNode *x) {
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    // Perform rotation  
    y->left = x;
    x->right = T2;

    // Update heights  
    x->height = max(getHeight(x->left),
            getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left),
            getHeight(y->right)) + 1;

    // Return new root  
    return y;
}

TreeNode* Tree::rightRotation(TreeNode *y) {
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    // Perform rotation  
    x->right = y;
    y->left = T2;

    // Update heights  
    y->height = max(getHeight(y->left),
            getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left),
            getHeight(x->right)) + 1;

    // Return new root  
    return x;
}

void Tree::printTree() {
    if (root != NULL) printNode(root);
}

void Tree::printNode(TreeNode *current) {
    if (current->left != NULL)
        printNode(current->left);
    current->entryDate.printDate();
    cout << endl;
    if (current->right != NULL)
        printNode(current->right);
}

void Tree::deleteTree(TreeNode *current) {
    if (current != NULL) {
        deleteTree(current->left);
        deleteTree(current->right);
        delete current->records;
        delete current;
    }
}

void Tree::dfs1_diseases(TreeNode * current, Heap * heap) {
    if (current != NULL) {
        //        cout << "Going to insert " << endl;
        //        cout << "My current is ";
        //        current->entryDate.printDate();
        //        cout << endl;
        ListNode *temp = current->records->getHead();
        //cout << temp->record->getCountry() << endl;
        //current->records->PrintList();
        for (int i = 0; i < current->records->getNumOfNodes(); i++) {
            heap->insert(temp->record->getDiseaseID());
            temp = current->records->getNext(temp);
        }
        dfs1_diseases(current->left, heap);
        dfs1_diseases(current->right, heap);
    }
}

void Tree::topK_diseases(int k, string country) {
    Heap * heap = new Heap();

    //cout << "I will print top " << k << " diseases for " << country << endl;

    // DFS
    dfs1_diseases(this->root, heap);
    //cout << "end of insert " << endl;
    if (k > heap->getNumOfNodes()) k = heap->getNumOfNodes();

    for (int i = 0; i < k; i++) {
        //  cout << "Printing " << i + 1 << " disease " << endl;
        heap->removeMax();
        
    }
    delete heap;
}

void Tree::dfs1_Countries(TreeNode * current, Heap * heap) {
    if (current != NULL) {
        //        cout << "Going to insert " << endl;
        //        cout << "My current is ";
        //        current->entryDate.printDate();
        //        cout << endl;
        ListNode *temp = current->records->getHead();
        //cout << temp->record->getCountry() << endl;
        //current->records->PrintList();
        for (int i = 0; i < current->records->getNumOfNodes(); i++) {
            heap->insert(temp->record->getCountry());
            //cout << "I inserted " << temp->record->getDiseaseID() << endl;
            temp = current->records->getNext(temp);
        }
        dfs1_Countries(current->left, heap);
        dfs1_Countries(current->right, heap);
    }
}

void Tree::topK_Countries(int k, string disease) {
    Heap * heap = new Heap();

    //  cout << "I will print top " << k << " countries for " << disease << endl;

    // DFS
    dfs1_Countries(this->root, heap);
    //    cout << "end of insert " << endl;
    //heap->printTree();
    if (k > heap->getNumOfNodes()) k = heap->getNumOfNodes();
    for (int i = 0; i < k; i++) {
        //    cout << "Printing " << i + 1 << " disease " << endl;
        heap->removeMax();
    }
    delete heap;
}

void Tree::topK_diseasesBetween(int k, string country, Date d1, Date d2) {
    Heap * heap = new Heap();

    // DFS
    dfs1_diseasesBetween(this->root, heap, d1, d2);
    if (k > heap->getNumOfNodes()) k = heap->getNumOfNodes();

    for (int i = 0; i < k; i++) {
        heap->removeMax();
        //        if (n != NULL) {
        //            cout << n->id << " : " << n->counter << endl;
        //        }
    }
    delete heap;
}

void Tree::dfs1_diseasesBetween(TreeNode * current, Heap * heap, Date d1, Date d2) {
    if (current != NULL) {
        // for each record in node's list:
        //heap->insert(current->record->getDiseaseID());

        // go left only if current's value is greater or equal to d1
        //dfs1_diseasesBetween(current->left, heap, d1, d2);

        // go right only if current's value is less or equal to d2
        //dfs1_diseasesBetween(current->right, heap, d1, d2);

        int result = current->entryDate.compareDate(d1);
        // go left only if current's value is greater or equal to d1
        if (result > 0 || result == 0) {
            dfs1_diseasesBetween(current->left, heap, d1, d2);
        }
        // go right only if current's value is less or equal to d2
        result = current->entryDate.compareDate(d2);
        if (result < 0 || result == 0) {
            dfs1_diseasesBetween(current->right, heap, d1, d2);
        }
        result = current->entryDate.isDateBetween(d1, d2);
        if (result) {
            ListNode *temp = current->records->getHead();
            //cout << temp->record->getCountry() << endl;
            //current->records->PrintList();
            for (int i = 0; i < current->records->getNumOfNodes(); i++) {
                heap->insert(temp->record->getDiseaseID());
                //cout << "I inserted " << temp->record->getDiseaseID() << endl;
                temp = current->records->getNext(temp);
            }
        }



    }
}

void Tree::topK_CountriesBetween(int k, string disease, Date d1, Date d2) {
    Heap * heap = new Heap();

    // DFS
    dfs1_CountriesBetween(this->root, heap, d1, d2);

    for (int i = 0; i < k; i++) {
        heap->removeMax();
        //        if (n != NULL) {
        //            cout << n->id << " : " << n->counter << endl;
        //        }
    }
    delete heap;
}

void Tree::dfs1_CountriesBetween(TreeNode * current, Heap * heap, Date d1, Date d2) {
    if (current != NULL) {
        // for each record in node's list:
        //heap->insert(current->record->getDiseaseID());
        // go left only if current's value is greater or equal to d1

        // go left only if current's value is greater or equal to d1
        //dfs1_diseasesBetween(current->left, heap, d1, d2);

        // go right only if current's value is less or equal to d2
        //dfs1_diseasesBetween(current->right, heap, d1, d2);

        int result = current->entryDate.compareDate(d1);
        if (result > 0 || result == 0) {
            dfs1_CountriesBetween(current->left, heap, d1, d2);
        }
        // go right only if current's value is less or equal to d2
        result = current->entryDate.compareDate(d2);
        if (result < 0 || result == 0) {
            dfs1_CountriesBetween(current->right, heap, d1, d2);
        }
        result = current->entryDate.isDateBetween(d1, d2);
        if (result) {
            ListNode *temp = current->records->getHead();
            //cout << temp->record->getCountry() << endl;
            //current->records->PrintList();
            for (int i = 0; i < current->records->getNumOfNodes(); i++) {
                heap->insert(temp->record->getCountry());
                //cout << "I inserted " << temp->record->getDiseaseID() << endl;
                temp = current->records->getNext(temp);
            }
        }



    }
}

int Tree::frequency(Date d1, Date d2) {
    //    cout << "begin from ";
    //    root->entryDate.printDate();
    //cout << endl;
    return dfs_frequency(root, d1, d2);
}

int Tree::frequencyCountry(string country, Date d1, Date d2) {
    //    cout << "begin from ";
    //    root->entryDate.printDate();
    //cout << endl;
    return dfs_frequencyCountry(root, country, d1, d2);
}

int Tree::dfs_frequency(TreeNode * current, Date d1, Date d2) {
    //int counter = 0;

    int x = 0;
    int y = 0;
    if (current != NULL) {
        // go left only if current's value is greater or equal to d1
        int result = current->entryDate.compareDate(d1);
        //cout << result << endl;
        if (result > 0 || result == 0) {
            //            cout << "going left " << endl;
            //            current->entryDate.printDate();
            //            cout << endl;
            x = x + dfs_frequency(current->left, d1, d2);
            //cout << x << endl;
        }
        // go right only if current's value is less or equal to d2
        result = current->entryDate.compareDate(d2);
        //        current->entryDate.printDate();
        //        cout << " " << " with ";
        //        d2.printDate();
        //        cout  << endl;
        if (result < 0 || result == 0) {
            //            cout << "going right " << endl;
            //            current->entryDate.printDate();
            //            cout << endl;
            x = x + dfs_frequency(current->right, d1, d2);
            //cout << x << endl;
        }
        result = current->entryDate.isDateBetween(d1, d2);
        if (result) y = current->records->getNumOfNodes();
        else y = 0;
        //        cout << "For Node ";
        //        current->entryDate.printDate();
        //        cout << " frequency is " << x + y << endl;
    }
    //cout << counter << endl;
    //int y = 1 ; // list length ....

    return y + x;
}

int Tree::dfs_frequencyCountry(TreeNode * current, string country, Date d1, Date d2) {

    int x = 0;
    int y = 0;
    if (current != NULL) {
        // go left only if current's value is greater or equal to d1
        int result = current->entryDate.compareDate(d1);
        if (result > 0 || result == 0) {
            x = x + dfs_frequencyCountry(current->left, country, d1, d2);
        }
        // go right only if current's value is less or equal to d2
        result = current->entryDate.compareDate(d2);
        if (result < 0 || result == 0) {
            x = x + dfs_frequencyCountry(current->right, country, d1, d2);
        }
        result = current->entryDate.isDateBetween(d1, d2);
        if (result) y = current->records->FindNode(country);
        else y = 0;
    }

    return y + x;
}