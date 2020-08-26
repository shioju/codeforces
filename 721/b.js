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
  const nums = readline().split(" ").map(x => parseInt(x));
  const n = nums[0];
  const k = nums[1];
  const passwordLengths = new Map();
  for (let i=0; i<n; i++) {
    const password = readline();
    passwordLengths.set(password.length, (passwordLengths.get(password.length) || 0) + 1);
  }
  const rightLength = readline().length;
  let base = 0;
  for (let [key,val] of [...passwordLengths].sort((a,b) => a[0]-b[0])) {
    if (key<rightLength) {
      base += val;
    } else {
      const min = base+Math.floor(base/k)*5+1;
      base += val - 1;
      const max = base+Math.floor(base/k)*5+1; 
      console.log(`${min} ${max}`);
      return;
    }
  }
}
