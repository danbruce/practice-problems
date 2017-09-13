/**
 * Returns an array of all binary strings that matches the given pattern.
 *
 * For example if the pattern is "?1?0", then we must return:
 * [ "0100", "0110", "1100" "1110" ].
 *
 * For this particular implementation, we return the strings in "ascending"
 * order where each string represents an unsigned integer in binary format.
 *
 * @param string binaryString The input string of 1's, 0's, and ?'s.
 * @return array Returns an array of valid strings that matches the pattern.
 */
const binaryStringsViaPattern = (binaryString) => {
  // holds our returned array
  const patterns = [];
  // get each substring part between the ?'s
  const parts = binaryString.split('?');
  // the size of the returned array will be 2^N where N is the # of ?'s in the input
  const max = 1 << (parts.length - 1);
  // we iterate over every integer from 0 to 2^(N-1)
  for (let i = 0; i < max; i++) {
    // and build a string that matches the pattern by combining the subparts
    // between the ?'s
    let newString = parts[0];
    for (j = 1; j < parts.length; j++) {
      // with the 0 or 1 at the bit location "j" for the integer "i"
      // by iterating over the bits of the integer in reverse (parts.length - j - 1)
      // we ensure our final output is in ascending order
      newString += (((i >> (parts.length - j - 1)) & 1) + parts[j]);
    }
    patterns.push(newString);
  }
  return patterns;
};
