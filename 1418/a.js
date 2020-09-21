'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
  inputString += inputStdin;
});

process.stdin.on('end', _ => {
  inputString = inputString.trim().split('\n').map(string => {
    return string.trim();
  });

  main();
});

function readline() {
  return inputString[currentLine++];
}

function main() {
  const t = parseInt(readline());
  for (var i=0; i<t; i++) {
    const [x, y, k] = readline().split(" ").map(x => BigInt(parseInt(x)));
    const result = (k*y + k - 1n + x - 2n) / (x-1n) + k;
    console.log(result.toString());
  }
}
