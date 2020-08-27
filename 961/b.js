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
  const [n, k] = readline().split(" ").map(x => parseInt(x));
  const a = readline().split(" ").map(x => parseInt(x));
  const t = readline().split(" ").map(x => parseInt(x));
  let awake = t.reduce((acc,curr,index) => acc += a[index]*curr, 0);
  let extra = 0;
  for (let i=0; i<k; i++) {
    extra += (1-t[i]) * a[i];
  }

  let max = extra;
  for (let i=k; i<n; i++) {
    extra += (1-t[i]) * a[i] - (1-t[i-k]) * a[i-k];
    max = Math.max(max, extra);
  }

  console.log(awake+max);
}
