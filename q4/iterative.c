int maxSubArray(int *nums, int numsSize) 
{
	int temp = 0;
	int max = nums[0];
	for (inti = 0; i < numsSize; i++) {
		if (temp > 0)
			temp += nums[i];
		else
			temp = nums[i];
		if (temp > max)
			max = temp;
	}
	return max;
}

int main()
{
    return 0;
}
