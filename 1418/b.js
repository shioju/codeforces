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
    const n = parseInt(readline());
    const a = readline().split(" ").map(x => parseInt(x));
    const locked = readline().split(" ").map(x => parseInt(x));

    const arr = a.filter((_, index) => locked[index]==0);
    arr.sort((a,b)=>b-a);

    let pos=0;
    const result = a.map((v, index)=> {
      if (locked[index]==1) return v;
      return arr[pos++];
    });

    console.log(result.join(" "));
  }
}
