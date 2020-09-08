'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputArray = [];
let currentLine = 0;

process.stdin.on('data', inputStdin => {
  inputString += inputStdin;
});

process.stdin.on('end', _ => {
  inputArray = inputString.trim().split('\n').map(string => {
    return string.trim();
  });

  main();
});

function readline() {
  return inputArray[currentLine++];
}

function main() {
  const t = parseInt(readline());
  for (let i=0; i<t; i++) {
    const n = parseInt(readline());
    const nums = readline().split(" ").map((x: string) => parseInt(x));
    if (nums[0]+nums[1]<=nums[n-1]) {
      console.log(1,2,n);
    } else {
      console.log(-1);
    }
  }
}
