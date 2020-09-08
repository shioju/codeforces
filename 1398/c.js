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
    const a = readline().split("").map(x => parseInt(x));

    let good = 0;
    let sum = 0;
    let m = new Map();
    m.set(0,1);
    for (let j=0; j<n; j++) {
      sum += a[j];
      let x = sum - j - 1;
      m.set(x, (m.get(x)|0) + 1);
    }

    for (let [k,v] of m) {
      good += v * (v-1) / 2;
    }
    console.log(good);
  }
}
