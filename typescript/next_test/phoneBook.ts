type phoneName = {
  name: string;
  number: string;
};

function phonebookSearch(phonebook: phoneName[], name: string): string {
  let left = 0;
  let right = phonebook.length - 1;
  while (left <= right) {
    let middle = Math.floor((left + right) / 2);
    if (phonebook[middle].name === name) {
      return phonebook[middle].number;
    } else if (phonebook[middle].name < name) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return "Phone number not found, try again.";
}

const phonebook = [
  { name: "Angelo", number: "55-9910-1234" },
  { name: "Bruno", number: "55-9802-5678" },
  { name: "Christina", number: "55-9071-9101" },
  // ...
];

console.log(phonebookSearch(phonebook, "Angelo")); // Output: "55-9910-1234"
console.log(phonebookSearch(phonebook, "Christina")); // Output: "55-9071-9101"
console.log(phonebookSearch(phonebook, "Jose")); // Output: "Phone number not found, try again."
