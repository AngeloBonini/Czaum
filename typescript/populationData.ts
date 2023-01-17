const populationData = (population: Person[]) => {
  let elderAge = 0;

  for (let i = 0; i <= population.length - 1; i++) {
    for (let j = 1; j <= population.length - 1; j++) {
      if (population[j].age > population[i].age) {
        elderAge = population[j].age;
      }
    }
  }

  console.log("Elder Citizen age: " + elderAge);
  return population;
};

interface Person {
  gender: "male" | "female";
  eyeColor: "blue" | "green" | "brown";
  age: number;
  hairColor: "blonde" | "brown" | "black";
}

const peopleInNumbers: Person[] = [
  {
    gender: "male",
    eyeColor: "brown",
    age: 53,
    hairColor: "blonde",
  },
  {
    gender: "male",
    eyeColor: "green",
    age: 30,
    hairColor: "black",
  },
  {
    gender: "male",
    eyeColor: "green",
    age: 30,
    hairColor: "black",
  },
  {
    gender: "male",
    eyeColor: "green",
    age: 30,
    hairColor: "black",
  },
  {
    gender: "male",
    eyeColor: "green",
    age: 100,
    hairColor: "black",
  },
  {
    gender: "male",
    eyeColor: "green",
    age: 30,
    hairColor: "black",
  },
  {
    gender: "male",
    eyeColor: "green",
    age: 30,
    hairColor: "black",
  },
  {
    gender: "male",
    eyeColor: "green",
    age: 30,
    hairColor: "black",
  },
  {
    gender: "male",
    eyeColor: "green",
    age: 30,
    hairColor: "black",
  },
  {
    gender: "male",
    eyeColor: "green",
    age: 30,
    hairColor: "black",
  },
  {
    gender: "male",
    eyeColor: "green",
    age: 30,
    hairColor: "black",
  },
  {
    gender: "female",
    eyeColor: "blue",
    age: 30,
    hairColor: "black",
  },
];

populationData(peopleInNumbers);
