const nextEvenToSquareRoot = (inputNumber: number): number => {
  const squareRoot = Math.sqrt(inputNumber);

  squareRoot % 2 === 0 ? console.log(squareRoot) : console.log(squareRoot + 1);
  return squareRoot % 2 === 0 ? squareRoot : squareRoot + 1;
};

nextEvenToSquareRoot(25);
nextEvenToSquareRoot(100);
