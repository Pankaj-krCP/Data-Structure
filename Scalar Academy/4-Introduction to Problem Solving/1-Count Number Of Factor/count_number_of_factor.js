"use strict";
process.stdin.resume();
process.stdin.setEncoding("utf-8");
let inputString = "";
let currentLine = 0;
process.stdin.on("data", (inputStdin) => {
  inputString += inputStdin;
});
process.stdin.on("end", (_) => {
  inputString = inputString
    .trim()
    .split("\n")
    .map((string) => {
      return string.trim();
    });
  main();
});

function readLine() {
  return inputString[currentLine++];
}

//Above code is taking input

function main() {
  let num = parseInt(readLine());
  let factor = 0;
  for (let i = 0; i * i <= num; i++) {
    if (num % i == 0) {
      if (num / i != i) factor += 2;
      else factor += 1;
    }
  }
  console.log(factor);
}
