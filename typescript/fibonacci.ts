const fibonacci = (numberInTheSequence: number): number => {
  if (numberInTheSequence <= 1) {
    console.log(numberInTheSequence);
    return numberInTheSequence;
  }
  const fibonacciInSequence =
    fibonacci(numberInTheSequence - 1) + fibonacci(numberInTheSequence - 2);
  console.log("last number: " + fibonacciInSequence);
  return fibonacciInSequence;
};

fibonacci(9);
