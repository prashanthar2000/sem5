Web3 = require('web3');
fs = require('fs');

web3 = new Web3("http://localhost:8545")
web3.eth.getAccounts(console.log)
bytecode = fs.readFileSync('voting_sol_Voting.bin').toString()
abi = JSON.parse(fs.readFileSync('voting_sol_Voting.abi').toString())

deployedContract = new web3.eth.Contract(abi)
listOfCandidates = ['Rama', 'sham', 'Rani']

deployedContract.deploy({
    date:bytecode, 
    arguments: [listOfCandidates.map(name => 
        web3.utils.asciiToHex(name))]      
}).send({
    from:'0x3E2Bb0a934F5372d353c7Bf9fBb04512cF491Ac9', 
    gas:1500000,
    gasPrice: web3.utils.toWei('0.00003', 'ether')
}).then((newContractInstance) =>{
    deployedContract.options.address =  newContractInstance.options.address
    console.log(newContractInstance.options.address)
});

