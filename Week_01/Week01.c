
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

// 打印int数组
void PrintIntArray(int *a, int size);
// 加一测试
void TestPlusOne();
//删除排序数组中的重复项测试
void testRemoveDuplicates();
//旋转数组测试
void testRotate();

int main(int argc, const char *argv[]) {
    //testPlusOne();
    //testRemoveDuplicates();
    //testRotate();
    return 0;
}

/* 加一 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
    }
    *returnSize = digitsSize + 1;
    int *newDigits = (int *)malloc(sizeof(int) * (*returnSize));
    memset(newDigits, 0, (*returnSize) * sizeof(int));
    newDigits[0] = 1;
    return newDigits;
}

void testPlusOne() {
    int a[] = {0, 0};
    int digitsSize = sizeof(a) / sizeof(int);
    int returnSize = 0;
    int *result = plusOne(a, digitsSize, &returnSize);
    PrintIntArray(result, returnSize);
}

/* 26、删除排序数组中的重复项 */
int removeDuplicates(int* nums, int numsSize){
    if (numsSize <= 1) return numsSize;
    int i = 0;
    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

void testRemoveDuplicates() {
    int a[] = {0, 0, 1, 2, 2, 2, 4, 6, 6, 9};
    int size = sizeof(a) / sizeof(int);
    int result = removeDuplicates(a, size);
    printf("resultSize = %d\n", result);
    PrintIntArray(a, result);
}

/* 189. 旋转数组 */

//暴力求解
void rotate01(int* nums, int numsSize, int k) {
    k %= numsSize;
    int temp, prev;
    for (int i = 0; i < k; i++) {
        prev = nums[numsSize - 1];
        for (int j = 0; j < numsSize; j++) {
            temp = prev;
            prev = nums[j];
            nums[j] = temp;
        }
    }
}

//使用环状替换
void rotate02(int* nums, int numsSize, int k) {
    k %= numsSize;
    int count = 0;
    for (int start = 0; count < numsSize; start++) {
        int current = start;
        int prev = nums[start];
        do {
            int next = (current + k) % numsSize;
            int temp = nums[next];
            nums[next] = prev;
            prev = temp;
            current = next;
            count++;
        } while (start != current);
    }
}

//三次翻转（推荐，思路清晰，代码简洁）
void reverse(int *nums, int start, int end);

void rotate03(int* nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

void reverse(int *nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void testRotate() {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(a) / sizeof(int);
    //rotate01(a, size, 3);
    //rotate02(a, size, 3);
    rotate03(a, size, 3);
    PrintIntArray(a, size);
}

/* 合并两个有序链表 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

/* 88、合并两个有序数组 */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p = m + n - 1, p1 = m - 1, p2 = n - 1;
    while (p2 >= 0) {
        if (p1 >= 0) {
            nums1[p--] = nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--];
        } else {
            nums1[p--] = nums2[p2--];
        }   
    }
}

/* 1、两数之和 */
//暴力
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int *result = (int *)malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
//哈希表

/* 283、移动零 */
void moveZeroes(int* nums, int numsSize) {
    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i]) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
    }
}

/* 70、爬楼梯 */
int climbStairs(int n) {
    int p = 0, q = 0, r = 1;
    for (int i = 1; i <= n; i++) {
        p = q;
        q = r;
        r = p + q;
    }
    return r;
}

/* 42、接雨水 */
int trap(int* height, int heightSize){
    int left = 0, right = heightSize - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= left_max) {
                left_max = height[left];
            } else {
                ans += (left_max - height[left]);
            }
            left++;
        } else {
            if (height[right] >= right_max) {
                right_max = height[right];
            } else {
                ans += (right_max - height[right]);
            }
            right--;
        }
    }
    return ans;
}

/* 141、环形链表 */
//快慢指针
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) return true;
    }
    return false;
}

/* 工具方法 */

// 打印int数组
void PrintIntArray(int *a, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", a[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}


