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
    const s = readline();
    let lengths = [];
    let count = 0;
    for (let c of s) {
      if (c == "1") {
        count++;
      } else if (count > 0) {
        lengths.push(count);
        count = 0;
      }
    }
    if (count > 0) lengths.push(count);
    lengths.sort((a,b) => a-b);

    let answer = 0;
    for (let j=lengths.length-1; j>=0; j-=2) {
      answer += lengths[j];
    }
    console.log(answer);
  }
}
