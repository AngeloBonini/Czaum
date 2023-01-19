function palindromeChecker(word: string): boolean {
  const reversedWord = word.split("").reverse().join("");
  return word === reversedWord;
}

console.log(palindromeChecker("HANNAH")); // true
console.log(palindromeChecker("GAGA")); // false
