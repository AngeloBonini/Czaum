function isValid(str) {
  const strArray = str.split("");
  const allLettersAreEqual = strArray.every((letter) => letter === str[0]);
  let middleLetterIsValid = false;
  if (strArray.length !== 1 && strArray.length % 2 !== 0) {
    const middleLetter = strArray[parseInt(strArray.length / 2, 10)];
    const firstHalf = strArray.slice(0, parseInt(strArray.length / 2, 10));
    const secondHalf = strArray.slice(
      parseInt(strArray.length / 2, 10) + 1,
      strArray.length
    );

    JSON.stringify(firstHalf) == JSON.stringify(secondHalf) &&
    JSON.stringify(firstHalf) !== middleLetter
      ? (middleLetterIsValid = true)
      : (middleLetterIsValid = false);
  }

  if (middleLetterIsValid) {
    console.log(middleLetterIsValid);
    return str;
  }
  if (allLettersAreEqual) {
    return str;
  }
}
function substrCount(n, s) {
  const substringArr = [];
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n + 1; j++) {
      substringArr.push(s.slice(i, j));
    }
  }
  console.log(substringArr);
  const newArr = substringArr.filter(isValid);
  console.log(newArr);
  return newArr.length;
}
