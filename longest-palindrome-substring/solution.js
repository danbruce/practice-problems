const longestPalindrome = (s) => {
  // handle the single char string or empty string
  if (s.length < 2) return s;

  // indicates the start and end of the longest palindrome
  let start = 0;
  let end = 0;
  for (let i = 0; i < s.length; i++) {
    let left = i - 1; // initialize the left walker just to the left of i
    let right = i + 1; // initialize the right walker just to the right of i
    // walk the right walker to the end of the repeated sequence of characters
    while (right < s.length && s[i] === s[right] && right < s.length) {
      right++;
    }
    // walk the palindrome on both sides of the centre point until we no longer match
    while (left >= 0 && right < s.length && s[left] === s[right]) {
      left--;
      right++;
    }
    // replace the longest known sequence if our current sequence is longer
    if ((right - left - 1) > (end - start)) {
      start = left + 1;
      end = right - 1;
    }
  }
  // return the final answer
  return s.substr(start, end - start + 1);
};