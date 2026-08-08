// NOLINTBEGIN(misc-definitions-in-headers)

#include <cstddef>
#if 0

#include <vector>
#include <limits>

class Solution {
private:
    static int doTheDP(
        const std::vector<int>& nums,
        const int l,
        const int r,
        std::vector<std::vector<int>>& dpCache);
public:
    static bool predictTheWinner(
        const std::vector<int>& nums);
};

int Solution::doTheDP(
    const std::vector<int>& nums,
    const int l,
    const int r,
    std::vector<std::vector<int>>& dpCache) {
    
    if (l == r) {
        dpCache[l][r] = nums[l];
    }

    if (dpCache[l][r] != std::numeric_limits<int>::min()) {
        return dpCache[l][r];
    }

    const int takeL = nums[l] - Solution::doTheDP(nums, l + 1, r, dpCache);
    const int takeR = nums[r] - Solution::doTheDP(nums, l, r - 1, dpCache);

    return dpCache[l][r] = std::max(takeL, takeR);
}

bool Solution::predictTheWinner(const std::vector<int>& nums) {

    const int n = static_cast<int>(nums.size());

    std::vector<std::vector<int>> dpCache(
        n, std::vector<int>(n, std::numeric_limits<int>::min()));

    return Solution::doTheDP(nums, 0, n - 1, dpCache) >= 0;
}

#elif 0

#include <stdlib.h>
#include <string.h>

// Mega block of ugly code...

void**allocateTwoD(
    const size_t n,
    const size_t m,
    const size_t elementSize,
    const unsigned char byteInit){
    void**memPtr=(void**)malloc(n*sizeof(void*));
    for(size_t i=0;i<n;++i){
        memPtr[i] = malloc(m*elementSize);
        memset(memPtr[i],byteInit,m*elementSize);}
    return memPtr;}
void freeTwoD(
    const size_t n,
    void**dpCache){
    for(size_t i=0;i<n;++i){
        free(dpCache[i]);}
    free(dpCache);}
int doDp(
    int*nums,
    int l,
    int r,
    int**dp){
    if(l==r)dp[l][r]=nums[l];
    if(dp[l][r]!=-1)return dp[l][r];
    const int tL=nums[l]-doDp(nums,l+1,r,dp);
    const int tR=nums[r]-doDp(nums,l,r-1,dp);
    return dp[l][r]=tL>tR?tL:tR;}
bool predictTheWinner(
    int* nums,
    const int numsSize) {
    int**dp=(int**)allocateTwoD(
        (size_t)numsSize,
        (size_t)numsSize,
        sizeof(int),
        0b11111111);
    const int result=doDp(nums,0,numsSize-1,dp);
    freeTwoD(
        (size_t)numsSize,
        (void**)dp);
    return result>=0;}

#else

#include <vector>
#include <stdlib.h>
#include <string.h>


static void**allocateTwoD(
    const size_t n,
    const size_t m,
    const size_t elementSize,
    const unsigned char byteInit){
    void**memPtr=(void**)malloc(n*sizeof(void*));
    for(size_t i=0;i<n;++i){
        memPtr[i] = malloc(m*elementSize);
        memset(memPtr[i],byteInit,m*elementSize);}
    return memPtr;}
static void freeTwoD(
    const size_t n,
    void**dpCache){
    for(size_t i=0;i<n;++i){
        free(dpCache[i]);}
    free(dpCache);}
static int doDp(
    int*nums,
    int l,
    int r,
    int**dp){
    if(l==r)dp[l][r]=nums[l];
    if(dp[l][r]!=-1)return dp[l][r];
    const int tL=nums[l]-doDp(nums,l+1,r,dp);
    const int tR=nums[r]-doDp(nums,l,r-1,dp);
    return dp[l][r]=tL>tR?tL:tR;}
static bool predictTheWinnerC(
    int* nums,
    const int numsSize) {
    int**dp=(int**)allocateTwoD(
        (size_t)numsSize,
        (size_t)numsSize,
        sizeof(int),
        0b11111111);
    const int result=doDp(nums,0,numsSize-1,dp);
    freeTwoD(
        (size_t)numsSize,
        (void**)dp);
    return result>=0;}


class Solution {
public:
    static bool predictTheWinner(
        std::vector<int>& nums);
};

bool predictTheWinner(
    std::vector<int>& nums){
        return predictTheWinnerC(
            nums.data(),
            static_cast<int>(nums.size()));}

#endif

// NOLINTEND(misc-definitions-in-headers)