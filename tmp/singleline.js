deployedContract.deploy({ date:bytecode, arguments: [listOfCandidates.map(name => web3.utils.asciiToHex(name))]      }).send({from:'0x3E2Bb0a934F5372d353c7Bf9fBb04512cF491Ac9', gas:1500000,gasPrice: web3.utils.toWei('0.00003', 'ether')}).then((newContractInstance) =>{ deployedContract.options.address =  newContractInstance.options.address;  console.log(newContractInstance.options.address);});