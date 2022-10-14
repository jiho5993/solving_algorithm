/**
 * @param {string} s
 * @return {string}
 */
 var longestPalindrome = function(s) {
  let size = 0;
  let res = s[0];
  let dp = Array.from(Array(1001), () => new Array(1001));

  dp[1][1] = true;

  for (let i=2; i<=s.length; i++) {
    for (let j=1; j<=i; j++) {
      if (i == j) {
        dp[i][j] = true;
        continue;
      }

      if (s[i-1] !== s[j-1]) dp[i][j] = false;
      else dp[i][j] = dp[i-1][j+1];
      
      if (i-1 === j && s[i-1] === s[j-1]) {
        dp[i][j] = true;
      }

      if (dp[i][j] && size < i-j+1) {
        size = i-j+1;
        res = "";
        for (let idx=j-1; idx<i; idx++) res += s[idx];
      }
    }
  }

  return res;
};