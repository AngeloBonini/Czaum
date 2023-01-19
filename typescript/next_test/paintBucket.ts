function paintBucket(
  image: string[][],
  x: number,
  y: number,
  newColor: string
): void {
  let originalColor = image[x][y];
  if (originalColor === newColor) {
    return;
  }

  let queue = [[x, y]];
  while (queue.length > 0) {
    const [currentX, currentY] = queue.shift();
    if (
      currentX < 0 ||
      currentX >= image.length ||
      currentY < 0 ||
      currentY >= image[0].length
    ) {
      continue;
    }
    if (image[currentX][currentY] !== originalColor) {
      continue;
    }
    image[currentX][currentY] = newColor;

    queue.push([currentX - 1, currentY]);
    queue.push([currentX + 1, currentY]);
    queue.push([currentX, currentY - 1]);
    queue.push([currentX, currentY + 1]);
  }
}
