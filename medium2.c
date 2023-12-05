#include <stdio.h>
#include <stdlib.h>
int* mE(int* nums, int numsSize, int* returnSize) {
    int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }
    count1 = count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        }
    }
    *returnSize = 0;
    if (count1 > numsSize / 3) {
        (*returnSize)++;
    }
    if (count2 > numsSize / 3 && candidate1 != candidate2) {
        (*returnSize)++;
    }
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    int index = 0;
    if (count1 > numsSize / 3) {
        result[index++] = candidate1;
    }
    if (count2 > numsSize / 3 && candidate1 != candidate2) {
        result[index++] = candidate2;
    }

    return result;
}
int main() {
    int nums[] = {1,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* result = mE(nums, numsSize, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);

    return 0;
}
