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
  const [r,g,b] = readline().split(" ").map(x => parseInt(x));
  const ar = readline().split(" ").map(x => parseInt(x));
  const ag = readline().split(" ").map(x => parseInt(x));
  const ab = readline().split(" ").map(x => parseInt(x));
  ar.sort((a,b)=>b-a);
  ag.sort((a,b)=>b-a);
  ab.sort((a,b)=>b-a);

  let ans = 0;
  let dp = Array(r+1).fill().map(
    _ => Array(g+1).fill().map(
      _ => Array(b+1).fill(0)));
  
  for (let i=0; i<=r; i++) {
    for (let j=0; j<=g; j++) {
      for (let k=0; k<=b; k++) {
        if (i<r && j<g) {
          dp[i+1][j+1][k] = Math.max(dp[i+1][j+1][k], dp[i][j][k] + ar[i]*ag[j]);
        }
        if (i<r && k<b) {
          dp[i+1][j][k+1] = Math.max(dp[i+1][j][k+1], dp[i][j][k] + ar[i]*ab[k]);
        }
        if (j<g && k<b) {
          dp[i][j+1][k+1] = Math.max(dp[i][j+1][k+1], dp[i][j][k] + ag[j]*ab[k]);
        }
        ans = Math.max(ans, dp[i][j][k]);
      }
    }
  }
  console.log(ans);
}
