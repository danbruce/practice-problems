/**
 * Counts the number of pairs (i,j) from the input where i < j and arr[i] + arr[j] is divisible by k.
 * Runs in O(N).
 * @param Array<int> input
 * @param int k
 * @return int Returns a count of the number of pairs.
 */
const countPairs = (input, k) => {
  const modClasses = new Array(k);  // counts how many we've seen in each modulus class
  let count = 0; // counts the number of pairs
  for (let i = 0; i < input.length; i++) {
    const modClass = input[i] % k; // modulus class
    const compClass = (k - modClass) % k; // complimentary modulus class
    if (modClasses[compClass]) {
      count += modClasses[compClass];
    }
    if (!modClasses[modClass]) {
      modClasses[modClass] = 1;
    } else {
      modClasses[modClass]++;
    }
  }
  return count;
};

console.log(countPairs([1, 3, 2, 6, 1, 2], 3));