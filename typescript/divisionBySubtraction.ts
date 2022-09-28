const divisionBySubtraction = (dividend: number, divider: number) => {
  const resultDivision = {
    rest: 0,
    quotient: 0,
  };

  while (dividend >= divider) {
    dividend = dividend - divider;
    resultDivision.quotient++;
  }

  if (dividend < divider) {
    resultDivision.rest = dividend;
  }

  console.log(resultDivision);
  return resultDivision;
};

divisionBySubtraction(10, 3);
divisionBySubtraction(5, 2);
divisionBySubtraction(5, 3);
divisionBySubtraction(50, 3);
divisionBySubtraction(1000, 3);
