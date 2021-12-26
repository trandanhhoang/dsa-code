#include <vector>

#include "sll.h"

using namespace std;
//O(n) time O(n) space
bool isPalindrome(SNode *head) {
    // TODO
    // store in vector
    vector<int> my_vec;
    SNode *p_Cur = head;
    while (p_Cur) {
        my_vec.emplace_back(p_Cur->key);
        p_Cur = p_Cur->next;
    }
    //check
    int count = 0;
    int size = my_vec.size();
    while (count < size / 2) {
        if (my_vec[count] != my_vec[size - count - 1]) {
            return false;
        }
        count++;
    }
    return true;
}

//Complexity: O(n) time O(1) space
bool isPalindromeOptimal(SNode *head) {
    // TODO
    //move slow to middle.
    SNode *p_slow = head, *p_fast = head;
    while (p_fast != NULL && p_fast->next != NULL) {
        p_slow = p_slow->next;
        p_fast = p_fast->next->next;
    }
    //case1: even 1-2-3-4, slow at
    //case2: odd 1-2-3-2-1, slow at 3
    SNode *p_prev = nullptr, *p_middle = p_slow;
    while (p_middle) {
        SNode *pNext = p_middle->next;
        p_middle->next = p_prev;
        p_prev = p_middle;
        p_middle = pNext;
    }
    SNode *p_run = head;
    while (p_prev) {
        if (p_run->key != p_prev->key) {
            return false;
        }
        p_run = p_run->next;
        p_prev = p_prev->next;
    }
    return true;
}

/* Testing */

SLLForPractice *generateOddPalindrome() {
    SLLForPractice *sll = new SLLForPractice();
    for (auto &&ele : {1, 2, 3, 2, 1}) {
        sll->pushFront(ele);
    }
    return sll;
}

SLLForPractice *generateEvenPalindrome() {
    SLLForPractice *sll = new SLLForPractice();
    for (auto &&ele : {1, 2, 3, 3, 2, 1}) {
        sll->pushFront(ele);
    }
    return sll;
}

int main() {
    SLLForPractice *sll;

    // Test odd palindrome
    sll = generateOddPalindrome();
    sll->traverse();
    cout << "Palindrome: " << boolalpha << isPalindrome(sll->getHead()) << "\n";
    delete sll;
    sll = nullptr;

    // Test even palindrome
    sll = generateEvenPalindrome();
    sll->traverse();
    cout << "Palindrome: " << boolalpha << isPalindrome(sll->getHead()) << "\n";
    delete sll;
    sll = nullptr;

    return 0;
}
