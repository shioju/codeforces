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
  const nums = readline().split(" ").map(x => BigInt(x));
  for (var i=0; i<t; i++) {
    const top = nums[i] % 14n;
    if (nums[i]>14 && top>0 && top<7) {
      console.log("YES");
    } else {
      console.log("NO");
    }
  }
}
