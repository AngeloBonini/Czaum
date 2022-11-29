const sevenOnDie = () => {
  const possibleNumbersOnFirstDice = [1, 2, 3, 4, 5, 6];
  const possibleNumbersOnSecondDice = [1, 2, 3, 4, 5, 6];
  let sumPossibilities = 0;
  for (let i = 0; i <= possibleNumbersOnFirstDice.length; i++) {
    for (let x = 0; x <= possibleNumbersOnSecondDice.length; x++) {
      if (i + x == 7) {
        sumPossibilities++;
      }
    }
  }
  console.log(sumPossibilities);
  sumPossibilities = sumPossibilities / 36;
  console.log(sumPossibilities);
};

sevenOnDie();
