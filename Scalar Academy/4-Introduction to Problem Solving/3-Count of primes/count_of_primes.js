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

function main() {
  let n = parseInt(readLine());
  let total_primes = 0;
  if (n >= 2) total_primes += 1;
  for (let i = 3; i <= n; i++) {
    let flag = 0;
    for (let j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        flag = 1;
        break;
      }
    }
    if (!flag) total_primes += 1;
  }
  console.log(total_primes);
}
