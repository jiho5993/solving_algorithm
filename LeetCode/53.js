const max = (a, b) => {
  return a > b ? a : b;
}

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
  const dp = new Array(100001);

  let res = nums[0];
  dp[0] = nums[0];

  for (let i=1; i<nums.length; i++) {
    const c = nums[i];
    const s = nums[i] + dp[i-1];

    dp[i] = max(c, s);
    res = max(res, dp[i]);
  }

  return res;
};