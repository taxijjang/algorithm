var readline = require('readline'); 

var r = readline.createInterface({ 
  input:process.stdin, 
  output:process.stdout 
}); 

r.question("", function(answer) {
  // *
  // **
  // ***
  // ****
  // *****
  // ******
  // *******
  // for (i = 0 ;i < answer; i++){
  //   for (j = 0 ; j <= i ; j ++){
  //     process.stdout.write('*');
  //   }
  //   console.log();
  // }

  // ******
  // *****
  // ****
  // ***
  // **
  // *
  // for (i = 0 ;i <answer; i++){
  //   for(j=i;j<answer;j++){
  //     process.stdout.write('*');
  //   }
  //   console.log();
  // }

  //     *
  //    ***
  //   *****
  //  *******
  // *********
  for(i=1;i<=answer; i++){
    for(j=1; j<=answer-i; j++){
      process.stdout.write(' ');
    }
    for(k=1; k<=i*2 -1; k++){
      process.stdout.write('*');
    }
    console.log();
  }
  r.close()
});