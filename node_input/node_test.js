let fs = require('fs');

let input = fs.readFileSync('stdin.txt').toString().split('\n');

input.forEach(function(element){
        let a = Number(element.split(' ')[0])
        let b = Number(element.split(' ')[1])
        if (a==0 && b==0){
            return 0
        }
        if (a > b){
            console.log("Yes");
        } else {
            console.log("No");
        }
    }
)
// console.log(input)
// let T = Number(input[0]) // 무슨 type?? (int)

// for (let i=1; i<=T; i++){
//     // input[i] -> '1 1'

//     let data = input[i].split(' ')
//     // console.log(data) 
//     // [ '1', '1' ]
//     // [ '2', '3' ]
//     // [ '3', '4' ]
//     // [ '9', '8' ]
//     // [ '5', '2' ]
    
//     let A = Number(data[0])
//     let B = Number(data[1])
    
//     console.log(A+B)
// }
