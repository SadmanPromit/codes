const fs = require('fs');
const JavaScriptObfuscator = require('javascript-obfuscator');
const originalHtml = fs.readFileSync('index.html', 'utf8');

const obfuscationResult = JavaScriptObfuscator.obfuscate(originalHtml, {
    compact: true,
    controlFlowFlattening: true,
    controlFlowFlatteningThreshold: 1,
    numbersToExpressions: true,
    simplify: true,
    stringArrayShuffle: true,
    splitStrings: true,
    stringArrayThreshold: 1
});

fs.writeFileSync('index.html', obfuscationResult.getObfuscatedCode(), 'utf8');
console.log('Obfuscation complete! Check the "index.html" file.');