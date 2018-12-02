# Pay_Go_Service_SmartContract
Keep information in EOS smart contract. Every can visit the information, and nobody except owner can remove it.

The smart contract can be compiled by EOS CDT 1.3.

You may need to update the folder name to income_14.


```
cd folder
mkdir build
cd build
cname ..
make
```

The abi file and wasm file are both generated in build folder. You may need to copy them to upper folder before deploy contract.

deploy smart contract
```
cleos -u https://nodes.get-scatter.com set contract  youreosaccount income_14 --permission youreosaccount@active
```
create record, with setup_time:1, service_info:"dead beef duck"
```
cleos  -u https://nodes.get-scatter.com push action youreosaccount create '{"setup_time":1, "service_info":"dead beef duck"}' --permission youreosaccount@active
```
list record
```
cleos -u  https://nodes.get-scatter.com get table youreosaccount youreosaccount srvportal
```
remove record
```
cleos  -u https://nodes.get-scatter.com push action youreosaccount remove '{"setup_time":1}' --permission youreosaccount@active
```
list again
```
cleos -u  https://nodes.get-scatter.com get table youreosaccount youreosaccount srvportal
```
