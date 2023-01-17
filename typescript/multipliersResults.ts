const multipliersResults = (multipler: number, multiplied: number) => {
  const multiplierArr = Array.from(multipler.toString());
  const unitMultiplication = parseInt(multiplierArr[2]) * multiplied;
  const dozenMultiplication = parseInt(multiplierArr[1]) * multiplied * 10;
  const centMultiplication = parseInt(multiplierArr[0]) * multiplied * 100;
  const result = unitMultiplication + dozenMultiplication + centMultiplication;
  console.log("    " + multipler);
  console.log("x   " + multiplied);
  console.log(unitMultiplication);
  console.log(dozenMultiplication);
  console.log(centMultiplication);
  console.log("--------------------------");
  console.log(result);
};

multipliersResults(426, 325);
