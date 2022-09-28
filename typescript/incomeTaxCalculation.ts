interface employeeData {
  baseSalary: number;
  employeeSalary: number;
  dependents: number;
}

const incomeTaxCalculation = (employee: employeeData): number => {
  const dependentDiscountMultiplier = 0.05;
  const dependentDiscount =
    dependentDiscountMultiplier * employee.dependents * employee.baseSalary;
  employee.baseSalary = employee.baseSalary - dependentDiscount;

  const incomeTaxMultiplier = dependentDiscountMultiplier;
  const salaryOverBaseSalary = employee.employeeSalary / employee.baseSalary;
  let incomeTax = 0;

  const multipliersRate = [1, 2, 3, 4, 5, 6, 7];
  if (salaryOverBaseSalary === 1) {
    console.log("isento");
    console.log(incomeTax);
    console.log(employee);
  } else if (salaryOverBaseSalary === 2 && salaryOverBaseSalary < 3) {
    console.log("5% de imposto");
    incomeTax = employee.employeeSalary * incomeTaxMultiplier;
    console.log(incomeTax);
    console.log(employee);
  } else if (salaryOverBaseSalary === 3 || salaryOverBaseSalary < 5) {
    console.log("10% de imposto");
    incomeTax = employee.employeeSalary * incomeTaxMultiplier * 2;
    console.log(incomeTax);
    console.log(employee);
  } else if (salaryOverBaseSalary === 5 || salaryOverBaseSalary < 7) {
    console.log("15% de imposto");
    incomeTax = employee.employeeSalary * incomeTaxMultiplier * 3;
    console.log(incomeTax);
    console.log(employee);
  } else if (salaryOverBaseSalary === 7 || salaryOverBaseSalary > 7) {
    console.log("20% de imposto");
    incomeTax = employee.employeeSalary * incomeTaxMultiplier * 4;
    console.log(incomeTax);
    console.log(employee);
  }

  return incomeTax;
};

const employeeExample: employeeData = {
  baseSalary: 1000,
  employeeSalary: 3000,
  dependents: 1,
};

incomeTaxCalculation(employeeExample);
