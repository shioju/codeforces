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
    const s = readline();
    const x = parseInt(readline());

    let w = new Array(s.length).fill("1");
    for (let j=0; j<s.length; j++) {
      if (s[j] == "0") {
        if (j+x<s.length) w[j+x]="0";
        if (j-x >= 0) w[j-x]="0";
      }
    }
    let ok = true;
    for (let j=0; j<s.length; j++) {
      if (s[j] == "1") {
        if (!(j+x<s.length && w[j+x] == "1") &&
          !(j-x >=0 && w[j-x] == "1")) {
          ok = false;
        }
      }
    }
    console.log(ok ? w.join('') : "-1");
  }
}
