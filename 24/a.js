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
  const n = parseInt(readline());
  const roads = new Map();
  let neighbours = (new Array(n+1)).fill(new Array());
  let start = 0,
      curr = 0,
      next = 0,
      d1 = 0,
      d2 = 0;
  for (let i=0; i<n; i++) {
    const [a, b, c] = readline().split(" ").map(x => parseInt(x));
    roads.set(a+"-"+b, c);
    neighbours[a] = neighbours[a].concat(b);
    neighbours[b] = neighbours[b].concat(a);
    if (start == 0) {
      start = a;
      curr = a;
      next = b;
    }
  }

  do {
    if (roads.has(curr+"-"+next)) {
      d1 += roads.get(curr+"-"+next);
    } else {
      d2 += roads.get(next+"-"+curr);
    }
    if (neighbours[next][0] == curr) {
      curr = next;
      next = neighbours[next][1];
    } else {
      curr = next;
      next = neighbours[next][0];
    }
  } while(curr != start);

  console.log(Math.min(d1,d2));
}
