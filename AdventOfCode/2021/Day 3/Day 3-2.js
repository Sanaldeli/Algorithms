const fs = require('fs');

const binaries = fs.readFileSync('Input.txt', 'utf8').split('\r\n');

let startsWithO2 = '';
let startsWithCO2 = '';

let binariesO2 = binaries;
let binariesCO2 = binaries;

for (let i = 0; binariesO2.length > 1; i++) {
    let counter = 0;
    for (const bin of binariesO2)
        counter += bin.split('')[i] === '1';
        
    startsWithO2 += counter * 2 >= binariesO2.length ? '1' : '0';
    
    if (binariesO2.length > 1)
        binariesO2 = binariesO2.filter(el => el.startsWith(startsWithO2))       
}

for (let i = 0; binariesCO2.length > 1; i++) {
    let counter = 0;
    for (const bin of binariesCO2)
        counter += bin.split('')[i] === '1';
        
    startsWithCO2 += counter * 2 >= binariesCO2.length ? '0' : '1';
    
    if (binariesCO2.length > 1)
        binariesCO2 = binariesCO2.filter(el => el.startsWith(startsWithCO2))    
}

const o2 = parseInt(binariesO2[0].split('\r')[0], 2)
const co2 = parseInt(binariesCO2[0].split('\r')[0], 2)

console.log(`O2: ${o2} * CO2: ${co2} = ${o2 * co2}`)
// Result: 7928162
    