const pangram = word => (
  word.toLowerCase().split('').reduce((bits, char) => {
    const charCode = char.charCodeAt(0) - 97;
    // ensure a-z
    if (charCode < 0 || charCode > 25) return bits;
    const mask = 1 << charCode;
    return bits & ~mask;
  }, Math.pow(2, 26) - 1) === 0
);
