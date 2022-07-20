"use strict";
exports.__esModule = true;
exports.printarrayElements = void 0;
function printarrayElements(inputTwoDimensionalArray, row, col) {
    for (var _i = 0, row_1 = row; _i < row_1.length; _i++) {
        var i = row_1[_i];
        for (var _a = 0, col_1 = col; _a < col_1.length; _a++) {
            var j = col_1[_a];
            if (i === j || i < j) {
                console.log("item da diagonal inferior: " + inputTwoDimensionalArray[i][j]);
            }
        }
    }
}
exports.printarrayElements = printarrayElements;
var matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
];
var rows = 3;
var cols = 3;
printarrayElements(matrix, rows, cols);
