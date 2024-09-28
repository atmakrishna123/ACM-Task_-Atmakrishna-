int singleNumber(int* nums, int numsSize) {
    for (int i=0;i<numsSize;++i){
        int temp=nums[i];
        int count=0;
        for (int j=0;j<numsSize;++j){
            if (temp==nums[j]){
                ++count;
            }
        }
        if (count==1){
            return(temp);
        }
    }
    return -1;
}