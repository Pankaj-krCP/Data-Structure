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
  let A = parseInt(readLine());
  let tmp = 1;
  for (let i = 2; i * i <= A; i++) {
    if (A % i == 0) tmp += i + A / i;
  }
  if (tmp == A) console.log("1");
  else console.log("0");
}
