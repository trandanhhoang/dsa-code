//DONE
#include "my-lib.h"
#include "sll.h"

using namespace std;
/* Remember: Manipulating pointer, not swap data */
// SNode *sort_2_merge(SNode *left, SNode *right)
// {
//     //recursive
//     if (!left)
//         return right;
//     if (!right)
//         return left;
//     if (left->key <= right->key)
//     {
//         left->next = sort_2_merge(left->next, right);
//         return left;
//     }
//     else
//     {
//         right->next = sort_2_merge(left, right->next);
//         return right;
//     }
// }

// SNode *find_middle(SNode *head)
// {
//     SNode *slow = head, *fast = head;
//     while (fast && fast->next)
//     {
//         fast = fast->next->next;
//         if (fast)
//             slow = slow->next; //condition to choose exactly node
//     }
//     return slow;
// }

// SNode *mergeSort(SNode *head)
// {
//     // TODO
//     //condition to stop
//     if (!head->next)
//     {
//         return head;
//     }
//     //find middle, middle -> next = null
//     SNode *middle = find_middle(head);
//     SNode *middle_next = middle->next;
//     middle->next = NULL;
//     //split left
//     SNode *left = mergeSort(head);
//     //split right
//     SNode *right = mergeSort(middle_next);
//     //sort left and right to 1
//     return sort_2_merge(left, right);
// }

//1-6    5-7
SNode *merge(SNode *left, SNode *right){
    if(!left)
        return right;
    if(!right)
        return left;

    if(left->key < right->key){
        left->next = merge(left->next,right);
        return left;
    }
    else{
        right->next = merge(left,right->next);
        return right;
    }
}

SNode *findMiddle(SNode *head)
{
    SNode *slow = head;
    SNode *fast = head;
    //0-1-2-3-4
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//1-2-3-4
SNode *mergeSort(SNode *head)
{
    //condition to stop
    if (head->next == nullptr)
        return head;
    //find middle and divide to 2 part
    SNode *pre_middle = findMiddle(head);
    SNode *middle = pre_middle->next;
    pre_middle->next = nullptr;
    //mergeSort with middle is head
    SNode *left = mergeSort(head);
    SNode *right = mergeSort(middle);
    return merge(left, right);
}

int main()
{
    srand(time(0));
    SLLForPractice sll;

    for (auto &&ele : generateVector(15))
    {
        sll.pushFront(ele);
    }

    sll.traverse();
    sll.setHead(mergeSort(sll.getHead()));
    sll.traverse();

    return 0;
}
