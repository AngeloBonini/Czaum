export function printarrayElements(inputTwoDimensionalArray, row, col) {
  for (const i of row) {
    for (const j of col) {
      if (i < j) {
        console.log(
          "item da diagonal inferior: " + inputTwoDimensionalArray[i][j]
        );
      }
    }
  }
}

const matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9],
];
const rows = 3;
const cols = 3;

printarrayElements(matrix, rows, cols);
