const monkQueen = () => {
  let numberOfWheats = 1;
  let wheatsPerSquare = 1;
  const chessBoard = 64;

  for (let i = 1; i <= chessBoard; i++) {
    wheatsPerSquare = wheatsPerSquare * 2;
    numberOfWheats += wheatsPerSquare;
  }
  console.log(numberOfWheats);
};

monkQueen();
