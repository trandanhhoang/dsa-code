#include "sll.h"
#include <vector>
using namespace std;
//cach 1 : pointer to pointer
// SNode *getMiddle(SNode *head) {
//     // TODO
//     SNode **pCr = &head;
//     SNode *pRun = head;
//     int sum = 1;
//     while(pRun!=NULL){
//         if(sum%2==0){
//             pCr = &((*pCr)->next);
//         }
//         pRun=pRun->next;
//         sum++;
//     }
//     return *pCr;
// }
//cach 2: slow go 1, fast go 2.
SNode *getMiddle(SNode *head)
{
    SNode *fast = head;
    SNode *slow = head;
    while (fast && fast->next)
    {
        if (!fast->next->next)
        {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main()
{
    SLLForPractice sll;
    for (auto &&ele : vector<int>{1, 2, 3})
    {
        sll.pushFront(ele);
    }

    // Odd number of elements
    sll.traverse();
    auto middle = getMiddle(sll.getHead());
    cout << "Middle: " << (middle ? middle->key : -1) << "\n";
    cout << "\n";

    // Even number of elements
    sll.pushFront(0);
    sll.traverse();

    middle = getMiddle(sll.getHead());
    cout << "Middle: " << (middle ? middle->key : -1) << "\n";

    return 0;
}
