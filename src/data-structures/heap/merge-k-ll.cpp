#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getLeft(int i) {
    return i * 2 + 1;
}
int getRight(int i) {
    return i * 2 + 2;
}

int getParent(int i) {
    return (i - 1) / 2;
}

void swap(vector<pair<int, ListNode *>> &sort, int i, int j) {
    pair<int, ListNode *> temp = sort[i];
    sort[i] = sort[j];
    sort[j] = temp;
}

void heapDown(vector<pair<int, ListNode *>> &sort, int index) {
    int size = sort.size();
    int childLeft = getLeft(index);
    int childRight = getRight(index);
    int save = index;
    if (childLeft < size && sort[save].second->val > sort[childLeft].second->val) {
        save = childLeft;
    }
    if (childRight < size && sort[save].second->val > sort[childRight].second->val) {
        save = childRight;
    }
    if (save != index) {
        swap(sort, index, save);
        heapDown(sort, save);
    }
}

void heapUp(vector<pair<int, ListNode *>> &sort, int index) {
    if (index == 0) return;
    int parent = getParent(index);

    if (sort[index].second->val < sort[parent].second->val) {
        swap(sort, parent, index);
        heapUp(sort, parent);
    }
}

void addNode(ListNode *&head, int val) {
    if (head == nullptr) {
        head = new ListNode(val);
        return;
    }
    ListNode *p = head;
    while (p->next) {
        p = p->next;
    }
    p->next = new ListNode(val);
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    vector<pair<int, ListNode *>> sort;
    int k = lists.size();

    //insert k elements
    for (int i = 0; i < k; i++) {
        if (lists[i]) {
            pair<int, ListNode *> pairList;
            pairList.first = i;
            pairList.second = lists[i];
            sort.push_back(pairList);
            heapUp(sort, sort.size() - 1);
        }
    }
    //extract, heapdown, and insert heap up
    ListNode *result = nullptr;

    while (sort.size() > 0) {
        int tail = sort.size() - 1;
        int endIndex = sort[0].first;
        if (sort.size() > 0) {
            int valNode = sort[0].second->val;
            addNode(result, valNode);
            //extract and pop
            sort[0] = sort[tail];
            sort.pop_back();
        }
        //insert the end of pop
        if (lists[endIndex] && lists[endIndex]->next) {
            lists[endIndex] = lists[endIndex]->next;
            sort.push_back(make_pair(endIndex, lists[endIndex]));
            heapUp(sort, tail);
        }
        for (int i = k / 2; i >= 0; i--) {
            heapDown(sort, i);
        }
    }
    return result;
}

// [[1,4,5],[1,3,4],[2,6]]
int main() {
    ListNode *p1 = nullptr;
    ListNode *p2 = new ListNode(1);
    addNode(p2, 3);
    addNode(p2, 4);
    ListNode *p3 = new ListNode(2);
    addNode(p3, 6);

    vector<ListNode *> myvector;
    myvector.push_back(p1);
    myvector.push_back(p2);
    myvector.push_back(p3);
    ListNode *result = mergeKLists(myvector);
    while (result) {
        cout << result->val << "\n";
        result = result->next;
    }
    return 0;
}
