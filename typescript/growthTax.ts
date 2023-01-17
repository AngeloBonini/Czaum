const growthTax = () => {
  let fulanoHeight = 150;
  const fulanoGrowthPerYear = 2;
  let ciclanoHeight = 110;
  const ciclanoGrowthPerYear = 3;
  let yearsNeeded = 0;

  while (ciclanoHeight <= fulanoHeight) {
    fulanoHeight += fulanoGrowthPerYear;
    ciclanoHeight += ciclanoGrowthPerYear;
    yearsNeeded++;
    console.log("current fulano height: " + fulanoHeight);
    console.log("current ciclano height: " + ciclanoHeight);
  }

  console.log(yearsNeeded);
};

growthTax();
