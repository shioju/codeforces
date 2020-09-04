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
  const T = parseInt(readline());
  for (let t=0; t<T; t++) {
    const n = parseInt(readline());
    const nums = readline().split(" ").map(x => parseInt(x));

    let result = 0;
    // left[x] is the number of smaller than index j with value x
    let left = new Array(n+1).fill(0);
    // right[x] is the number of greater than index k with value x
    let right = new Array(n+1).fill(0);

    // iterate over each j and k
    for (let j=0; j<n; j++) {
      right.fill(0);
      for (let k=n-1; j<k; k--) {
        result += left[nums[k]] * right[nums[j]];
        right[nums[k]]++;
      }
      left[nums[j]]++;
    }
    console.log(result);
  }
}
